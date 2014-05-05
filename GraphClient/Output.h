#ifndef OUTPUT_H
#define OUTPUT_H
#include <vector>
#include "boost/filesystem/operations.hpp" // includes boost/filesystem/path.hpp
#include "boost/filesystem/fstream.hpp"    // ditto
class Output{
public:
	Output(){
	};
	int id;
int* type;
boost::filesystem::path* image;
bool connections[50];

};
#endif