#ifndef WELCOME_H
#define WELCOME_H
#include "Vertex.h"
#include "cinder\Text.h"
#include "cinder\gl\Texture.h"
#include "cinder\app\AppBasic.h"
#include "Texto.h"
#include "User.h"
class Welcome { //создание кнопок и квадратиков для ввода данных
	public:
	Texto login; //логин
	Texto password; //пароль
	Texto newUser;//новый юзер
	Texto hi; //привествие
	Texto end_and_logIn; //вход
	void Setup(ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,std::string &,std::string &, std::string &); //заполнение векторов
	void draw(); //рисование
	void update(); //обновление
	bool isClear(); //очистка
	/*void createUser();*/
	void set_sizes(); //задание размеров
	bool new_user; //новый пользователь
Welcome();
	ci::gl::Texture button;
	void setNewButton(const std::string &);
	int isPressed(const ci::Vec2i &loc); //проверка на то, какая из кнопок нажимается
	void fill(ci::app::KeyEvent &,int &); //создание события-клавиатуры

};
#endif