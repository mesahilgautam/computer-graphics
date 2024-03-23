SRCDIR=src/
INCDIR=inc/
BUILDDIR=build/
OBJDIR=obj/

BINARY=$(BUILDDIR)exe
IMAGE_FILE=$(BUILDDIR)image.ppm

GXX=g++
GFLAGS=-std=c++20 -g -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion \
	   -Wshadow -pedantic-errors  -I $(foreach D, $(INCDIR), $(D))

CPPFILES=$(foreach D, $(SRCDIR), $(wildcard $(D)*.cpp))
HPPFILES=$(foreach D, $(INCDIR), $(wildcard $(D)*.hpp))
OBJFILES=$(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(CPPFILES))

all : $(BINARY)

$(BINARY) : $(OBJFILES) | $(BUILDDIR)
	$(GXX) -o $@ $<

$(OBJFILES) : $(CPPFILES) $(HPPFILES) | $(OBJDIR)
	$(GXX) $(GFLAGS) -c -o $@ $<

$(OBJDIR) $(BUILDDIR) :
	mkdir -p $@

run : all
	./$(BINARY) > $(IMAGE_FILE)


clean : 
	rm -rf $(BUILDDIR) $(OBJDIR)

# Write tests
test :

