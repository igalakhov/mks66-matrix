all: main.o drawer.o display.o
	g++ -o main.out main.o drawer.o display.o
	./main.out

main.o: main.cpp
	g++ -c main.cpp

draw.o: drawer.cpp drawer.h
	g++ -c drawer.cpp

display.o: display.cpp display.h
	g++ -c display.cpp

clean:
	touch fakefile.o
	touch fakefile.h.gch
	touch main.out
	rm *.o
	rm main.out
	rm *.h.gch