#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROOLER_H
#include "User.h"
#include "zmq_for_WinApi.hpp"
#include "zhelpers.hpp"

#include <boost/random/random_device.hpp>
#include <boost/timer.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/thread/thread.hpp>
using namespace std;
//#pragma comment(lib, "libzmq.lib")


class NetworkController{
	public:
	void recieve_msg();
	void send_msg();
	int state;
std::	string one;
	std::string two;
	bool New;
	NetworkController(User &);
};
void NetworkController::send_msg(){
	// Setup sockets
	zmq::context_t context(1);

	// request socket
	zmq::socket_t requester(context, ZMQ_REQ);
		
	// set timeout for infinite
	int timeout = -1; 
	//requester.setsockopt(ZMQ_RCVTIMEO, &timeout, sizeof(timeout));

	//// set client identidication code (id)
std::string str;
	std::string chars(
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"1234567890"
		"!@#$%^&*()"
		"`~-_=+[{]{\\|;:'\",<.>/? ");
	boost::random::random_device rng;
	boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);
	for(int i = 0; i < 8; ++i) {
		str = str+ chars[index_dist(rng)];
	}
	/*requester.setsockopt(ZMQ_IDENTITY,str.c_str(), str.length());
*/
	boost::timer too;
	requester.connect("tcp://localhost:5556");
   bool stete = requester.connected();
	while(!requester.connected()){
		if (too.elapsed()<30){
			Sleep(2);
			requester.connect("tcp://localhost:5556");
		};
		
	}
	NetworkController::state = 1;
	char temp = '/';
	char buffer[2];
	char * temp_state = itoa(New,buffer,10);
	string result =*temp_state+one+temp+two;
	s_sendf(requester,result, ZMQ_NOBLOCK);


}
NetworkController::NetworkController(User & user){
	this->two = user.password;
	this->one = user.login;
	this->New = user.New;
	this->send_msg();
}
#endif