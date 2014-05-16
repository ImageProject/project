//файл рисования линии
#include "Line.h"

Line::Line(){
	start = Vec2i(0,0); //определение начала
	finish = Vec2i(0,0); //определение конца и заполнение вектора
	lColor = Color(122,23,0); //выбор цвета

}
void Line::draw(){
	gl::color(Color(255,0,0)); //выбор цвета
	gl::drawLine(start,finish); //рисование линии от координаты старта к координате финиша
}
