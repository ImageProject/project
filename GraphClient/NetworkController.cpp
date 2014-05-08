#include "NetworkController.h"
#include "zmq_for_WinApi.hpp"
#include "zhelpers.hpp"
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "boost/lexical_cast.hpp"
#include <cstdio>

extern std::vector<boost::filesystem::path> paths;
//std::string NetworkController::receive(){
//
//// 	zmq::context_t context (1);
//// 	zmq::socket_t socket (context, ZMQ_REP);
//// 	socket.bind ("tcp://*:5555");
//// 	return s_recv(socket);
//}
bool NetworkController::send_strings(){
	std::string str;
	boost::timer too;
	requester->connect("tcp://localhost:5555");
	bool stete = requester->connected();
	while(!requester->connected()){
		if (too.elapsed()<30){
			Sleep(2);
			requester->connect("tcp://localhost:5555");
		} else{ fail=true; }                                                                            //////////////////////////
	}
	if (!grapth.size()){
	char temp = '/';
	char buffer[2];
	char * temp_state = itoa(New,buffer,10);
	string newresult;
    newresult =newresult+*temp_state+temp+one+temp+two+temp;
	s_send(*requester,newresult);
	/*this->receive();*/
	}
	else {
	grapth = "G"+id+"/"+grapth;
	s_send(*requester,grapth);
	}
	//if (this->receive().c_str()=="1"){
	//	return true;                                                                        ///////////////
	//}
	return 1;
};

bool NetworkController::send_image(){
	
	requester->connect("tcp://localhost:5555");
	bool stete = requester->connected();
	boost::timer too;
	while(!requester->connected()){
		if (too.elapsed()<30){
			Sleep(2);
			requester->connect("tcp://localhost:5555");                                         //////////////////
		};
		
	};
	for (int i=0;i<paths.size();++i){
		FILE * pFile = fopen(paths[i].string().c_str(),"rb");
		if (pFile!=NULL){
		fseek( pFile, 0, SEEK_END );
		int Size = ftell( pFile );
		rewind(pFile);                         // ÊÀÆÄÀß ÑÒÐÎ×ÊÀ ÂÛÑÒÐÀÄÀÍÀ"!!!!!!!!
		zmq::message_t messagee(Size);
		fread((void*)messagee.data(),1,Size,pFile);
		requester->send(messagee);         
		fclose(pFile);
		}
	}
	return true;

}
NetworkController::NetworkController(){
	New=false;
	state = 0;
	this->prepare();
}
void NetworkController::setUser(User * newUser){
	this->one = newUser->login;
	this->two = newUser->password;
	this->New = newUser->New;
	
}
bool NetworkController::receive_result(){
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind ("tcp://*:5555");
		zmq::message_t receiven;
		int a = socket.recv(&receiven);
		FILE * ndefile = fopen("Receive.jpg","wb");
		fwrite((void *)receiven.data(),1,777835, ndefile);
		std::cout<<"YEA BITCH";
		fclose(ndefile);
		return true;
}
void NetworkController::prepare(){
	zmq::context_t context(1);
zmq::socket_t ptr_requester(context, ZMQ_REQ);
requester = &ptr_requester;
}