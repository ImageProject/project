//файл-контроллер за сетью
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
	socket.bind("tcp://*:5556"); //созадние самого сервера
 	return s_recv(socket);
}
bool NetworkController::send_strings(){
	zmq::context_t context(1);
	zmq::socket_t requester(context, ZMQ_REQ);
	std::string str;
	boost::timer too;
	requester.connect("tcp://localhost:5555"); //соединение с сервером
	bool stete = requester.connected(); //создание переменной, если соединение прошло успешно
	while(!requester.connected()){
		if (too.elapsed()<30){ //если соединение происходит более 30 секунл
			Sleep(2); //то сон
			requester.connect("tcp://localhost:5555"); //и вторая попытка соединения
		} else{ fail=true; }                                                                            //////////////////////////
	}
	if (!grapth.size()){ //проверка на размер графа
	char temp = '/';
	char buffer[2];
	char * temp_state = itoa(New,buffer,10);
	string newresult; //создание строки для записи нового результата
    newresult =newresult+*temp_state+temp+one+temp+two+temp; //нахождение новго результата
	s_send(requester,newresult); //отправление на сервер результата
	if (this->receive()[0]=='O') //если получен 0, то всё верно
	return true;                  
	}
	else { //если получен не 0, то выполняется ещё раз
	grapth = 'G'+id+"/"+grapth;
	s_send(requester,grapth);
	}
	/*if (this->receive()[0]=='O')*/
		return true;                  
/*	return false;*/
};

bool NetworkController::send_image(){ //класс отправки изображения на сервер
	std::string connect="tcp://localhost:510"; //соединение с сервером
	for (int i=0;i<paths.size();++i){ //проверка размера изображение
		zmq::context_t context(1);
		zmq::socket_t requester(context, ZMQ_REQ);
		connect[18] =boost::lexical_cast<char>(i); //соединение
		int a=5;
		requester.connect(connect.c_str());
		FILE * pFile = fopen(paths[i].string().c_str(),"rb"); //открытие файла
		if (pFile!=NULL){
		fseek( pFile, 0, SEEK_END );
		int Size = ftell( pFile ); //размер файла
		rewind(pFile);                         //  ¿∆ƒ¿ﬂ —“–Œ◊ ¿ ¬€—“–¿ƒ¿Õ¿"!!!!!!!!
		zmq::message_t messagee(Size);         // ƒÛÏ‡˛, Ì‡ ˝ÚÓÏ ÏÓÏÂÌÚÂ —ÂÂÊ‡ ·˚Î ÌÂ ‚ ÒÂ·Â 
		fread((void*)messagee.data(),1,Size,pFile); //чтение файлра
		requester.send(messagee);         //отправление изображени
		fclose(pFile); //закрытие файла
		Sleep(0.5); //отдых

		}
	}
	return true;

}
NetworkController::NetworkController(){
	New=false;
	state = 0;
	this->prepare(); //подготовка
}
void NetworkController::setUser(User * newUser){ //класс создания нового пользоателя на сервере
	this->one = newUser->login; //запоминание логина
	this->two = newUser->password; //запоминание пароля
	this->New = newUser->New; //сохранение новог пользователя
	
}
bool NetworkController::receive_result(){ //класс получения результата
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind ("tcp://*:5555"); //запрос на сервер
		zmq::message_t receiven; //запись полученного изображения
		int a = socket.recv(&receiven);
		FILE * ndefile = fopen("Receive.jpg","wb"); //открытие полученного файл
		fwrite((void *)receiven.data(),1,777835, ndefile); //обработка одним из фильтров
		std::cout<<"YEA BITCH"; //вывод сообщения об удачной обработке
		fclose(ndefile);//закрытие файла
		return true;
}
void NetworkController::prepare(){ //подготовка
//zmq::context_t context(1);
//zmq::socket_t ptr_requester(context, ZMQ_REQ);
//requester = &ptr_requester;
}