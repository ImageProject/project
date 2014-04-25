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


using namespace ci;
Vertex::Vertex(const Vec2i &position, const int & mainRadius,const int & scale){
	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	vRadius = mainRadius/scale;
	name.setSize(Vec2i(vRadius*2/sqrtf(2),vRadius*2/sqrtf(2)));
	vLoc = position;
	name.setBackgroundColor(vColor);
	name.setColor(ci::Color::black());

	
	///*name.getAlignment();
	//name.size=Vec2i(vRadius/sqrt(2),vRadius*2/sqrt(2));*/
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
	vRadius = Rand::randInt(23);
	name.setSize(Vec2i(vRadius*2/sqrtf(2),vRadius*2/sqrtf(2)));
	vLoc = position;
	vBounds[0]=Vec2i(vLoc.x-vRadius,vLoc.y-vRadius);
vBounds[1]=Vec2i(vLoc.x+vRadius,vLoc.y-vRadius);
vBounds[2]=Vec2i(vLoc.x-vRadius,vLoc.y+vRadius);
vBounds[3]=Vec2i(vLoc.x+vRadius,vLoc.y+vRadius);
isImage = false;
//std::string txt = "Here is";
//name= TextBox().alignment( TextBox::RIGHT ).font( Font( "Cochin-Italic", 32 ) ).size( Vec2i( 10, 16 ) ).text( txt ).color( Color( 1.0f, 0.65f, 0.35f ) ).backgroundColor( ColorA( 0.5, 0, 0, 1 ) );

for (int i=0; i<6;++i){
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i);
	smallVertexs.push_back(newsmallVertex);
   }
name.setColor(Color(255,0,0));
};
void Vertex::draw(){
gl::color(vColor);

	for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
{
	p->draw();
}
	int i=0;
	if (!isImage)  {
switch(i){
case 0:
	filter = NONE;
    break;
case 1:
	filter = F1;
    break;
case 2:
	filter = F2;
    break;
case 3:
	filter = F3;
    break;
case 4:
	filter = F4;
    break;
case 5:
	filter = F5;
    break;
	}

gl::color(vColor);
gl::drawSolidCircle( vLoc, vRadius );
if (name.getText()!=" "){
	gl::Texture name_temp = name.render();
	gl::draw(name_temp,vLoc);
}
	}
//gl::draw(image);
//IplImage *source = cvLoadImage(path.string().c_str());
//// Here we retrieve a percentage value to a integer
//int percent = 10;
//
//// declare a destination IplImage object with correct size, depth and channels
//      IplImage *destination = cvCreateImage
//( cvSize((int)((source->width*percent)/100) , (int)((source->height*percent)/100) ),
//                                     source->depth, source->nChannels );
//
////use cvResize to resize source to a destination image
//cvResize(source, destination);
//
//// save image with a name supplied with a second argument
//cvSaveImage("new", destination );
//	}
 else{
type = IMAGE;
gl::disableAlphaBlending();
gl::drawSolidCircle(vLoc,vRadius);
Vec2i temp_loc = Vec2i(vLoc.x-reImage.getWidth()/2,vLoc.y-reImage.getHeight()/2);
gl::draw(reImage,temp_loc);
	}

//for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
//{
//	p->draw();
//}

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