CC = i686-w64-mingw32-gcc
PYTHON = python2

CCFLAGS = -nostdlib -nodefaultlibs -std=c99 -Wl,-e_start -s -mwindows -m32 -municode -Os -w -march=i486
LIBS    = -luser32 -lkernel32 -lgdi32 -lwinmm -lcomctl32 -ladvapi32 -lshell32 -lpsapi

# Don't change the build directory, it is hardcoded on other places
BUILDDIR = Build

CFILES = $(shell find Source -name '*.c' -type f)
HFILES = $(shell find Source -name '*.h' -type f)

DATA = $(wildcard Data/*)


all: dir $(BUILDDIR)/FMEMZ.exe $(BUILDDIR)/FMEMZ.bat

dir: $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	
$(BUILDDIR)/Data.c $(BUILDDIR)/Data.h: ../NyanMBR/disk.img $(DATA)
	$(PYTHON) Data/genData.py $(BUILDDIR)/Data.c $(BUILDDIR)/Data.h
	
$(BUILDDIR)/FMEMZ.exe: $(CFILES) $(HFILES) $(BUILDDIR)/Data.c $(BUILDDIR)/Data.h
	echo "#define DESTRUCTIVE" > $(BUILDDIR)/Mode.h
	$(CC) $(CCFLAGS) $(CFILES) $(BUILDDIR)/Data.c $(LIBS) -o $@
	
$(BUILDDIR)/FMEMZ.bat: $(BUILDDIR)/FMEMZ.exe Source/exe2bat.py
	$(PYTHON) Source/exe2bat.py $(BUILDDIR)/FMEMZ.exe $@ FMEMZ.exe -zip
	
clean:
	rm -r $(BUILDDIR)

exe: dir $(BUILDDIR)/FMEMZ.exe
bat: dir $(BUILDDIR)/FMEMZ.bat

.PHONY: clean all dir exe bat