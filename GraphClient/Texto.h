#ifndef TEXT_H
#define TEXT_H
#include "Vertex.h"
#include "cinder\Text.h"
#include "cinder\app\AppBasic.h"
class Texto{ //создание класса текстбокс для его дальнейшего использования
	public:
	ci::TextBox * essence_ptr;
	~Texto();
	std::string cur_text;
	ci::Vec2i locate;
	bool warning;
	bool text_update;
	char temp;
	//Texto();
	void Setup();
	void fill(const ci::app::KeyEvent & );
};
#endif