#ifndef LINE_H
#define LINE_H
#include "cinder\Cinder.h"
#include "cinder\app\AppBasic.h"
using namespace ci;
class Line{
public:
	Line();
	Vec2i start;
	Vec2i finish;
	Color lColor;
	void draw();
	/*void update();*/
};
#endif