#ifndef SMALLVERTEX_H
#define SMALLVERTEX_H
#include <vector> 
#include "cinder\Cinder.h"
#include "cinder/app/AppBasic.h"
class smallVertex{
	public:
	smallVertex(ci::Vec2i &, int &,const int);
	void update();
	void draw();
	//void keyEvent();
	ci::Vec2i	newLoc;
	int	smRadius;
	ci::Color	smColor;
	ci::Vec2i   smBounds[4];
    //std::vector<int> Connections;
};
#endif