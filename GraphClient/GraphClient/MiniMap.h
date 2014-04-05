#ifndef MINIMAP_H
#define MINIMAP_H
#include "cinder\Cinder.h"
#include "cinder\app\AppBasic.h"
#include <vector>
#include "Line.h"
#include "Vertex.h"
using namespace ci;


class MiniMap{
	Vec2i center;
public:
	Vec2i resolution;
	short scale;
	short position;
	MiniMap();
	void push_line(const Line &);
	void push_vertex(const Vertex &);
	void draw();
	std::vector<Vertex> objects;
	std::vector<Line> lines;
	void getCenter();
};
#endif