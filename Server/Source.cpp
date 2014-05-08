#include "Database.h"
#include "mongo\client\dbclient.h"
void Database::run(){
	mongo::DBClientConnection c;
	c.connect("127.0.0.1:27017");
}