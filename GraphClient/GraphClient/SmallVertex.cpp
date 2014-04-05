#include "SmallVertex.h"
#include <cmath>
#include "cinder\gl\gl.h"

using namespace ci;
smallVertex::smallVertex(ci::Vec2i & loc,int & vRadiusMain, int par){
	if (!par) {
		newLoc= Vec2i(loc.x+vRadiusMain,loc.y);
	}
	else
		newLoc = Vec2i(loc.x+vRadiusMain*cosf(3.14/3*par), loc.y+vRadiusMain*sinf(3.14/3*par));
smRadius = vRadiusMain/4;
smBounds[0]=Vec2i(loc.x-smRadius,loc.y-smRadius);
smBounds[1]=Vec2i(loc.x+smRadius,loc.y-smRadius);
smBounds[2]=Vec2i(loc.x-smRadius,loc.y+smRadius);
smBounds[3]=Vec2i(loc.x+smRadius,loc.y+smRadius);
const cinder::Color smColor=Color(255,204,0);

}
void smallVertex::draw(){
	gl::color(Color(255,0,0));
	gl::drawSolidCircle(newLoc,smRadius);
}