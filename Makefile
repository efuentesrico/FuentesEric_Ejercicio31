all: dat30.dat

dat30.dat: a.out
	./a.out

a.out: poisson.cpp
	c++ poisson.cpp 

clean:
	rm a.out 
