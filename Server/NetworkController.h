#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
#include <string>
#include "UserUser.h"
#include <vector>
#include "Vertex.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
extern zmq::socket_t sockett;
extern zmq::message_t receiven;
class NetworkController{
public:
	void newUser(std::string*);
	void logIn(std::string*);
	void receive_photos(int & count,std::string & user_id, std::vector<int> & id_photos);
	void receive();
	void receive_grapht_info(std::string&);
	/*void receive_photos(std::string*);*/
	NetworkController();
	std::vector<User> Users;
	std::vector<Vertex> Vertexes;
};

#endif