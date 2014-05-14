#ifndef DATABASE_H
#define DATABASE_H
class Database{            // Создаем класс
public:                       // Публичные поля классас с 3 функциями
	void run();               
	void addUser();           // Добавление пользователя
	void searchUser();         // Поиск существующего пользователя
};
#endif