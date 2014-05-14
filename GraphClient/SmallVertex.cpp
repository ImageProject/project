#include "SmallVertex.h"
#include <cmath>
#include "cinder\gl\gl.h"

using namespace ci;
smallVertex::smallVertex(ci::Vec2i & loc,int & vRadiusMain, int par){
	if (!par) {
		smLoc= Vec2i(loc.x+vRadiusMain,loc.y);
	}
	else
		smLoc = Vec2i(loc.x+vRadiusMain*cosf(3.14/3*par), loc.y+vRadiusMain*sinf(3.14/3*par));
smRadius = vRadiusMain/4;
smBounds[0]=Vec2i(loc.x-smRadius,loc.y-smRadius); // Располагаем наши соединения
smBounds[1]=Vec2i(loc.x+smRadius,loc.y-smRadius); // Вокруг вершина графа 
smBounds[2]=Vec2i(loc.x-smRadius,loc.y+smRadius);
smBounds[3]=Vec2i(loc.x+smRadius,loc.y+smRadius);
const cinder::Color smColor=Color(255,204,0);

}
void smallVertex::draw(){            // Рисуем соединения 
	gl::color(Color(255,0,0));
	gl::drawSolidCircle(smLoc,smRadius);
};
void smallVertex::update(const int & speed, const int & direction){
enum {up=1,down,left,right};
	switch(direction){
	case up: 
	smLoc.y=smLoc.y-speed;
	break;
	case down: 
    smLoc.y=smLoc.y+speed;
    break;
	case left: 
    smLoc.x=smLoc.x-speed;
	break;
	case right:
	smLoc.x=smLoc.x+speed;
	break;
	};
};