#include "Welcome.h"
#include "Texto.h"
#include "cinder\ImageIo.h"
#include "cinder\app\AppBasic.h"
#include "User.h"
#include "NetworkController.h"
using namespace ci;
using namespace std;
void Welcome::Setup(Vec2i &loc_log,Vec2i &loc_pass,Vec2i &loc_hi,Vec2i &loc_newUser,Vec2i &loc_end_and_logIn,string & str_newUser,string & str_hi, string & str_log_in){
	login.Setup();// = Texto();
	password.Setup();// = Texto();
	hi.Setup();
	newUser.Setup();
	end_and_logIn.Setup();
	login.locate = loc_log;
	newUser.cur_text = str_newUser;
	hi.cur_text = str_hi;
	password.locate = loc_pass;
	newUser.locate = loc_newUser;
	hi.locate = loc_hi;
	end_and_logIn.locate = loc_end_and_logIn;
	end_and_logIn.cur_text = str_log_in;
	end_and_logIn.essence_ptr->setText(end_and_logIn.cur_text);
	hi.essence_ptr->setText(hi.cur_text);
	newUser.essence_ptr->setText(newUser.cur_text);


}
Welcome::Welcome(){
	new_user = false;
}
bool Welcome::isClear(){
	if ((login.cur_text.size())&&(password.cur_text.size()))
		return true;
	return false;
}
void Welcome::set_sizes(){
	hi.essence_ptr->setSize(Vec2i(200,200));
	end_and_logIn.essence_ptr->setSize(Vec2i(60,60));
	newUser.essence_ptr->setSize(Vec2i(60,60));

}
void Welcome::setNewButton(const std::string & name){
	button =ci::gl::Texture( ci::loadImage( name ) );
}
void Welcome::update(){
	gl::draw(login.essence_ptr->render(),login.locate);
	gl::draw(password.essence_ptr->render(),password.locate);
};
void Welcome::draw(){

	gl::draw(login.essence_ptr->render(),login.locate);
	gl::draw(password.essence_ptr->render(),password.locate);
	gl::draw(end_and_logIn.essence_ptr->render(),end_and_logIn.locate);
	gl::draw(hi.essence_ptr->render(),hi.locate);
	gl::draw(newUser.essence_ptr->render(),newUser.locate);



};
int Welcome::isPressed(const ci::Vec2i &loc){
	if ((loc.x>login.locate.x)&&(loc.x<login.locate.x+login.essence_ptr->getSize().x)&&(loc.y<login.locate.y+login.essence_ptr->getSize().y)&&(loc.y>login.locate.y))
		return 1;
	if ((loc.x>password.locate.x)&&(loc.x<password.locate.x+password.essence_ptr->getSize().x)&&(loc.y<password.locate.y+password.essence_ptr->getSize().y)&&(loc.y>password.locate.y))
		return 2;
	if ((loc.x>newUser.locate.x)&&(loc.x<newUser.locate.x+newUser.essence_ptr->getSize().x)&&(loc.y<newUser.locate.y+newUser.essence_ptr->getSize().y)&&(loc.y>newUser.locate.y))
        return 3;
	if ((loc.x>end_and_logIn.locate.x)&&(loc.x<end_and_logIn.locate.x+end_and_logIn.essence_ptr->getSize().x)&&(loc.y<end_and_logIn.locate.y+end_and_logIn.essence_ptr->getSize().y)&&(loc.y>end_and_logIn.locate.y))
		return 4;
	
	return 0;
}
void Welcome::fill(ci::app::KeyEvent & k_event, int &parameter){
	switch(parameter){
	case 0:
		break;
	case 1:
		login.fill(k_event);
		break;
	case 2:
		password.fill(k_event);
		break;
	case 3:
		//
	case 4:
		//
		break;

	}
	

}
