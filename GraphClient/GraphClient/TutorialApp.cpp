#include "VertexController.h"
#include "SmallVertex.h"
#include "Vertex.h"
#include "cinder\Cinder.h"
#include "MiniMap.h"
#include "Line.h"
#include "cinder\app\AppBasic.h"
using namespace ci;
using namespace ci::app;
class TutorialApp: public AppBasic{ //создание главынх функций
	bool updates;
	void setup(); //установка
	void update(); //обновление
	void draw(); //рисование
	void mouseDown(MouseEvent); //движение мыши
	void keyDown(KeyEvent);
	void settings(Settings * setting); //установка натсроек
	short downs;
	VertexController mVertexController; //создание объекта контроля вершин
	MiniMap          mMiniMap; //создание объекта миникарты
};
void TutorialApp::setup(){
	updates =0; //задание начальных параметров
	downs =0;
	mVertexController.mMiniMap=MiniMap();                    //warning,crutches!
	mVertexController.mMiniMap.scale=4; //задание масштаба для миникарты
	mVertexController.mMiniMap.position=1;
	mVertexController.mMiniMap.resolution=Vec2i(1920,1080); //размер миникарты
	mVertexController.mMiniMap.getCenter(); //местоположение карты
	gl::lineWidth(2.5f); //установка ширины линий

	
};

void TutorialApp::update(){
	if (updates)
		mVertexController.update();
};
void TutorialApp::draw(){
	gl::clear(Color(242,221,198));
    mVertexController.draw(); //вершни


}
void TutorialApp::keyDown(KeyEvent k_event){ //движение по карте
	if (k_event.KEY_s)
		updates = true;
}


void TutorialApp::mouseDown(MouseEvent m_event){
	if (m_event.isLeftDown())
	{         //warning,crutch!
		mVertexController.addVertexes(m_event.getPos()); //добавление вершин
	}

	if (m_event.isRightDown()){
		Vec4i connect = mVertexController.isConnect(m_event.getPos());
		if (connect!=Vec4i(0,0,0,0))
		{ //определение правильности нажатия
			++downs;
			mVertexController.connects.push_back(connect);
		}
		if (downs==2){ //если равно 2, то соединение вершин
			int position =mVertexController.connects.size()-1;
			Line newLine; //создание новой линии
			newLine.start = Vec2i(mVertexController.connects[position].z,mVertexController.connects[position].w); //заполение вектора позициями начал
			newLine.finish =Vec2i(mVertexController.connects[position-1].z,mVertexController.connects[position-1].w); //заполнение вектора позициям концов
			mMiniMap.lines.push_back(newLine); //заполнение ветора линий на миникарте
			mVertexController.lines.push_back(newLine); //заполнение вектора вершин на миникарте
		    downs=0;
		}
	}
	   

};


void TutorialApp::settings(Settings * setting){;
	setting->setWindowSize(1920,1080); //установка размера окна
}
CINDER_APP_BASIC(TutorialApp, RendererGl);
