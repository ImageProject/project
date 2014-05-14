#include "NetworkController.h"
#include "zmq_for_WinApi.hpp"
#include "zhelpers.hpp"
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "boost/lexical_cast.hpp"
#include <cstdio>

extern std::vector<boost::filesystem::path> paths;
std::string NetworkController::receive(){

 	zmq::context_t context (1);
 	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind("tcp://*:5556");
 	return s_recv(socket);
}
bool NetworkController::send_strings(){
	zmq::context_t context(1);
	zmq::socket_t requester(context, ZMQ_REQ);
	std::string str;
	boost::timer too;
	requester.connect("tcp://localhost:5555");
	bool stete = requester.connected();
	while(!requester.connected()){
		if (too.elapsed()<30){
			Sleep(2);
			requester.connect("tcp://localhost:5555");
		} else{ fail=true; }                                                                            //////////////////////////
	}
	if (!grapth.size()){
	char temp = '/';
	char buffer[2];
	char * temp_state = itoa(New,buffer,10);
	string newresult;
    newresult =newresult+*temp_state+temp+one+temp+two+temp;
	s_send(requester,newresult);
	if (this->receive()[0]=='O')
	return true;                  
	}
	else {
	grapth = 'G'+id+"/"+grapth;
	s_send(requester,grapth);
	}
	/*if (this->receive()[0]=='O')*/
		return true;                  
/*	return false;*/
};

bool NetworkController::send_image(){
	std::string connect="tcp://localhost:510";
	for (int i=0;i<paths.size();++i){
		zmq::context_t context(1);
		zmq::socket_t requester(context, ZMQ_REQ);
		connect[18] =boost::lexical_cast<char>(i);
		int a=5;
		requester.connect(connect.c_str());
		FILE * pFile = fopen(paths[i].string().c_str(),"rb");
		if (pFile!=NULL){
		fseek( pFile, 0, SEEK_END );
		int Size = ftell( pFile );
		rewind(pFile);                         // ÊÀÆÄÀß ÑÒÐÎ×ÊÀ ÂÛÑÒÐÀÄÀÍÀ"!!!!!!!!
		zmq::message_t messagee(Size);         // Äóìàþ, íà ýòîì ìîìåíòå Ñåðåæà áûë íå â ñåáå 
		fread((void*)messagee.data(),1,Size,pFile);
		requester.send(messagee);         
		fclose(pFile);
		Sleep(0.5);

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
//zmq::context_t context(1);
//zmq::socket_t ptr_requester(context, ZMQ_REQ);
//requester = &ptr_requester;
}