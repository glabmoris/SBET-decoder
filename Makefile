CC=g++
CFLAGS=-Wall

default: sbet

test: clean
	mkdir -p build/test
	$(CC) $(CFLAGS) test/CatchMain.cpp -c -o build/test/CatchMain.o
	$(CC) $(CFLAGS) build/test/CatchMain.o test/TemplateTest.cpp -o build/test/TemplateTest && build/test/TemplateTest -r junit > build/test/TemplateTest.xml

clean:
	rm -rf build
	
doc:
	rm -rf build/doxygen
	mkdir -p build/doxygen
	doxygen
	
sbet:
	mkdir -p build/bin
	g++ -o build/bin/sbet-decoder src/main.cpp
	
deploy:
