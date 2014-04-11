#include "Vertex.h"
#include "smallVertex.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
using namespace ci;
Vertex::Vertex(const Vec2i &position, const int & mainRadius,const int & scale){
	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	vRadius = mainRadius/scale;
	vLoc = position;
	///*name.getAlignment();
	//name.size=Vec2i(vRadius/sqrt(2),vRadius*2/sqrt(2));*/


for (int i=0; i<6;++i){
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i);
	smallVertexs.push_back(newsmallVertex);
   }
};
Vertex::Vertex(const Vec2i &position){

	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	vRadius = Rand::randInt(23);
	vLoc = position;
	vBounds[0]=Vec2i(vLoc.x-vRadius,vLoc.y-vRadius);
vBounds[1]=Vec2i(vLoc.x+vRadius,vLoc.y-vRadius);
vBounds[2]=Vec2i(vLoc.x-vRadius,vLoc.y+vRadius);
vBounds[3]=Vec2i(vLoc.x+vRadius,vLoc.y+vRadius);

for (int i=0; i<6;++i){
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i);
	smallVertexs.push_back(newsmallVertex);
   }
};
void Vertex::draw(){
gl::color(vColor);
	for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
{
	p->draw();
}
gl::color(vColor);
gl::drawSolidCircle( vLoc, vRadius );

//for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
//{
//	p->draw();
//}

};
void Vertex::update(const int & speed,const int & direction){
	switch(direction){
	case 1: 
	vLoc.y=vLoc.y-speed;
	break;
	case 2: 
    vLoc.y=vLoc.y+speed;
    break;
	case 3: 
    vLoc.x=vLoc.x-speed;
	break;
	case 4:
	vLoc.x=vLoc.x+speed;
	break;
	};
	for (std::vector<smallVertex>::iterator p= smallVertexs.begin();p!=smallVertexs.end();++p){
		p->update(speed,direction);
	}
};