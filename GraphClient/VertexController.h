#ifndef VERTEXCONTROLLER_H
#define VERTEXCONTROLLER_H
#include "Vertex.h"
#include <vector>
#include "cinder\gl\gl.h"
#include "MiniMap.h"
#include "vLine.h"

using namespace ci;
class VertexController{
public:
	VertexController();
	void addVertexes(const Vec2f &);
	void update(const int &, const int &);
	void draw();
	Vec4i isConnect(const Vec2i&);
	std::vector<Vec4i> connects;
	std::vector<vLine> lines;
	int direction;
	size_t isTextBox(const Vec2i&);

std::vector<Vertex> Vertexes;
int updateSpeed;
MiniMap  mMiniMap;     //warning,crutch!
;
};
#endif