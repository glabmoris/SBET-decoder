CC=g++
CFLAGS=-Wall

default:
	mkdir -p build/bin
	$(CC) $(CFLAGS) -o build/bin/sbet-decoder src/sbet-decoder.cpp
	$(CC) $(CFLAGS) -o build/bin/accuracy-decoder src/accuracy-decoder.cpp
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

deploy:
