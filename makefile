PROJECT := example

SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)

EXE_x64 := bin/$(PROJECT).x64.exe
EXE_x86 := bin/$(PROJECT).x86.exe

CCX64	:= x86_64-w64-mingw32-gcc
CCX86	:= i686-w64-mingw32-gcc

CFLAGS  := -masm=intel -s -w -Wall -I .

all: x64 x86

x64:
	@ $(CCX64) $(CFLAGS) -o $(EXE_x64) $(SOURCES)

x86:
	@ $(CCX86) $(CFLAGS) -o $(EXE_x86) $(SOURCES)
