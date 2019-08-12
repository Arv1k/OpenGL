# ----- variables
COMPILER = g++
CPPFLAGS = -Wall -Wextra -Weffc++ -pedantic -g
LDFLAGS = -O3
# -----

all: main.o tgaimage.o
	$(COMPILER) $(LDFLAGS) $(CPPFLAGS) main.o tgaimage.o -o main.out

start: 
	./main.out
	xviewer output.tga

main.o: main.cpp
	$(COMPILER) $(LDFLAGS) $(CPPFLAGS) -c main.cpp

tgaimage.o: tgaimage.cpp
	$(COMPILER) $(LDFLAGS) $(CPPFLAGS) -c tgaimage.cpp

clean:
	-rm -f *.out
	-rm -f *.o
	-rm -f *.tga

