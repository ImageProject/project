

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include <zmq.hpp>
#include <windows.h>

using namespace std;
using namespace zmq;

typedef enum {SERVER, CLIENT} MODE;

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


int main(void)
{ //решение того, кто ты: клиент, сервер или никто
program_start:

cout << "Who are you?\n [1] - Server\n [2] - Client\n [q] - Exit" << endl;

char decision = getch(); //выбираешь нужный вариант
MODE mode;

if(decision == '1'){ //если нажал 1, то перенправление на сервер
mode = SERVER;
}else if(decision == '2'){ //если 2, то на клиент
mode = CLIENT;
}else if(decision == 'q'){ //если q, то выход пока-пока
return 0;
}else{
// После нажатия какой-либо другой кнопки вывод сообщения
cout << "Try again" << endl; //"Попробуйте снова"
goto program_start; //начало программа
}


zmq::context_t context(1); //создание сокетов
zmq::socket_t *socket;


if(mode == SERVER){ //подготовка серера

socket = new zmq::socket_t(context, ZMQ_REP);	
socket->bind ("tcp://*:5555");
cout << "Server started. Waiting for client." << endl;	

//Клиент
message_t helloFromClient;
socket->recv(&helloFromClient);	
string helloFromClientString((char *)helloFromClient.data());

if(helloFromClientString == "connected"){
message_t helloClient(10);
memcpy((void *) helloClient.data(), "connected", 10);
socket->send(helloClient);
}else{
cout << "Client does not response" << endl;
return 0;
}

}else if(mode == CLIENT){

socket = new zmq::socket_t (context, ZMQ_REQ);

string remoteIP;

cout << "Enter IP to connect" << endl;
getline(cin, remoteIP);

std::cout << "Connecting to server..." << std::endl;
socket->connect (string("tcp://"+remoteIP+":5555").c_str());


// Handshaking with server
// First send req must be from client
message_t helloServer(10);
memcpy((void *) helloServer.data(), "connected", 10);
socket->send(helloServer);	

message_t helloFromServer;
socket->recv(&helloFromServer);	
string helloFromServerString((char *)helloFromServer.data());

if(helloFromServerString == "connected"){
cout << "Connected!" << endl;
message_t helloClient(10);
memcpy((void *) helloClient.data(), "connected", 10);
socket->send(helloClient);
}else{
cout << "Server does not response" << endl;
return 0;
}
}


// Everything's ready. Go for main loop

while(1){
// check for incoming messages
message_t receivedMessage;
socket->recv(&receivedMessage);

string receivedMessageString((char *)receivedMessage.data());

if(receivedMessageString == "0"){
// no messages
}else{
// something better
//cout << "Received size: " << receivedMessage.size() << endl;
cout << receivedMessageString << endl;
}

if(_kbhit()){
// wanana type message to send
cout << "Input message: ";
string messageString;
getline(cin, messageString);
messageString = "["+currentDateTime()+"] " + messageString;
char *messageCString = (char *)messageString.c_str();
size_t messageSize = strlen(messageCString)+1;

message_t message(messageSize);
memcpy((void *) message.data(), messageCString, messageSize);
socket->send(message);
cout << "\n" + messageString << endl;
cout << "[Message delivered]\n" << endl;
}else{	
// send "no messages" message
message_t noMsg(2);
memcpy((void *) noMsg.data(), "0", 2);
socket->send(noMsg);	
}	
}




return 0;
}