all: main.o drawer.o display.o edge_matrix.o transformation_matrix.o
	g++ -std=c++11 -o main.out main.o drawer.o display.o edge_matrix.o transformation_matrix.o
	./main.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

drawer.o: drawing/drawer.cpp drawing/drawer.h
	g++ -std=c++11 -c drawing/drawer.cpp

display.o: drawing/display.cpp drawing/display.h
	g++ -std=c++11 -c drawing/display.cpp

edge_matrix.o: matrix/edge_matrix.cpp matrix/edge_matrix.h matrix/transformation_matrix.h
	g++ -std=c++11 -c matrix/edge_matrix.cpp

transformation_matrix.o: matrix/transformation_matrix.cpp matrix/transformation_matrix.h matrix/edge_matrix.h
	g++ -std=c++11 -c matrix/transformation_matrix.cpp

convert:
	convert

clean:
	touch fakefile.o
	touch fakefile.h.gch
	touch main.out
	rm *.o
	rm main.out
	rm *.h.gch