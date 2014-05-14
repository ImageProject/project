#ifndef USER_H
#define USER_H
class User{          // Создаем класс Пользователь
public:
	std::string id;               // 3 Переменных строкового типа
	std::string password;
	std::string login;
	bool New;
	User(std::string* login_new,std::string* password_new){       // Фунция связвывающая пароль пользователя и его юзер нэйм
		New =0;
		login = *login_new;
		password = *password_new;

	};
};
#endif