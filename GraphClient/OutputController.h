#ifndef OUTPUTCONTROLLER_H
#define OUTPUTCONTROLLER_H
#include "Output.h"
#include <map>
#include "Vertex.h"
class OutputController{
public:
	std::vector<Output> vertexes;
	std::string inString();
};
#endif