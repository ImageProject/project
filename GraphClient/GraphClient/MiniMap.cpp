#include "VertexController.h"
#include "MiniMap.h"
using namespace std;
MiniMap::MiniMap(){
	position=1; //определение местонахождения миникарты
	scale=10;
	resolution=Vec2i(1920,1080); //заполнение какого-то вектора
};
void MiniMap::push_vertex(const Vertex & Image){ //класс заполнения миникарты вершинами
	Vertex MapObject = Vertex(center+(Image.vLoc - resolution/2)/scale, Image.vRadius,scale);
	MapObject.vColor=Image.vColor;
	objects.push_back(MapObject);
}
void MiniMap::push_line(const Line & Image){ //класс заполнения миникарты линиями
	Line MapLine = Line();
	MapLine.start = Vec2i(center+(Image.start-resolution/2)); //координата начала
	MapLine.finish =Vec2i(center+(Image.finish-resolution/2)); //координата конца
}

void MiniMap::draw(){ //класс непосредственного рисования
	for (vector<Vertex>::iterator p = objects.begin(); p!=objects.end(); ++p){
		p->draw(); //вершины
	}
	for (vector<Line>::iterator j =lines.begin(); j!=lines.end(); ++j){
		j->draw(); //линии
	}
}


void MiniMap::getCenter(){ //функция получения местоположения миникарты
	switch(position){
	case 1:
		center = Vec2i(resolution.x/(2*scale),resolution.y/(2*scale));
		break;
	case 2:
		center = Vec2i (resolution.x/(scale*2),resolution.y-resolution.y/(scale*2));
	    break;
	case 3:
		center = Vec2i (resolution.x-resolution.x/(scale*2),resolution.y/(scale*2));
		break;
	case 4:
		center = resolution - resolution/(2*scale);
		break;

	};
};