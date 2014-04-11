#ifndef VERTEX_H
#define VERTEX_H
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/Text.h"
#include <vector>
#include "smallVertex.h"
class Vertex {
 public:
int speed;
ci::TextBox name;
Vertex(const ci::Vec2i & pos);
Vertex(const ci::Vec2i & pos,const int &,const int &);
void draw();
void update(const int &,const int &);
ci::Vec2i	vLoc;
int		vRadius;
ci::Vec2i vBounds[4];
ci::Color	vColor;
//std::vector<int> vEdges;
//std::string Name;
std::vector<smallVertex> smallVertexs;
};


#endif