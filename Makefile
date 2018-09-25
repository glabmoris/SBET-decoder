CC=g++
CFLAGS=-Wall

default: sbet

test: clean
	mkdir -p build/test
	$(CC) $(CFLAGS) test/CatchMain.cpp -c -o build/test/CatchMain.o
	$(CC) $(CFLAGS) build/test/CatchMain.o test/TemplateTest.cpp -o build/test/TemplateTest && build/test/TemplateTest -r compact


clean:
	rm -rf build
	
doc:
	rm -rf build/doxygen
	mkdir -p build/doxygen
	doxygen
	
sbet:
	src/main.cpp
	mkdir -p build
	g++ -o build/sbet-decoder src/main.cpp
	
deploy: