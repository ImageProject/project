#include "zmq.hpp"
int main{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        //  �������� ���������� ������� �� �������
        socket.recv (&request);

        //  �� ����������� ��� ���� ����� ������������
#ifndef _WIN32
        sleep(1);
#else
    Sleep (1);
#endif

        //  ������� ����� ������� ������������
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "Im Got IT!", 5);
        socket.send (reply);
    }
    return 0;
}