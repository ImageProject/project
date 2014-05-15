#include "Text.h"
#include "cinder\app\AppBasic.h"
Text::Text(){
	essence=ci::TextBox();
	locate = ci::Vec2i(0,0); //устанвливаем текс-бокс в начальную позицию
	cur_text =std::string();
}
typedef ci::app::KeyEvent key;
void Text::fill(const key &k_event){
	if ((k_event.getCode()>47 && k_event.getCode()<58)||(k_event.getCode()>96 && k_event.getCode()<123))
		char temp = k_event.getChar();
	else
		switch(k_event.getCode()){
		case key::KEY_BACKSPACE: //если нажимают пробел, то он удаляется автоматически
			if (cur_text.size()) cur_text.erase(/**/);
			break;
		case key::KEY_RIGHT: //каретка вправо двигается, то ошибка
			// 
			break;
		case key::KEY_LEFT: //аналогично для лево
			//
			break;
		default: //вывод окна предупреждения
			warning =true;
			break;
	};
