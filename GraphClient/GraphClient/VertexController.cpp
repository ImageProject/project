#include "cinder/app/AppBasic.h"
#include "cinder/Timeline.h"
#include "cinder/Rand.h"
#include "VertexController.h"
#include "Vertex.h"
#include "cinder/Rand.h"
using namespace ci;
using namespace ci::app;
using namespace std;
VertexController::VertexController()
{
	

};
void VertexController::addVertexes(const Vec2f & position){
Vertex mVertex=Vertex(position);
mMiniMap.push_vertex(mVertex);
Vertexes.push_back(mVertex);
			};
void VertexController::update(){
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p)
	{
		p->update();
	}
};
void VertexController::draw(){
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p)
	{
		p->draw();
	}
	for (vector<Line>::iterator line =lines.begin();line!=lines.end();++line){
		line->draw();
	}
	mMiniMap.draw();
};
Vec4i VertexController::isConnect(const Vec2i & location){
	for (vector<Vertex>::iterator p=Vertexes.begin(); p!=Vertexes.end();++p)
		for (vector<smallVertex>::iterator s= p->smallVertexs.begin();s!=p->smallVertexs.end();++s){
			short current_y =  location.y-s->newLoc.y;
			short current_x =  location.x-s->newLoc.x;
			if ((-s->smRadius<current_x)&&(s->smRadius>current_x)&&(-s->smRadius<current_y)&&(s->smRadius>current_y))
				return Vec4i(p-Vertexes.begin(),s-p->smallVertexs.begin(),s->newLoc.x,s->newLoc.y);
		}
	return Vec4i(0,0,0,0);
	};
