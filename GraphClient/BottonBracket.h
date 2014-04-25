#include "cinder/app/AppBasic.h"
#include "cinder\Cinder.h"
enum direction{left,right};
class BottonBracket{
	ci::Vec2i locate;
	ci::Color color;
	void Transfer(const direction &);
	void setColor(const ci::Color &);
	void setLocate(const ci::Vec2i &);
