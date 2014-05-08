#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
#include <string>
#include "UserUser.h"
#include <vector>
#include "Vertex.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
extern zmq::socket_t sockett;
class NetworkController{
public:
	bool newUser(std::string*);
	bool logIn(std::string*);
	void receive_photos(int & count,std::string & user_id, std::vector<int> & id_photos);
	void receive();
bool  receive_graph_info(std::string &);
	bool send_request(std::string &request);
	/*void receive_photos(std::string*);*/
	NetworkController();
	std::vector<User> Users;
	std::vector<Vertex> Vertexes;
};

#endif