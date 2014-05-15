#include "NetworkController.h"
#include <string>
#include <boost\lexical_cast.hpp>
#include "zmq.hpp"
using namespace std;
int g=0;

bool NetworkController::logIn(std::string* user){ //Реализация функции  NetworkController 
	std::string login;                            //Вход пользователя 
	std::string password;                         // 2 Переменных строкового типа
	int current =0;                                // Устанавливаем текущее значение 0
    for (int i=2;(*user)[i]!='/';++i){
		login = login + (*user)[i];
		current =i;
	}
	current =current+2;
	for (current; (*user)[current]!='/';++current){
	    password = password + (*user)[current];
	}
	User newUser = User(&login,&password);                        //Заносим данные нового пользователя
	newUser.New = 0;                                             // В базу данных
	Users.push_back(newUser);                                    // Заполняем массив пользователей
	return true;
}
bool NetworkController::newUser(std::string* user){
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
	return true;

};
bool NetworkController::receive_graph_info(std::string & grapth){ //Реализация функции  NetworkController 
	                                                              //Получения информации о графе от клиента 
	string id;
	string count;
	int i=1;
	for (i;grapth[i]!='/';++i)
		id =id + grapth[i];
	i=i+1;
	for (i;grapth[i]!=' ';++i)
		count = count +grapth[i];
	int number = boost::lexical_cast<int>(count);
	i=i+1;
	std::vector<int> id_photos;
	for (int j=0; j<number; ++j){
	
		
		switch(grapth[i]){
		case '0':
			{
				int k=i+2;
				Vertex newVertex;
				newVertex.type =0;
				newVertex.adjective_matrix = new bool[number];
				int f=0;
				for (k;grapth[k]!=' ';++k){
					if (grapth[k]=='0')
						newVertex.adjective_matrix[f]=0;
					else
						newVertex.adjective_matrix[f]=1;
					++f;
				}
                Vertexes.push_back(newVertex);
				id_photos.push_back(j);
				break;
			}
		case 'N':
			{
				
				break;
			}
		case '1': case '2':case '3' :case '4':case '5': case '6':
			{
				Vertex newVertex;
				newVertex.type =boost::lexical_cast<int>(grapth[i]);
				newVertex.adjective_matrix = new bool[number];
				int f=0;
				for (int k =i+2;grapth[k]!='/';++k){
					if (grapth[k]=='0')
						newVertex.adjective_matrix[f]=0;
					else
						newVertex.adjective_matrix[f]=1;
					++f;
				}
				Vertexes.push_back(newVertex);
				break;
			}

	}

		i=i+number+3;

}
	this->receive_photos(number,id,id_photos);
	return true;
}
void NetworkController::receive_photos(int & count,std::string & user_id,std::vector<int> & id_photos){ //Реализация функции  NetworkController 
	int i=0;                                                                                           // Получения изображений от клиента 
	std::string bind="tcp://*:510";
	for (vector<int>::iterator p = id_photos.begin();p!=id_photos.end();++p){
	zmq::context_t context (1);
	zmq::message_t file;
	zmq::socket_t socket_image (context, ZMQ_REP);
	bind[10]=boost::lexical_cast<char>(i);
	socket_image.bind (bind.c_str());
	socket_image.recv(&file);//Реализация функции  NetworkController 
	std::string imagename = "Image_"+user_id+"_" + boost::lexical_cast<char>(*p)+".jpg";
	FILE * ndefile = fopen(imagename.c_str(),"wb");
	fwrite((void *)file.data(),1,file.size(), ndefile);
	std::cout<<"YEA BITCH";
	int a = ftell(ndefile);
	fclose(ndefile);
	++i;
	}

}
bool NetworkController::send_request(std::string & request){ // 
	zmq::context_t context(1);
	zmq::socket_t requester(context, ZMQ_REQ);
	std::string str;
	requester.connect("tcp://localhost:5556");
	s_send(requester,request);
	return true;
}
NetworkController::NetworkController(){

};