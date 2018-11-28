/**
 * @author Guillaume Labbe-Morissette
 */

#ifndef ACCURACYPROCESSOR_HPP
#define ACCURACYPROCESSOR_HPP

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <iostream>

#ifdef __GNUC__
#include <unistd.h>
#endif

#ifdef _WIN32
#include <io.h>
#endif

#pragma pack(1)
typedef struct{
	double time;    	//GPS seconds of week
	double northingSd; 	//northing standard deviation
	double eastingSd;	//easting standard deviation
	double altitudeSd;    	//altitude standard deviation
	double speedNorthSd;    //northing speed standard deviation
	double speedEastSd;    	//easting speed standard deviation
	double speedAltitudeSd; //vertical speed standard deviation
	double g;    		//???
	double h;    		//???
	double i;    		//???
} AccuracyEntry;
#pragma pack()

class AccuracyProcessor{
	public:
		AccuracyProcessor();
		virtual ~AccuracyProcessor();

		bool readFile(std::string & filename);
		virtual void processEntry(AccuracyEntry * entry)=0;

	private:
		int doRead(int fd,void* buf,unsigned int sz);
		int doOpen(const char * filename);
};

AccuracyProcessor::AccuracyProcessor(){

}

AccuracyProcessor::~AccuracyProcessor(){

}

int AccuracyProcessor::doRead(int fd,void * buffer,unsigned int sz){

#ifdef _WIN32
	return _read(fd,buffer,sz);
#endif

#ifdef __GNUC__
	return read(fd,buffer,sz);
#endif

}

int AccuracyProcessor::doOpen(const char * filename){
#ifdef _WIN32
        return _open(filename,_O_RDONLY|_O_BINARY);
#endif

#ifdef __GNUC__
        return open(filename,O_RDONLY);
#endif
}

bool AccuracyProcessor::readFile(std::string & filename){
	int fd;

	if((fd=doOpen(filename.c_str())) == -1){
		std::cerr << "Cannot open file " << filename << std::endl;
		return false;
	}

	AccuracyEntry entry;

	int bytesRead;

	do{
		bytesRead = doRead(fd,(void*)&entry,sizeof(AccuracyEntry));

		if(bytesRead == sizeof(AccuracyEntry)){
			processEntry(&entry);
		}
	}
	while(bytesRead > 0);

	if(bytesRead == -1){
		perror("Error while reading file");
	}

	return true;
}


#endif
