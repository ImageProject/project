#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H
#include <string>
#include "UserUser.h"
#include <vector>
#include "Vertex.h"

class NetworkController{
public:
	void newUser(std::string*);
	void logIn(std::string*);
	void receive_photo();
	void receive();
	void receive_grapht_info(std::string&);
	/*void receive_photos(std::string*);*/
	NetworkController();
	std::vector<User> Users;
	std::vector<Vertex> Vertexes;
};
#endif