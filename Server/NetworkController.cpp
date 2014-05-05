#include "NetworkController.h"
#include <string>
#include <boost\lexical_cast.hpp>
#include "zmq.hpp"
using namespace std;
int g=0;
void NetworkController::logIn(std::string* user){
	std::string login;
	std::string password;
	int current =0;
    for (int i=2;(*user)[i]!='/';++i){
		login = login + (*user)[i];
		current =i;
	}
	current =current+2;
	for (current; (*user)[current]!='/';++current){
	    password = password + (*user)[current];
	}
	User newUser = User(&login,&password);
	newUser.New = 0;
	Users.push_back(newUser);

}
void NetworkController::newUser(std::string* user){
	std::string login;
	std::string password;
	int current =0;
	for (int i=2;(*user)[i]!='/';++i){
		login = login + (*user)[i];
		current =i;
	}
	current =current+2;
	for (current; (*user)[current]!='/';++current){
		password = password + (*user)[current];
	}
	User newUser = User(&login,&password);
	newUser.New = 1;
	Users.push_back(newUser);

};
void NetworkController::receive_grapht_info(std::string & grapth){
	string id;
	string count;
	int i=0;
	for (i=1;grapth[i]!='/';++i)
		id =id + grapth[i];
	for (i=i+2;grapth[i]!='/';++i)
		count = count +grapth[i];
	int number = boost::lexical_cast<int>(count);
	for (int j=0; j<number; ++j)
		switch(grapth[i+2]){
		case 'I':
			{
				Vertex newVertex;
				newVertex.type =0;
				newVertex.adjective_matrix = new bool[number];
				int f=0;
				for (int k=i+2;grapth[k]!='/';++k){
					if (grapth[k]=='0')
						newVertex.adjective_matrix[f]=0;
					else
						newVertex.adjective_matrix[f]=1;
					++f;
				}
				++i;
                Vertexes.push_back(newVertex);
				bool newchar[3];
				for (int i=0; i<3; ++i)
				newchar[i]=newVertex.adjective_matrix[i];
				int a= 9;
				break;
			}
		case 'N':
			{
				Vertex newVertex;
				newVertex.type =-1;
				i=i+number+1;
				break;
			}
		case 'F':
			{
				std::string type_str;
				for (int l=i+2; grapth[l]!='/';++l)
				   type_str = type_str+grapth[l];
				Vertex newVertex;
				newVertex.type =boost::lexical_cast<int>(type_str);
				newVertex.adjective_matrix = new bool[number];
				int f=0;
				for (int k =i+2;grapth[k]!='/';++k){
					if (grapth[k]=='0')
						newVertex.adjective_matrix[f]=0;
					else
						newVertex.adjective_matrix[f]=1;
					++f;
				}
				++i;
				Vertexes.push_back(newVertex);
				break;
			}

	}

		
}
void NetworkController::receive_photo(){
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");
	zmq::message_t receiven;
	socket.recv(&receiven);
	g++;
	char newChar = boost::lexical_cast<char>(g);
	std::string imagename = "Image"+newChar;
	FILE * ndefile = fopen(imagename.c_str(),"wb");
	fwrite((void *)receiven.data(),1,777835, ndefile);
	std::cout<<"YEA BITCH";
	fclose(ndefile);
	int ar =9;

}
NetworkController::NetworkController(){

};