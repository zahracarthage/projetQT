#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{

    db=QSqlDatabase::addDatabase("QODBC");
/*db.setDatabaseName("projet_test");
db.setUserName("bechir");//inserer nom de l'utilisateur
db.setPassword("bechir");//inserer mot de passe de cet utilisateur*/

db.setDatabaseName("Projet_2A");
db.setUserName("bechir");//inserer nom de l'utilisateur
db.setPassword("bechir");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}

void Connection::closeConnection()
{
    db.close();
}

