#ifndef USER_H
#define USER_H
#include <string>
class User{
	public:
	std::string password;
	std::string login;
    bool New;
	User(){
		New = false;
	};
};
#endif