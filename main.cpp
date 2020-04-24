#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    if(c.createconnection())
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);

        // qDebug()<<"Connection successful";
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);

        //qDebug()<<"Connection failed";


    //c.closeConnection();

    return a.exec();
}
