#ifndef OUTPUTCONTROLLER_H
#define OUTPUTCONTROLLER_H
#include "Output.h"
#include <map>
class OutputController{
public:
	OutputController(){
		for (int i=0; i<50; i++)
         for (int j=0; j<50; j++)
             adjencive_matrix[i][j] = 0;
	}
	std::vector<Output>  vertexes;
	bool adjencive_matrix[50][50];
};
#endif