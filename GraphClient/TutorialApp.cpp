
#include "VertexController.h"
#include "SmallVertex.h"
#include "Vertex.h"
#include "cinder\Cinder.h"
#include "MiniMap.h"
#include "vLine.h"
#include "cinder/CinderResources.h"
#include <algorithm>
#include "cinder\app\AppBasic.h"
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "cinder\app\FileDropEvent.h"
#include "cinder/ImageIo.h"
#include "Output.h"
#include "OutputController.h"
#include "Welcome.h"
#pragma comment(lib, "opencv_highgui245d.lib")
using namespace ci;
using namespace ci::app;
bool next = false;

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
	if (next){
	if (updates){
		mVertexController.update(mVertexController.updateSpeed,mVertexController.direction);
	updates = false;}
	}
	else 
	mWelcome.update();
};
void TutorialApp::draw(){
	if (next) {
	gl::clear(Color(242,221,198));
    mVertexController.draw();
	} else {
	gl::clear(Color(242,221,198));
	mWelcome.draw();
	}
}
void TutorialApp::keyDown(KeyEvent k_event){
	if (next) {
	enum direction{up=1,down,left,right};
	switch(k_event.getCode()){
		if(!stop){
			if(changeVertex){
			case KeyEvent::KEY_1:
				mVertexController.Vertexes[changeVertex-1].name.setText("1");
				break;
			case KeyEvent::KEY_2:
				mVertexController.Vertexes[changeVertex-1].name.setText("2");
				break;
			case KeyEvent::KEY_3:
				mVertexController.Vertexes[changeVertex-1].name.setText("3");
				break;
			case KeyEvent::KEY_4:
				mVertexController.Vertexes[changeVertex-1].name.setText("4");
				break;
			case KeyEvent::KEY_5:
				mVertexController.Vertexes[changeVertex-1].name.setText("5");
				break;
			case KeyEvent::KEY_6:
				mVertexController.Vertexes[changeVertex-1].name.setText("6");
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
			stop = true;
			mOutputController = OutputController();
			for (std::vector<Vertex>::iterator p =mVertexController.Vertexes.begin();p!=mVertexController.Vertexes.end();++p)
			{
				Output newOutput = Output();
				newOutput.type=p->type;
				newOutput.filterId = p->filter;
				mOutputController.vertexes.push_back(newOutput);
			}
//				 // Создаём динамический массив:
//			mOutputController.adjencive_matrix= new bool *[mVertexController.Vertexes.size()];  // int - тип элементов матрицы, **matrix - указатель на указатель
//                                  // new - ключевое слово, которое выделяет память в куче под x элементов типа int
// 
//      for (int i=0; i<mVertexController.Vertexes.size(); i++)
//         mOutputController.adjencive_matrix[i] = new  bool[mVertexController.Vertexes.size()];   // для каждого элемента динамического массива matrix создаём ещё по 'y' элементов типа int
//      // в итоге имеем двумерный динамический массив, аля матрица
// // запускаем цикл, который будет заполнять элементы матрицы рандомно
//      for (int i=0; i<mVertexController.Vertexes.size(); i++)
//         for (int j=0; j<mVertexController.Vertexes.size(); j++)
//             mOutputController.adjencive_matrix[i][j] = 0; //обнуление матрицы
//for (std::vector<Vec4i>::iterator p =mVertexController.connects.begin();p !=mVertexController.connects.end();++p)
//	if (p->x||p->y) {
//		mOutputController.adjencive_matrix[p->x][p->y]=1;
//		mOutputController.adjencive_matrix[p->y][p->x]=1;
//	}

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

}
void TutorialApp::fileDrop(FileDropEvent drop){
	for(size_t i=0; i<drop.getNumFiles();++i){
			Vertex imageVertex = Vertex((Vec2i(drop.getPos().x, drop.getPos().y)));
		    imageVertex.path = drop.getFiles()[i];
			imageVertex.image=gl::Texture(loadImage(ci::loadFile(imageVertex.path)));
			imageVertex.isImage= true;
			int max = imageVertex.image.getHeight()>imageVertex.image.getWidth()?imageVertex.image.getHeight():
				imageVertex.image.getWidth();
			int scale = max/(imageVertex.vRadius/sqrtf(2));
				IplImage* temp = cvLoadImage(imageVertex.path.string().c_str());
			IplImage* image2 = cvCreateImage(cvSize(temp->width/scale,temp->height/scale),temp->depth,temp->nChannels);
            cvResize(temp,image2);
			cvSaveImage("iamgeolo.jpg",image2);
			imageVertex.reImage = ci::loadImage("iamgeolo.jpg");
			mVertexController.Vertexes.push_back(imageVertex);
			mVertexController.mMiniMap.push_vertex(imageVertex);

		}
	};


void TutorialApp::mouseDown(MouseEvent m_event){
	if (next)  {
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
			mOutputController.adjencive_matrix[mVertexController.connects[position].x][mVertexController.connects[position-1].x]=1;
			mOutputController.adjencive_matrix[mVertexController.connects[position-1].x][mVertexController.connects[position].x]=1; 
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
			mWelcome.new_user=true;
			mWelcome.createUser();
			next = true;
			break;
					  }
		case LogIn:{
			mWelcome.new_user=false;
			mWelcome.createUser();
			next = true;
			break;
				   }
		}
}
}
void TutorialApp::settings(Settings * setting){;
	setting->setWindowSize(1920,1080);
};
CINDER_APP_BASIC(TutorialApp,RendererGl);