#ifndef SMALLVERTEX_H
#define SMALLVERTEX_H
#include <vector> 
#include "cinder\Cinder.h"
#include "cinder/app/AppBasic.h"
class smallVertex{
	public:
	smallVertex(ci::Vec2i &, int &,const int);
	void update(const int &,const int &);
	void draw();
	//void keyEvent();
	ci::Vec2i	smLoc;
	int	smRadius;
	ci::Color	smColor;
	ci::Vec2i   smBounds[4];
    //std::vector<int> Connections;
};
#endif