CC		= g++
CFLAGS	= -W -Wall
CDEPS	= -lGL -lGLU -lglut

EXEC	= koeboes.exe

all: remdir makedir $(EXEC)

remdir:
	@echo "Cleaning Build Folder"
	@rm -rf build/

makedir:
	@echo "Making Build Folder"
	@mkdir -p build/bin/
	@mkdir -p build/o/

control.o: src/control.cc src/control.hh
	$(CC) $(CFLAGS) -c src/control.cc -o build/o/control.o

render.o: src/render.cc src/render.hh
	$(CC) $(CFLAGS) -c src/render.cc -o build/o/render.o

structure.o: src/structure.cc src/structure.hh
	$(CC) $(CFLAGS) -c src/structure.cc -o build/o/structure.o

main.o: src/main.cc
	$(CC) $(CFLAGS) -c src/main.cc -o build/o/main.o

$(EXEC): control.o render.o structure.o main.o
	$(CC) $(CFLAGS) build/o/control.o build/o/render.o build/o/structure.o  build/o/main.o $(CDEPS) -o build/bin/$(EXEC)
