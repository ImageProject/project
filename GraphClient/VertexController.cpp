//файл-контроллер графа
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
Vertex mVertex=Vertex(position); //определение позиций мини вершин
mMiniMap.push_vertex(mVertex); //заполнение вектора вершин графа на мини карте
Vertexes.push_back(mVertex); //заполнение вектора вершин графа
			};
void VertexController::update(const int & speed,const int & direction){
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p)
	{
		p->update(speed,direction);
	}
	for (vector<vLine>::iterator t=lines.begin();t!=lines.end(); t++){
		t->update(speed,direction);
	}
};
void VertexController::draw(){ //класс рисования вершин
	for (vector<Vertex>::iterator p =Vertexes.begin();p!=Vertexes.end();++p)
	{
		p->draw();
	}
	for (vector<vLine>::iterator p =lines.begin();p!=lines.end();++p){
		p->draw();
	}
	mMiniMap.draw();
};
Vec4i VertexController::isConnect(const Vec2i & location){ //класс соединения вершин графов и проверка на то, внужно ли месте кликнули
	for (vector<Vertex>::iterator p=Vertexes.begin(); p!=Vertexes.end();++p)
		for (vector<smallVertex>::iterator s= p->smallVertexs.begin();s!=p->smallVertexs.end();++s){
			short current_y =  location.y-s->smLoc.y;
			short current_x =  location.x-s->smLoc.x;
			if ((-s->smRadius<current_x)&&(s->smRadius>current_x)&&(-s->smRadius<current_y)&&(s->smRadius>current_y))
				return Vec4i(p-Vertexes.begin(),s-p->smallVertexs.begin(),s->smLoc.x,s->smLoc.y);
		}
	return Vec4i(0,0,0,0);
	};
size_t VertexController::isTextBox(const Vec2i & location){
	for (vector<Vertex>::iterator p=Vertexes.begin(); p!=Vertexes.end();++p){
			short current_y =  location.y-p->vLoc.y;
			short current_x =  location.x-p->vLoc.x;
			if ((-p->vRadius<current_x)&&(p->vRadius>current_x)&&(-p->vRadius<current_y)&&(p->vRadius>current_y))
				return p-Vertexes.begin();
	}
	return false;
	};

