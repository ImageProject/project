#include "VertexController.h"
#include "SmallVertex.h"
#include "Vertex.h"
#include "cinder\Cinder.h"
#include "MiniMap.h"
#include "vLine.h"
#include "cinder\app\AppBasic.h"
using namespace ci;
using namespace ci::app;
class TutorialApp: public AppBasic{
	bool updates;
	void setup();
	void update();
	void draw();
	void mouseDown(MouseEvent);
	void keyDown(KeyEvent);
	void settings(Settings * setting);
	short downs;
	VertexController mVertexController;
	MiniMap          mMiniMap;
};
void TutorialApp::setup(){
	updates =0;
	downs =0;
	mVertexController.mMiniMap=MiniMap();                    //warning,crutches!
	mVertexController.mMiniMap.scale=4;
	mVertexController.mMiniMap.position=1;
	mVertexController.mMiniMap.resolution=Vec2i(1920,1080);
	mVertexController.mMiniMap.getCenter();
	mVertexController.updateSpeed=3;
	gl::lineWidth(2.5f);

	
};

void TutorialApp::update(){
	if (updates){
		mVertexController.update(mVertexController.updateSpeed,mVertexController.direction);
	updates = false;}

};
void TutorialApp::draw(){
	gl::clear(Color(242,221,198));
    mVertexController.draw();


}
void TutorialApp::keyDown(KeyEvent k_event){
	switch(k_event.getCode()){
	case KeyEvent::KEY_s:
		{
		mVertexController.direction=1;
		updates=true;
		break;
		}
	case KeyEvent::KEY_w:
		{
			mVertexController.direction =2;
		    updates=true;
			break;
		}
	case KeyEvent::KEY_a:
			{
				mVertexController.direction=3;
				updates=true;
				break;
			}
	case KeyEvent::KEY_d:
			{
				mVertexController.direction=4;
				updates = true;
				break;
			}
		default: 
			updates =false;
	}
}


void TutorialApp::mouseDown(MouseEvent m_event){
	if (m_event.isLeftDown())
	{         //warning,crutch!
		mVertexController.addVertexes(m_event.getPos());
	}
	


	if (m_event.isRightDown()){
		Vec4i connect = mVertexController.isConnect(m_event.getPos());
		if (connect!=Vec4i(0,0,0,0))
		{
			++downs;
			mVertexController.connects.push_back(connect);
		}
		if (downs==2){
			int position =mVertexController.connects.size()-1;
			vLine newLine;
			newLine.start = Vec2i(mVertexController.connects[position].z,mVertexController.connects[position].w);
			newLine.finish =Vec2i(mVertexController.connects[position-1].z,mVertexController.connects[position-1].w);
			mMiniMap.push_line(newLine);
			mVertexController.lines.push_back(newLine);
		    downs=0;
		}
		if (mVertexController.isTextBox(m_event.getPos())){
			exit(0);
		}

	}
};


void TutorialApp::settings(Settings * setting){;
	setting->setWindowSize(1920,1080);
}
CINDER_APP_BASIC(TutorialApp, RendererGl);
