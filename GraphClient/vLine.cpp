#include "vLine.h"

vLine::vLine(){
	start = Vec2i(0,0);
	finish = Vec2i(0,0);
	lColor = Color(122,23,0);

}
void vLine::draw(){
	gl::lineWidth(2.5f);         // Задаем толщину для линии
	gl::color(Color(255,0,0));   // Задаем цвет для линии
	gl::drawLine(start,finish); // Задаем координаты  для линии
}
void vLine::update(const int & speed, const int & direction){
	switch(direction){
	case 1: 
	start.y=start.y-speed;
	finish.y=finish.y-speed;
	break;
	case 2: 
    start.y=start.y+speed;
	finish.y=finish.y+speed;
    break;
	case 3: 
    start.x=start.x-speed;
	finish.x=finish.x-speed;
	break;
	case 4:
	start.x=start.x+speed;
	finish.x=finish.x+speed;
	break;
	};
}