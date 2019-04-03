CC=g++
CFLAGS=-Wall

default:
	mkdir -p build/bin
	$(CC) $(CFLAGS) -o build/bin/sbet-decoder src/sbet-decoder.cpp src/SbetProcessor.cpp
	$(CC) $(CFLAGS) -o build/bin/accuracy-decoder src/accuracy-decoder.cpp
test: clean default
	mkdir -p build/test/reports
	$(CC) $(CFLAGS) -o build/test/tests test/CatchMain.cpp
	build/test/tests -r junit -o build/test/reports/sbet-test-linux-report.xml
clean:
	rm -rf build

doc:
	rm -rf build/doxygen
	mkdir -p build/doxygen
	doxygen

deploy:
