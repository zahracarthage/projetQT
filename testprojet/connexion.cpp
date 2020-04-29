#include "connexion.h"



Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("projet2a11");

db.setUserName("zahra");//inserer nom de l'utilisateur

db.setPassword("esprit19");//inserer mot de passe de cet utilisateur

if (db.open())

test=true;



    return  test;
}
