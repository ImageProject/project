#include "NetworkController.h"
#include "zmq.hpp"
#include "zhelpers.hpp"
#include <fstream>
#include <iostream>
#include "boost/archive/xml_oarchive.hpp"
#include "boost/archive/xml_iarchive.hpp"
#include "UserUser.h"
void NetworkController::receive(){
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5556");

    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
       current =  s_recvf(socket);

		std::cout<<"Yeaa,bitch! I have the user! Time to get money!";
		switch(current[0]){
		case '0':
			this->logIn();
			break;
		case '1':
			this->newUser();
			break;
		case 'G':
			/*this->*/;
		}
		
			/*	Users newUser = Users();
			request >> BOOST_SERIALIZATION_NVP(newUser);*/
#ifndef _WIN32
        sleep(1);
#else
    Sleep (1);
#endif

        //  Send reply back to client
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "I Got IT!", 5);
        socket.send (reply);
    }
}
bool NetworkController::newUser(){
	return 0;
}
bool NetworkController::logIn(){
	return 0;
};
NetworkController::NetworkController(){

}


int main(){
	NetworkController mNetworkController = NetworkController();
	mNetworkController.receive();
	return 0;
}