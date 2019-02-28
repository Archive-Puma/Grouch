#ifndef RECYCLEBIN_WINDOWS10
#define RECYCLE_BIN_WINDOWS10

#include <cstdint>
#include <fstream>
#include <iostream>

typedef struct metadata_s {
	size_t header;
	size_t fsize;
	size_t timestamp;
	unsigned int namelenght;
	char *name;
} Metadata;

Metadata unpack (std::string);

#endif
