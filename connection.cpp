#include "connection.h"
#include<QDebug>
#include<QMessageBox>

using namespace std;
connection::connection()
{

}


connection::~connection()
{
    /*  */
}

bool connection::connect()
{      QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("Projet_2A11");
       db.setUserName("willy");
       db.setPassword("willy");
       if (!db.open()) {
           QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
               QObject::tr("Unable to establish a database connection.\n"
                           "This example needs SQLite support. Please read "
                           "the Qt SQL driver documentation for information how "
                           "to build it.\n\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
           qDebug()<<" not conected!!\n";
           return false;
       }
     qDebug()<<"you are conected to the database!!!\n";
       return true;
   }

void connection::closeconnecxion()
{    QSqlDatabase db;
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
