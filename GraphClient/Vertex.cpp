#include "Vertex.h"
#include "smallVertex.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#include <string>
#include "Output.h"
#include "OutputController.h"
#include "cinder\Text.h"
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <boost/lexical_cast.hpp>


using namespace ci;
Vertex::Vertex(const Vec2i &position, const int & mainRadius,const int & scale){
	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	vRadius = mainRadius/scale;
	name.setSize(Vec2i(vRadius*2/sqrtf(2),vRadius*2/sqrtf(2)));
	vLoc = position;
	name.setBackgroundColor(vColor);
	name.setColor(ci::Color::black());
	type = -1;
	for (int i=0; i<50;++i){
		connections[i]=false;
	}

	isImage = false;

for (int i=0; i<6;++i){
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i);
	smallVertexs.push_back(newsmallVertex);
   }
};
Vertex::Vertex(const Vec2i &position){
	name.setText(" ");
	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	name.setBackgroundColor(vColor);
	name.setColor(ci::Color::black());
	vRadius = 32;
	name.setAlignment(ci::TextBox::CENTER);
	name.setFont(ci::Font("Times New Roman",vRadius));
	name.setSize(Vec2i(vRadius*2/sqrtf(2),vRadius*2/sqrtf(2)));
	vLoc = position;
	vBounds[0]=Vec2i(vLoc.x-vRadius,vLoc.y-vRadius);
vBounds[1]=Vec2i(vLoc.x+vRadius,vLoc.y-vRadius);
vBounds[2]=Vec2i(vLoc.x-vRadius,vLoc.y+vRadius);
vBounds[3]=Vec2i(vLoc.x+vRadius,vLoc.y+vRadius);
isImage = false;
type = -1;
for (int i=0; i<50;++i){
	connections[i]=false;
}


for (int i=0; i<6;++i){
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i);
	smallVertexs.push_back(newsmallVertex);
   }
name.setColor(Color(255,0,0));
};
void Vertex::draw(){

if (!isImage){
	if (type!=-1){
std::string newName = boost::lexical_cast<std::string>(type);
char prefix = 'F';
newName = newName +prefix;
name.setText(newName);
gl::color(vColor);
gl::drawSolidCircle( vLoc, vRadius );
gl::draw(name.render(),vLoc-name.getSize()/2);
	} else {
	gl::color(vColor);
	gl::drawSolidCircle( vLoc, vRadius );
	}
}
else 
{
	type = 0;
	gl::color(ci::Color(1,1,1));
	gl::draw(reImage,Vec2i(vLoc.x-reImage.getWidth()/2,vLoc.y-reImage.getHeight()/2));
}
gl::color(vColor);
for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
{
	p->draw();
}
};
void Vertex::update(const int & speed,const int & direction){
	enum {up=1,down,left,right};
	switch(direction){
	case up: 
	vLoc.y=vLoc.y-speed;
	break;
	case down: 
    vLoc.y=vLoc.y+speed;
    break;
	case left: 
    vLoc.x=vLoc.x-speed;
	break;
	case right:
	vLoc.x=vLoc.x+speed;
	break;
	};
	for (std::vector<smallVertex>::iterator p= smallVertexs.begin();p!=smallVertexs.end();++p){
		p->update(speed,direction);
	}
};
