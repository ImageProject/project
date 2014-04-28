#ifndef WELCOME_H
#define WELCOME_H
#include "Vertex.h"
#include "cinder\Text.h"
#include "cinder\gl\Texture.h"
#include "cinder\app\AppBasic.h"
#include "Texto.h"
#include "User.h"
class Welcome {
	public:
	Texto login;
	Texto password;
	Texto newUser;
	Texto hi;
	Texto end_and_logIn;
	void Setup(ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,ci::Vec2i &,std::string &,std::string &, std::string &);
	void draw();
	void update();
	bool isClear();
	void createUser();
	void set_sizes();
	bool new_user;
Welcome();
	ci::gl::Texture button;
	void setNewButton(const std::string &);
	int isPressed(const ci::Vec2i &loc);
	void fill(ci::app::KeyEvent &,int &);

};
#endif