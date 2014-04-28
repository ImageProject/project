
#include "Texto.h"
using namespace ci;
void Texto::fill(const ci::app::KeyEvent &k_event){
	if ((k_event.getCode()>47 && k_event.getCode()<58)||(k_event.getCode()>96 && k_event.getCode()<123)){
		temp = k_event.getChar();
	    cur_text = cur_text+temp;
		essence_ptr->setText(cur_text);
	}
	else{
		switch(k_event.getCode()){
		case ci::app::KeyEvent::KEY_BACKSPACE:
			if (cur_text.size()!=0) { cur_text.erase(cur_text.size()-1); text_update = true;
			break;
		case ci::app::KeyEvent::KEY_RIGHT:
		    // 
			break;
		case ci::app::KeyEvent::KEY_LEFT:
			//
			break;
	    default:
			warning =true;
			break;
	};
	}
};
};
void Texto::Setup(){
	essence_ptr = new ci::TextBox();
	essence_ptr->setFont(Font("Courier New",22));
	essence_ptr->setBackgroundColor(Color(242,1,198));
	essence_ptr->setSize(Vec2i(230,32));
	essence_ptr->setColor(ci::Color::black());
	essence_ptr->text(cur_text);
	locate = Vec2i(100,200);
	warning =false;
	temp = 0;
}
Texto::~Texto()
{
	delete essence_ptr;
}