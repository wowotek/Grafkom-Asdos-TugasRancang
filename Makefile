CC		= g++
CFLAGS	= -W -Wall
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

control.o: src/control.cc src/control.hh
	@echo "Compiling control.cc <- control.hh"
	@$(CC) $(CFLAGS) -c src/control.cc -o build/o/control.o

texture.o: src/texture.cc src/texture.hh
	@echo "Compiling Project : texture.cc <- texture.hh"
	@$(CC) $(CFLAGS) -c src/texture.cc -o build/o/texture.o

render.o: src/render.cc src/render.hh
	@echo "Compiling Project : render.cc <- render.hh"
	@$(CC) $(CFLAGS) -c src/render.cc -o build/o/render.o

camera.o: src/camera.cc src/camera.hh
	@echo "Compiling Project : camera.cc <- camera.hh"
	@$(CC) $(CFLAGS) -c src/camera.cc -o build/o/camera.o

solid.o: src/solid.cc src/solid.hh
	@echo "Compiling Project : solid.cc <- solid.hh"
	@$(CC) $(CFLAGS) -c src/solid.cc -o build/o/solid.o

structure.o: src/structure.cc src/structure.hh
	@echo "Compiling Project : structure.cc <- structure.hh"
	@$(CC) $(CFLAGS) -c src/structure.cc -o build/o/structure.o

furniture.o: src/furniture.cc src/furniture.hh
	@echo "Compiling Project : furniture.cc <- furniture.hh"
	@$(CC) $(CFLAGS) -c src/furniture.cc -o build/o/furniture.o

main.o: src/main.cc
	@echo "Compiling Project : main.cc"
	@$(CC) $(CFLAGS) -c src/main.cc -o build/o/main.o

$(EXEC): control.o texture.o render.o camera.o solid.o structure.o furniture.o main.o
	@echo "Linking compiled binary files... (control.o, texture.o, render.o, camera.o, structure.o, furniture.o, main.o)"
	@$(CC) $(CFLAGS) build/o/control.o build/o/texture.o build/o/render.o build/o/camera.o build/o/solid.o build/o/structure.o build/o/furniture.o build/o/main.o $(CDEPS) -o build/bin/$(EXEC)
