CC = g++
FLAGS =
PROGRAM = main
LIBS = DS*.cpp main.cpp

all: build

build: $(PROGRAM)

$(PROGRAM) : $(LIBS)
	$(CC) $(FLAGS) $(LIBS) -o $@

clean:
	@rm -f *.d *.o
	@rm $(PROGRAM)

run:
	./$(PROGRAM)

