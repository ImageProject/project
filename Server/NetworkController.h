#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
#include <string>
#include "UserUser.h"   // Подключаем библиотечки
#include <vector>        
#include "Vertex.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
extern zmq::socket_t sockett;
class NetworkController{                        // Создаем класс
public:
	bool newUser(std::string*);                 // пара булевых функций
	bool logIn(std::string*);
	void receive_photos(int & count,std::string & user_id, std::vector<int> & id_photos);  // фунцкия возвращающая 
	void receive(); // фунцкия возвращающая
bool  receive_graph_info(std::string &);  
	bool send_request(std::string &request);
	/*void receive_photos(std::string*);*/
	NetworkController();
	std::vector<User> Users; // Запиливаем вектор 
	std::vector<Vertex> Vertexes;
};

#endif