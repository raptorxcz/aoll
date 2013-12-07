CC = g++
FLAGS =
PROGRAM1 = lorenz
PROGRAM2 = shilnikov
LIBS = DS*.cpp
LIBS1 = ../simlib/src/*.cc main.cpp

all: build

build: $(PROGRAM1)

$(PROGRAM1) : $(LIBS) main.cpp
	$(CC) $(FLAGS) $(LIBS) main.cpp -o $@

build: $(PROGRAM2)
$(PROGRAM2) : $(LIBS) main1.cpp
	$(CC) $(FLAGS) $(LIBS) main1.cpp -o $@


clean:
	@rm -f *.d *.o
	@rm $(PROGRAM1)
	@rm $(PROGRAM2) 

run:
	./$(PROGRAM1)
	./$(PROGRAM2)

