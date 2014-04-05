#include "Line.h"

Line::Line(){
	start = Vec2i(0,0);
	finish = Vec2i(0,0);
	lColor = Color(122,23,0);

}
void Line::draw(){
	gl::color(Color(255,0,0));
	gl::drawLine(start,finish);
}
