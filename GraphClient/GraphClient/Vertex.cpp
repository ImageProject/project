//файл создания новой вершины графа

#include "Vertex.h"
#include "smallVertex.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#
using namespace ci;
Vertex::Vertex(const Vec2i &position, const int & mainRadius,const int & scale){
	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163)); //выбор цвета
	vRadius = mainRadius/scale; //настройка радиуса
	vLoc = position; //настройка позиции

for (int i=0; i<6;++i){ //цикл создания маленьких кружков
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i); //маленькая вершина создается в зависимости от радиуса и позиции большого
	smallVertexs.push_back(newsmallVertex); //заполнение вектора маленьких вершни
   }
};
Vertex::Vertex(const Vec2i &position){ //определение новых местоположений

	vColor = Color(Rand::randInt(1),Rand::randInt(111),Rand::randInt(163));
	vRadius = Rand::randInt(23); //перезаписывание радиуса в переменную vRadius
	vLoc = position; //перезписывание позиции в переменну vLoc

for (int i=0; i<6;++i){ //цикл для заполнения вектора маленьких вершин
	smallVertex newsmallVertex = smallVertex(vLoc,vRadius,i); //создание маленькой вершины
	smallVertexs.push_back(newsmallVertex);
   }
};
void Vertex::draw(){ //функция рисования
gl::color(vColor); //цвет
	for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p) //цикл рисования
{
	p->draw();
}
gl::color(vColor); //цвет
gl::drawSolidCircle( vLoc, vRadius ); //рисование

//for (std::vector<smallVertex>::iterator p = smallVertexs.begin(); p!=smallVertexs.end(); ++p)
//{
//	p->draw();
//}

};
void Vertex::update(){ //обновление переменной
	vLoc.y=vLoc.y-speed;
}