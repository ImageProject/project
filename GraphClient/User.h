#ifndef USER_H
#define USER_H
#include <string>
class User{
	public:
	std::string password; //ввод пароля
	std::string login; //ввод логина
    bool New; //создание нового пользователя
	User(){
		New = false;
	};
};
#endif