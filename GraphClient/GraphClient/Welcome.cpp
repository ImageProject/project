//файл окна привествия

#include "Welcome.h"
#include "Text.h"
#include "cinder\ImageIo.h"
#include "cinder\app\AppBasic.h"
Welcome::Welcome(){
	login = new Text;
	password = new Text;

}

void Welcome::setLocPass(const ci::Vec2i& loc){ //установка позиции для
	login->locate=loc; //-логина
}
void Welcome::setLogPass(const ci::Vec2i& loc){ //-пароля
	password->locate=loc;
}
void Welcome::setNewButton(const std::string & name){ //новая кнопка
	button =ci::gl::Texture( ci::loadImage( name ) ); //загрузка изображения кнопки
}
