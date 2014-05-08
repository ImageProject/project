#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROOLER_H
#include "zmq_for_WinApi.hpp"
#include "zhelpers.hpp"
#include "User.h"

#include <boost/random/random_device.hpp>
#include <boost/timer.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/thread/thread.hpp>
#include "boost/filesystem/path.hpp" // includes boost/filesystem/path.hpp
#include <fstream>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
using namespace std;
//#pragma comment(lib, "libzmq.lib")

class NetworkController{
	public:
	NetworkController();
	void prepare();
	bool send_image();
	bool send_strings();
	void setUser(User *);
	std::string receive();
	int state;
	string id;
    std::string one;
	std::string two;
	bool New;
	string grapth;
	bool fail;
	bool receive_result();
};
#endif