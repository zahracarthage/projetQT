#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include "mainwindow.h"



class connection
{
public:
    connection();
    ~connection();

   static bool connect();
     void closeconnecxion();




private:
    Ui::MainWindow *ui;
     //QSqlDatabase db;
};

#endif // CONEXION_H
