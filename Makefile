CC = g++

#The Target Binary Program
TARGET      := mygame

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := Libraries
INCDIR      := #Libraries/Common
BUILDDIR    := obj
TARGETDIR   := bin
RESDIR      := res
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -lncurses -Wall -g
LIB         := -lncurses
INC         := -I$(INCDIR) -I/usr/local/include
INCDEP      := -I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------

SOURCES     := $(shell find . -type f -name "*.$(SRCEXT)")
OBJECTS     := $(patsubst %.cpp, %.o, $(SOURCES))

#Defauilt Make
all: resources $(TARGET)

#Remake
remake: cleaner all

#Copy Resources from Resources Directory to Target Directory
resources: directories
	$(shell cp $(RESDIR)/* $(TARGETDIR)/)

#Make the Directories
directories:
	$(shell mkdir -p $(TARGETDIR))
	$(shell mkdir -p $(BUILDDIR))

#Clean only Objecst
clean:
	$(shell rm -rf $(BUILDDIR))
	$(shell find -type f -name "*.o" -delete)

#Full Clean, Objects and Binaries
cleaner: clean
	$(shell rm -rf $(TARGETDIR))

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

#Compile
#$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
#	$(shell mkdir -p $(dir $@))
#	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
#	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT))
#	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp)
#	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT))
#	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT))
#	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp)
