#ifndef VERTEX_H
#define VERTEX_H
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <vector>
#include "smallVertex.h"
class Vertex {
 public:
int speed;
Vertex(const ci::Vec2i & pos);
Vertex(const ci::Vec2i & pos,const int &,const int &);
void draw();
void update();
ci::Vec2i	vLoc;
int		vRadius;
ci::Color	vColor;
//std::vector<int> vEdges;
//std::string Name;
std::vector<smallVertex> smallVertexs;
};


#endif