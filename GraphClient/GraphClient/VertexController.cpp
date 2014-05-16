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
void VertexController::addVertexes(const Vec2f & position){ //функция добавление вершин
Vertex mVertex=Vertex(position);
mMiniMap.push_vertex(mVertex);
Vertexes.push_back(mVertex);
			};
void VertexController::update(){ //обновление
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p)
	{
		p->update();
	}
};
void VertexController::draw(){ //рисование
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p) //начало
	{
		p->draw();
	}
	for (vector<Line>::iterator line =lines.begin();line!=lines.end();++line) //конец
    {
		line->draw();
	}
	mMiniMap.draw(); //рисование миникарты
};
Vec4i VertexController::isConnect(const Vec2i & location){ //проверка на соединение маленьких вершин
	for (vector<Vertex>::iterator p=Vertexes.begin(); p!=Vertexes.end();++p)
		for (vector<smallVertex>::iterator s= p->smallVertexs.begin();s!=p->smallVertexs.end();++s){
			short current_y =  location.y-s->newLoc.y;
			short current_x =  location.x-s->newLoc.x;
			if ((-s->smRadius<current_x)&&(s->smRadius>current_x)&&(-s->smRadius<current_y)&&(s->smRadius>current_y))
				return Vec4i(p-Vertexes.begin(),s-p->smallVertexs.begin(),s->newLoc.x,s->newLoc.y);
		}
	return Vec4i(0,0,0,0);
	};
