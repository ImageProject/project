#include "SmallVertex.h"
#include <cmath>
#include "cinder\gl\gl.h"

using namespace ci;
smallVertex::smallVertex(ci::Vec2i & loc,int & vRadiusMain, int par){
	if (!par) {
		newLoc= Vec2i(loc.x+vRadiusMain,loc.y); //новое положение маленькой вершины
	}
	else
		newLoc = Vec2i(loc.x+vRadiusMain*cosf(3.14/3*par), loc.y+vRadiusMain*sinf(3.14/3*par));
smRadius = vRadiusMain/4; //определение радиуса малой вершины
smBounds[0]=Vec2i(loc.x-smRadius,loc.y-smRadius); //заполнение векторов местоположением 1 вершины
smBounds[1]=Vec2i(loc.x+smRadius,loc.y-smRadius); //заполнение векторов местоположением 2 вершины
smBounds[2]=Vec2i(loc.x-smRadius,loc.y+smRadius); //заполнение векторов местоположением 3 вершины
smBounds[3]=Vec2i(loc.x+smRadius,loc.y+smRadius); //заполнение векторов местоположением 4 вершины
const cinder::Color smColor=Color(255,204,0);

}
void smallVertex::draw(){ //функция рисования вершин
	gl::color(Color(255,0,0)); //выбор цвета
	gl::drawSolidCircle(newLoc,smRadius); //рисование кругов (позиция, радиус)
}