#include "zmq.hpp"
int main{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        //  ќжидание следующего запроса от клиента
        socket.recv (&request);

        //  Ќ≈ представл€ю как люди пишут документацию
#ifndef _WIN32
        sleep(1);
#else
    Sleep (1);
#endif

        //  ќтслыем ответ обратно пользователю
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "Im Got IT!", 5);
        socket.send (reply);
    }
    return 0;
}