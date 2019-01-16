CXX = g++

#The Target Binary Program
TARGET      := mygame

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./
#INCDIR      := #Libraries/Common
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

#------------------------------------------------------------
#Do not touch anything below this line
#------------------------------------------------------------

SOURCES     := $(shell find . -type f -name "*.$(SRCEXT)")
OBJECTS     := $(SOURCES:.$(SRCEXT)=.$(OBJEXT))
OBJECTS     := $(addprefix $(BUILDDIR)/, $(notdir $(OBJECTS)))

vpath %$(SRCEXT) = $(dir $(SOURCES))

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
	$(CXX) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT)
	$(CXX) -c $(CFLAGS) -o $@ $^
