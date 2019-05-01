CC = g++ -std=c++11

#The Target Binary Program
TARGET      := mygame

#The Directories, Source, Includes, Objects, Binary and Resources
BUILDDIR    := obj
TARGETDIR   := bin
RESDIR      := res
EXTRADIRS   := html latex
SRCEXT      := cpp
HEADEREXT   := h
DEPEXT      := d
OBJEXT      := o

STATUSFILE  := status.log

#Flags, Libraries and Includes
CFLAGS      := -lncurses -Wall -g
LIB         := -lncurses

#------------------------------------------------------------
#Do not touch anything below this line
#------------------------------------------------------------

SOURCES     := $(shell find . -type f -name "*.$(SRCEXT)")
HEADERS     := $(shell find . -type f -name "*.$(HEADEREXT)")
vpath %$(SRCEXT) = $(dir $(SOURCES))
OBJECTS     := $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES:.$(SRCEXT)=.$(OBJEXT))))

#Defauilt Make
all: resources $(TARGET)

status:
	$(shell echo "number of code lines:" > $(STATUSFILE))
	$(shell echo -n "   .$(SRCEXT) files: " >> $(STATUSFILE))
	$(shell cat $(SOURCES) | wc -l >> $(STATUSFILE))
	$(shell echo -n "   .$(HEADEREXT) files: " >> $(STATUSFILE))
	$(shell cat $(HEADERS) | wc -l >> $(STATUSFILE))
	$(shell echo -n "   total: " >> $(STATUSFILE))
	$(shell cat $(SOURCES) $(HEADERS) | wc -l >> $(STATUSFILE))

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
	$(shell rm -rf $(EXTRADIRS))

#Full Clean, Objects and Binaries
cleaner: clean
	$(shell rm -rf $(TARGETDIR))

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))
-include $(subst .c,.d,$(SOURCES))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT)
	$(CC) -c $(CFLAGS) -o $@ $<
