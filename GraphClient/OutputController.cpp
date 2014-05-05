#include "OutputController.h"
#include <boost/lexical_cast.hpp>
std::string OutputController::inString(){
	std::string result;
	char splitter = '/';

	for (std::vector<Output>::iterator p= vertexes.begin(); p!=vertexes.end();++p){

		std::string current = "ID" + boost::lexical_cast<std::string>(p->id) +splitter;
		if (*(p->type)==0)
			current = current + "I"+ splitter;
		else if (*(p->type)==-1) current = current + "N"+ splitter; 
		   else
			current = current + "F" + boost::lexical_cast<std::string>(*(p->type))+splitter;
		for (int i=0;i<vertexes.size();++i) 
			current =current + boost::lexical_cast<std::string>(p->connections[i]);
		result = result + " " + current;
		
	}

	result = "C"+boost::lexical_cast<std::string>(vertexes.size())+splitter + result +splitter;
	return result;

}
