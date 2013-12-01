CC = g++
FLAGS =
PROGRAM = main
LIBS = DS*.cpp main.cpp
LIBS1 = ../simlib/src/*.cc main.cpp

all: build

build: $(PROGRAM)

$(PROGRAM) : $(LIBS)
	$(CC) $(FLAGS) $(LIBS) -o $@

clean:
	@rm -f *.d *.o
	@rm $(PROGRAM)

run:
	./$(PROGRAM)

