test: libmy.so test_c.c test_cpp.cpp
	gcc -g test_c.c -o test_c
	./test_c
	LD_PRELOAD=${PWD}/libmy.so ./test_c
	g++ -g test_cpp.cpp -o test_cpp
	./test_cpp
	LD_PRELOAD=${PWD}/libmy.so ./test_cpp
	

libmy.so: new.o malloc.o
	g++ -g -fPIC -shared -o libmy.so new.o malloc.o


new.o: new.cpp
	g++ -g -fPIC -c new.cpp
malloc.o: malloc.c
	gcc -g -fPIC -c malloc.c
