#ifndef VERTEXCONTROLLER_H
#define VERTEXCONTROLLER_H
#include "Vertex.h"
#include <vector>
#include "cinder\gl\gl.h"
#include "MiniMap.h"
#include "Line.h"
using namespace ci;
class VertexController{
public:
	VertexController();
	void addVertexes(const Vec2f &);
	void update();
	void draw();
	Vec4i isConnect(const Vec2i&);
	std::vector<Vec4i> connects;
	std::vector<Line> lines;

std::vector<Vertex> Vertexes;
MiniMap  mMiniMap;        //warning,crutch!
;
};
#endif