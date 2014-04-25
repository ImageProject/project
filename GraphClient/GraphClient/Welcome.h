#include "Vertex.h"
#include "cinder\Text.h"
#include "cinder\gl\Texture.h"
#include "cinder\app\AppBasic.h"
#include "Text.h"
class Welcome {
	Text* login;
	Text* password;
	Welcome();
	void draw();
	void setLocPass(const ci::Vec2i &);
	void setLogPass(const ci::Vec2i&);
	ci::gl::Texture button;
	void setNewButton(const std::string &)


};