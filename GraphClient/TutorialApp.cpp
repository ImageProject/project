
#include "VertexController.h"
#include "SmallVertex.h"
#include "Vertex.h"
#include "cinder\Cinder.h"
#include "MiniMap.h"
#include "User.h"
#include "vLine.h"
#include "cinder/CinderResources.h"
#include <algorithm>
#include "cinder\app\AppBasic.h"
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "boost/filesystem/operations.hpp" // includes boost/filesystem/path.hpp
#include "boost/filesystem/fstream.hpp"    // ditto
#include "cinder\app\FileDropEvent.h"
#include "cinder/ImageIo.h"
#include "Output.h"
#include "OutputController.h"
#include "Welcome.h"
#include <fstream>
#include <string>
#include "NetworkController.h"
#include "boost/filesystem/path.hpp"
#pragma comment(lib, "opencv_highgui245d.lib")
using namespace ci;
using namespace ci::app;
std::vector<boost::filesystem::path> paths;
bool next_form = 1;

class TutorialApp: public AppBasic{
	void setup();
	void update();
	void draw();
	void mouseDown(MouseEvent);
	void keyDown(KeyEvent);
	void fileDrop(FileDropEvent);
	void settings(Settings * setting);
	short downs;
	bool stop;
	int changeVertex;
	Welcome mWelcome;
	int change;
	bool updates;
	VertexController mVertexController;
	OutputController mOutputController;
	NetworkController mNetworkController;
};
void TutorialApp::setup(){
	updates =0;
	downs =0;
	mNetworkController =  NetworkController();
	mVertexController.mMiniMap=MiniMap();                    //warning,crutches!
	mVertexController.mMiniMap.scale=4;
	mVertexController.mMiniMap.position=1;
	mVertexController.mMiniMap.resolution=Vec2i(1920,1080);
	mVertexController.mMiniMap.getCenter();
	mVertexController.updateSpeed=3;
	gl::lineWidth(2.5f);
	stop = false;
	changeVertex = false;
change = 0;
Vec2i locate_pass = Vec2i(960,540);
Vec2i locate_login = Vec2i(960,450);
Vec2i locate_hi = Vec2i(960,100);
Vec2i locate_newUser = Vec2i(100,900);
Vec2i locate_end_and_logIn = Vec2i(1600, 900);
std::string new_user = "New User";
std::string hi = "Hi! Chose registration or log in!)";
std::string log_in = "LogIn";
mWelcome.Setup(locate_login, locate_pass,locate_hi,locate_newUser,locate_end_and_logIn,new_user, hi,log_in);
mWelcome.set_sizes();
mWelcome.button= gl::Texture(loadImage("button.jpg"));
//mWelcome.setLocPass(Vec2i(1920-50,1080 -50));
//mWelcome.setLogPass(Vec2i(1920-50,1080 +50));
	
};

void TutorialApp::update(){
	if (next_form){
	if (updates){
		mVertexController.update(mVertexController.updateSpeed,mVertexController.direction);
	    updates = false;}
	}
	else 
	mWelcome.update();
};
void TutorialApp::draw(){
	if (next_form) {
	gl::clear(Color(242,221,198));
    mVertexController.draw();
	} else {
	gl::clear(Color(242,221,198));
	mWelcome.draw();
	}
}
void TutorialApp::keyDown(KeyEvent k_event){
	if (next_form) {
	enum direction{up=1,down,left,right};
	switch(k_event.getCode()){
		if(!stop){
			if(changeVertex){
			case KeyEvent::KEY_1:
				mVertexController.Vertexes[changeVertex-1].type=1;
				updates=true;
				break;
			case KeyEvent::KEY_2:
				mVertexController.Vertexes[changeVertex-1].type=2;
				updates=true;
				break;
			case KeyEvent::KEY_3:
				mVertexController.Vertexes[changeVertex-1].type=3;
				updates=true;
				break;
			case KeyEvent::KEY_4:
				mVertexController.Vertexes[changeVertex-1].type=4;
				updates=true;
				break;
			case KeyEvent::KEY_5:
				mVertexController.Vertexes[changeVertex-1].type=5;
				updates=true;
				break;
			case KeyEvent::KEY_6:
				mVertexController.Vertexes[changeVertex-1].type=6;
				updates=true;
				break;

			}

	case KeyEvent::KEY_w:
		{
		mVertexController.direction=up;
		updates=true;
		break;
		}
	case KeyEvent::KEY_s:
		{
			mVertexController.direction =down;
		    updates=true;
			break;
		}
	case KeyEvent::KEY_a:
			{
				mVertexController.direction=left;
				updates=true;
				break;
			}
	case KeyEvent::KEY_d:
			{
				mVertexController.direction=right;
				updates = true;
				break;
			}
	case KeyEvent::KEY_BACKSPACE:
		{
			mVertexController.Vertexes.pop_back();
			mVertexController.mMiniMap.objects.pop_back();
		}
	case KeyEvent::KEY_SPACE:
		{
			const int IMAGE =0 ;
			stop = true;
			OutputController mOutputController = OutputController();
			for (std::vector<Vertex>::iterator p =mVertexController.Vertexes.begin();p!=mVertexController.Vertexes.end();++p)
			{
				Output newOutput = Output();
				newOutput.type=&p->type;
				newOutput.id = p-mVertexController.Vertexes.begin();
				p->connections[p-mVertexController.Vertexes.begin()]=1;
				for (int i =0; i<mVertexController.Vertexes.size(); ++i)
				newOutput.connections[i] = p->connections[i];

				if (p->type == IMAGE)
				newOutput.image = &p->path;
				mOutputController.vertexes.push_back(newOutput);
			}
	        std::string newstr = mOutputController.inString();
			mNetworkController.grapth = newstr;
			if(mNetworkController.send_strings())
			{
			}else
			mNetworkController.send_image();
		}
		default: 
			updates =false;

		} else {// тут будет пересылка отправка 
		}
	}         /// тут надо исправить неболльшой баг, ибо отправляться все будет только после нажатия левых кнопок. Ну и лан
	}
	else {
		enum changes{login=1,password,newUser,endAndLogIn};
		switch(change){
		case login:
		case password:
			mWelcome.fill(k_event,change);
		    break;
		}
	}
};

