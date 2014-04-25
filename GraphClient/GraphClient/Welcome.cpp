#include "Welcome.h"
#include "Text.h"
#include "cinder\ImageIo.h"
#include "cinder\app\AppBasic.h"
Welcome::Welcome(){
	login = new Text;
	password = new Text;

}

void Welcome::setLocPass(const ci::Vec2i& loc){
	login->locate=loc;
}
void Welcome::setLogPass(const ci::Vec2i& loc){
	password->locate=loc;
}
void Welcome::setNewButton(const std::string & name){
	button =ci::gl::Texture( ci::loadImage( name ) );
}
