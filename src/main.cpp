#include "lib\recbinwin10.hpp"

int main
(int argc, char *argv[])
{
	if(argc == 2)
	{
		Metadata metadata = unpack((std::string) argv[1]);
		
		if(metadata.header == 0x02) {
			// Show the result
			std::cout << "Header: " << metadata.header << std::endl;
			std::cout << "File size: " << metadata.fsize << std::endl;
			std::cout << "Time stamp: " << metadata.timestamp << std::endl;
			std::cout << "Name Lenght: " << metadata.namelenght << std::endl;
			std::cout << "Name: " << metadata.name << std::endl;
		}
		
	} else std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
	
	return 0;
}

// https://stackoverflow.com/questions/26845538/parsing-a-binary-file-what-is-a-modern-way
