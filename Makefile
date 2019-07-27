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

#cpdatatobuild:
#	@echo "Copying Data Files to Build Folder"
#	@cp -r Data/ build/Data/

control.o: src/control.cc src/control.hh
	$(CC) $(CFLAGS) -c src/control.cc -o build/o/control.o

render.o: src/render.cc src/render.hh
	$(CC) $(CFLAGS) -c src/render.cc -o build/o/render.o

structure.o: src/structure.cc src/structure.hh
	$(CC) $(CFLAGS) -c src/structure.cc -o build/o/structure.o

keyboard.o: src/keyboard_impl_glut.cc src/keyboard.hh
	$(CC) $(CFLAGS) -c src/keyboard_impl_glut.cc -o build/o/keyboard.o

main.o: src/main.cc
	$(CC) $(CFLAGS) -c src/main.cc -o build/o/main.o

$(EXEC): control.o render.o structure.o keyboard.o main.o
	$(CC) $(CFLAGS) build/o/control.o build/o/render.o build/o/structure.o  build/o/keyboard.o build/o/main.o $(CDEPS) -o build/bin/$(EXEC)