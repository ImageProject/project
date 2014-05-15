#include "NetworkController.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
#include <fstream>              // Поключаем кучу библиотек и файлов
#include <cstdio>
#include <iostream>
#include "UserUser.h"
#include "Database.h"
zmq::context_t context (1);
zmq::socket_t sockett (context, ZMQ_REP);
#pragma comment(lib,"libzmq_d.lib")
#pragma comment(lib,"libmongoclient.lib")
bool status =0;
std::string okay = "Ok";
std::string fail = "!";
void NetworkController::receive(){  // Реализуем фунции получения из  NetworkController.h
	
	
	
	//Начинаем цикл
	
    while (true) {                                    //Пока истина 
		zmq::context_t context (1);
		zmq::socket_t sockett (context, ZMQ_REP);
		sockett.bind ("tcp://*:5555");
		std::string current = s_recv(sockett);

		switch(current[0]){
		case 'G':
			{
				if(this->receive_graph_info(current)){       

					std::cout<<"Grapth is!"; // вывели на экран Grapth is!
				}
				else 
				this->send_request(fail); // Отправлем сообщение "Неудача"
				break;
			};
		//case 'I':{
		//	/*this->receive_photos(&current);*/
		//	break;
		/*}*/
		case '1':
		{
			if(this->newUser(&current)){
				this->send_request(okay); // Отправлем сообщение "Неудача"
				std::cout<<"New user is!"; // "Новый пользователь зарегистрирован"
			}
			else 
			    this->send_request(fail);     // Отправлем сообщение "Неудача"

			break;
		}
		case '0':
		{
			if(this->logIn(&current)){
				this->send_request(okay)            // Отправлем сообщение "Все в норме"
			std::cout<<"log in is!";               // "Вывошли"			}
			else 
			this->send_request(fail);          // Отправлем сообщение "Неудача"
		}
		}
// 		int a = socket.recv(&receiven);
// 		FILE * ndefile = fopen("Receive2.jpg","wb");
// 		fwrite((void *)receiven.data(),1,777835, ndefile);
// 		std::cout<<"YEA BITCH";
// 		fclose(ndefile);
// 		int ar =9;

		/*	Sleep(0.002);
		std::string OtherStringToParse =s_recv(socket);
		std::cout<<OtherStringToParse;



		std::cout<<"Yeaa,bitch! I have the user! Time to get money!";*/
			/*	Users newUser = Users();
			request >> BOOST_SERIALIZATION_NVP(newUser);*/
#ifndef _WIN32
        sleep(0.0002);
#else
    Sleep (0.00003);
#endif
    }
}


int main(){
	NetworkController mNetworkController = NetworkController();
	mNetworkController.receive();



	return 0;
}