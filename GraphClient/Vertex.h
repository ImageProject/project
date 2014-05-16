#ifndef VERTEX_H
#define VERTEX_H
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/Text.h"
#include <vector>
#include "smallVertex.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "boost\filesystem.hpp"
#include "Output.h"
class Vertex {
 public:
ci::TextBox name; //создание текстбокса для ввода логина и пароля
Vertex(const ci::Vec2i & pos);
Vertex(const ci::Vec2i & pos,const int &,const int &);
void draw();
void update(const int &,const int &);
ci::Vec2i	vLoc;
int		vRadius;
ci::Vec2i vBounds[4];
ci::Color	vColor; //цвет
int type;
boost::filesystem::path path; //нахождение пути
bool connections[50];
ci::gl::Texture reImage;
bool isImage;
bool isMini;
std::vector<smallVertex> smallVertexs; //заполнение вектора
};


#endif