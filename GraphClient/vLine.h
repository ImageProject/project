#ifndef VLINE_H
#define VLINE_H
#include "cinder\Cinder.h"
#include "cinder\app\AppBasic.h"
using namespace ci;
class vLine{
public:
	vLine();
	Vec2i start;
	Vec2i finish;
	Color lColor;
	void draw();
	void update(const int & speed, const int & direction);
	/*void update();*/
};
#endif