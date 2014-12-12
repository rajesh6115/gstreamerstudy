/**
* Using TagLib we can get MP3 meta datas. If know anything else than TagLib 
* Inform Me Also. I would also like to have c library for metadata.
* Don't foget opensource!!!
* TO COMPILE:
 	g++ getmp3info.cpp `pkg-config ` -o mp3info
**/
#include <iostream>
#include <fileref.h>
#include <tstring.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		std::cerr << " USAGE: " << argv[0] << " <mp3file>"  << std::endl;
		return -1;
	}
	std::string mp3filename= argv[1];
	TagLib::FileRef mp3file(mp3filename.c_str());
	TagLib::String artist= mp3file.tag()->artist();
	TagLib::String title= mp3file.tag()->title();
	TagLib::uint track = mp3file.tag()->track();
	std::cout << "Artist = " << artist << std::endl;
	std::cout << "Title = " << title << std::endl;
	std::cout << "Track = " << track << std::endl;
	return 0;
}
