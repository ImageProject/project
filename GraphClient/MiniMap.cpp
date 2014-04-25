#include "VertexController.h"
#include "MiniMap.h"
using namespace std;
MiniMap::MiniMap(){
	position=1;
	scale=10;
	resolution=Vec2i(1920,1080);
};
void MiniMap::push_vertex(const Vertex & Image){
	Vertex MapObject = Vertex(center+(Image.vLoc - resolution/2)/scale, Image.vRadius,scale);
	MapObject.vColor=Image.vColor;
	MapObject.isMini = true;
	objects.push_back(MapObject);
}
void MiniMap::push_line(const vLine & Image){
	vLine MapLine = vLine();
	MapLine.start = Vec2i(center+(Image.start-resolution/2));
	MapLine.finish =Vec2i(center+(Image.finish-resolution/2));
	lines.push_back(MapLine);
}

void MiniMap::draw(){
	for (vector<Vertex>::iterator p = objects.begin(); p!=objects.end(); ++p){
		p->draw();
	};
	for (vector<vLine>::iterator j =lines.begin(); j!=lines.end(); ++j){
		j->draw();
	}
}


void MiniMap::getCenter(){
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