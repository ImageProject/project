#ifndef USER_H
#define USER_H
class User{          // ������� ����� ������������
public:
	std::string id;               // 3 ���������� ���������� ����
	std::string password;
	std::string login;
	bool New;
	User(std::string* login_new,std::string* password_new){       // ������ ������������ ������ ������������ � ��� ���� ����
		New =0;
		login = *login_new;
		password = *password_new;

	};
};
#endif