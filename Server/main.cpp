#include "NetworkController.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
#include <fstream>
#include <cstdio>
#include <iostream>
#include "UserUser.h"
#include "Database.h"

#pragma comment(lib,"libzmq_d.lib")
void NetworkController::receive(){
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
	socket.bind ("tcp://*:5555");
    while (true) {

        //  Wait for next request from client
       /*current =  s_recvf(socket);*/
		zmq::message_t receiven;
		std::string current = s_recv(socket);
		switch(current[0]){
		case 'G':
			{
				this->receive_grapht_info(current);
				break;
			};
		case 'I':{
			/*this->receive_photos(&current);*/
			break;
		}
		case '1':
		{
			this->newUser(&current);
			break;
		}
		case '0':
		{
			this->logIn(&current);
			break;
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