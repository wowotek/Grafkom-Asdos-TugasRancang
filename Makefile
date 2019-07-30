CC		= g++
CFLAGS	= -W -Wall -Ilib
CDEPS	= -lGL -lGLU -lglut

EXEC	= koeboes.app

all: build run

build: remdir makedir $(EXEC) cpdatadir

remdir:
	@echo "Cleaning Build Folder"
	@rm -rf build/

makedir:
	@echo "Making Build Folder"
	@mkdir -p build/bin/
	@mkdir -p build/o/

cpdatadir:
	@echo "Copying Data Dir"
	@cp -r data/ build/bin/data/

run:
	@cd ./build/bin/ && ./$(EXEC)

# Project Compile
control.o: src/control.cc src/control.hh
	@echo "Compiling control.cc <- control.hh"
	@$(CC) $(CFLAGS) -c src/control.cc -o build/o/control.o

texture.o: src/texture.cc src/texture.hh
	@echo "Compiling texture.cc <- texture.hh"
	@$(CC) $(CFLAGS) -c src/texture.cc -o build/o/texture.o

render.o: src/render.cc src/render.hh
	@echo "Compiling render.cc <- render.hh"
	@$(CC) $(CFLAGS) -c src/render.cc -o build/o/render.o

camera.o: src/camera.cc src/camera.hh
	@echo "Compiling camera.cc <- camera.hh"
	@$(CC) $(CFLAGS) -c src/camera.cc -o build/o/camera.o

structure.o: src/structure.cc src/structure.hh
	@echo "Compiling structure.cc <- structure.hh"
	@$(CC) $(CFLAGS) -c src/structure.cc -o build/o/structure.o

main.o: src/main.cc
	@echo "Compiling main.cc"
	@$(CC) $(CFLAGS) -c src/main.cc -o build/o/main.o

$(EXEC): control.o texture.o render.o camera.o structure.o main.o
	@echo "Linking compiled binary files... (control.o, texture.o, render.o, camera.o, structure.o, main.o)"
	@$(CC) $(CFLAGS) build/o/control.o build/o/texture.o build/o/render.o build/o/camera.o build/o/structure.o build/o/main.o $(CDEPS) -o build/bin/$(EXEC)
