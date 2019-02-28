#include "recbinwin10.hpp"

Metadata unpack
(std::string filename)
{
	Metadata metadata;
	std::fstream file(filename, std::fstream::binary | std::fstream::in);
	if(file.is_open())
	{
		file.read((char *) &metadata, sizeof(metadata) - sizeof(size_t) - sizeof(unsigned int));
		
		if(metadata.header == 0x02)
		{
			// https://linux.die.net/man/3/ctime
			// https://4n6xplorer.com/forensics/once-upon-a-time-in-recycle-bin/
			metadata.timestamp = metadata.timestamp * 100 / 1000000000;
			
			metadata.name = new char[metadata.namelenght];
			
			unsigned int i;
			for(i = 0; i < metadata.namelenght; i++)
			{
				file.get(metadata.name[i]);
				file.ignore(1);
			}
			
		} else std::cerr << "[ERROR]: Not a valid $I file." << std::endl;
		
	} else perror("[ERROR]");
	
	file.close();
	
	return metadata;
}
