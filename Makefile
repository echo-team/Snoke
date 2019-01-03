CC = g++
CFLAGS = -lncurses -g
SOURCES = $(wildcard *.cpp) \
	  $(wildcard Libraries/*.cpp) \

OBJECTS = $(SOURCES:.cpp=.o)
mygame:$(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o mygame

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

#.PHONY: clean
clean:
	cd Libraries && $(MAKE) $@
	rm -rf *.o