void TutorialApp::fileDrop(FileDropEvent drop){
	for(size_t i=0; i<drop.getNumFiles();++i){
			Vertex imageVertex = Vertex((Vec2i(drop.getPos().x, drop.getPos().y)));
		    imageVertex.path = drop.getFiles()[i];
			paths.push_back(imageVertex.path);
			gl::Texture image=gl::Texture(loadImage(ci::loadFile(imageVertex.path)));
			imageVertex.isImage= true;
			int max = image.getHeight()>image.getWidth()?image.getHeight():
				image.getWidth();
			int scale = max/40;
				IplImage* temp = cvLoadImage(imageVertex.path.string().c_str());
			IplImage* image2 = cvCreateImage(cvSize(temp->width/scale,temp->height/scale),temp->depth,temp->nChannels);
            cvResize(temp,image2);
			cvSaveImage("iamgeolo.jpg",image2);
			imageVertex.reImage = ci::loadImage("iamgeolo.jpg");
			mVertexController.Vertexes.push_back(imageVertex);
			mVertexController.mMiniMap.push_vertex(imageVertex);

		}
	};
//void TutorialApp::mouseMove(MouseEvent m_event){
//	if(next_form){
//		if (mVertexController.isTextBox(m_event.getPos()))          /// это определяет, нажатие на вершину или нет
//	/*		m_event.*/         // тут должна быть логика перемещения элемента
//	}
//}


void TutorialApp::mouseDown(MouseEvent m_event){
	if (next_form)  {
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
			mVertexController.mMiniMap.push_line(newLine);
			mVertexController.lines.push_back(newLine);
			//заполнение матрицы смежности
			mVertexController.Vertexes[mVertexController.connects[position].x].connections[mVertexController.connects[position-1].x]=1;
			mVertexController.Vertexes[mVertexController.connects[position-1].x].connections[mVertexController.connects[position].x]=1;
			downs=0;
		}
		if (size_t number = mVertexController.isTextBox(m_event.getPos())){
			mVertexController.Vertexes[number].vColor=Color(1,0.6,34);
			changeVertex = number+1;
			
		}
		}
} else 
	{
        if (m_event.isLeftDown()){
			change  = mWelcome.isPressed(m_event.getPos());
		}
		enum MouseDown{NewUser=3,LogIn=4};
		switch(change){
		case NewUser: {
			User newestUser = User();
			newestUser.New = true;
			newestUser.login = mWelcome.login.cur_text;
			newestUser.password = mWelcome.password.cur_text;

			mNetworkController.setUser(&newestUser);
			if(mNetworkController.send_strings())
			next_form = true;
			else   {}                                                 ///////////////
			break;
					  }
		case LogIn:{
			User newestUser = User();
			newestUser.New = false;
			newestUser.login = mWelcome.login.cur_text;
			newestUser.password = mWelcome.password.cur_text;
			mNetworkController.setUser(&newestUser);
            if(mNetworkController.send_strings())
			next_form = true;
			else    {}                                               ////////////////
				   }
		}
}
}
void TutorialApp::settings(Settings * setting){;
	setting->setWindowSize(1920,1080);
};
CINDER_APP_BASIC(TutorialApp,RendererGl);