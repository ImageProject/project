#include "Vertex.h"
#include "cinder\Text.h"
#include "cinder\app\AppBasic.h"
class Text{
public:
	ci::TextBox essence;
	std::string cur_text;
	ci::Vec2i locate;
	bool warning;
	Text();
	void fill(const ci::app::KeyEvent & );
};