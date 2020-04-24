#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "client_fidele.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPdfWriter>
#include <QTextDocument>
#include <QtPrintSupport/qabstractprintdialog.h>
#include <QDialog>
#include <QDebug>
#include <QPen>
#include <string>
#include <QDateTime>
#include <QtCore/qstring.h>
 #include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabclient->setModel(tmpclient.afficher());
ui->tabclientf->setModel(tmpclientf.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int REF = ui->lineEdit_ref->text().toInt();
    QString NOM= ui->lineEdit_nom->text();
    QString PRENOM= ui->lineEdit_prenom->text();
     int CIN = ui->lineEdit_cin->text().toInt();
     QString ADRESSE= ui->lineEdit_adresse->text();
      QString DATE1= ui->lineEdit_date1->text();
       QString NBR_JOURS= ui->lineEdit_nbr_jours->text();
  client c(REF,NOM,PRENOM,CIN,ADRESSE,DATE1,NBR_JOURS);
  bool test=c.ajouter();
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpclient.supprimer(id);
if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("client supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_ajouter_client_f_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
     QString cin = ui->lineEdit_cin_2->text();
     QString adresse= ui->lineEdit_adresse_2->text();
      QString adresse_mail= ui->lineEdit_adresse_mail->text();
  client_fidele cf(matricule,nom,cin,adresse,adresse_mail);
  bool test=cf.ajouter();
  if(test)
{ui->tabclientf->setModel(tmpclientf.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client fidéle"),
                  QObject::tr("client fidéle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_pb_supprimer_2_clicked()
{
   int MATRICULE_FISCALE = ui->line_matricule_fiscale2->text().toInt();
    bool test=tmpclientf.supprimer(MATRICULE_FISCALE);
    if(test)
    {ui->tabclientf->setModel(tmpclientf.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un CLIENT"),
                    QObject::tr("CLIENT supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un CLIENT"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_modifier_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT REF FROM CLIENT");

    int ref=ui->comboBox_ref_modifier->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE REF = :REF");
    query.bindValue(":REF",ref);
    query.exec();
    ui->tabWidget->setCurrentIndex(3);
    ui->comboBox_ref_modifier->setModel(model);
    while(query.next()){
        ui->lineEdit_ref_3->setText(query.value(0).toString());
        ui->lineEdit_nom_5->setText(query.value(1).toString());
        ui->lineEdit_prenom_3->setText(query.value(2).toString());
        ui->lineEdit_cin_5->setText(query.value(3).toString());
        ui->lineEdit_adresse_5->setText(query.value(4).toString());
        ui->lineEdit_date1_3->setText(query.value(5).toString());
        ui->lineEdit_nbr_jours_3->setText(query.value(6).toString());



    }


}


void MainWindow::on_pushButton_modifierClient_clicked()
{
    int ref = ui->lineEdit_ref_3->text().toInt();
    QString nom= ui->lineEdit_nom_5->text();
    QString prenom= ui->lineEdit_prenom_3->text();
     int cin = ui->lineEdit_cin_5->text().toInt();
     QString adresse= ui->lineEdit_adresse_5->text();
      QString date1= ui->lineEdit_date1_3->text();
       QString nbr_jours= ui->lineEdit_nbr_jours_3->text();
  client c(ref,nom,prenom,cin,adresse,date1,nbr_jours);
  bool test=c.modifier(ref);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_rechercher_clicked()
{
    QString search=ui->lineEdit_search->text();
    ui->tabclient->setModel(tmpclient.rechercher(search));
}

void MainWindow::on_pushButton_tri_decr_clicked()
{
    client c;
    ui->tabclient->setModel(tmpclient.tri());
}



void MainWindow::on_pushButton_modifier_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");

    int MAT=ui->comboBox_ref_modifier_2->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM client_fidele WHERE MATRICULE_FISCALE = :MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE",MAT);
    query.exec();
    ui->tabWidget->setCurrentIndex(12);
    ui->comboBox_ref_modifier_2->setModel(model);
    while(query.next()){
        ui->lineEdit_matricule_11->setText(query.value(0).toString());
        ui->lineEdit_nom_12->setText(query.value(1).toString());
        ui->lineEdit_nom_13->setText(query.value(2).toString());
        ui->lineEdit_nom_14->setText(query.value(3).toString());
        ui->lineEdit_nom_15->setText(query.value(4).toString());



}
}
void MainWindow::on_pushButton_modifierClient_2_clicked()
{
    int MAT = ui->lineEdit_matricule_11->text().toInt();
    QString nom= ui->lineEdit_nom_12->text();
     QString cin = ui->lineEdit_nom_13->text();
     QString adresse= ui->lineEdit_nom_14->text();
      QString adresse_mail= ui->lineEdit_nom_15->text();
  client_fidele cf(MAT,nom,cin,adresse,adresse_mail);
  bool test=cf.modifier(MAT);
  if(test)
{ui->tabclientf->setModel(tmpclientf.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client fidéle"),
                  QObject::tr("client fidéle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier CLIENT FIDELE"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_ajouter_client_f_3_clicked()
{

    QPrinter printer;

    printer.setOutputFormat(QPrinter::PdfFormat);

    printer.setOutputFileName("C:\\Users\\Bechir\\Desktop\\test.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation

    QPainter painter;



    if (! painter.begin(&printer)) { // failed to open file

        qWarning("failed to open file, is it writable?");

        //return 1;

    }









    QSqlQuery   query ;

    qDebug() << query.prepare("select sysdate from dual  ");//hethi date mta3 systeme d9i9et eli 3melet create pdf (clic 3al bouton )

    if ( query.exec() )

    {



        QString S= QDate::currentDate().toString();

        painter.drawText(50,50, S);

        QPen penred(Qt::red);



        painter.setFont(QFont("Arial", 60));

        penred.setWidth(1);

        painter.setPen(penred);

        painter.drawText(200,500," LIST ");

        painter.drawText(200,650,"  CLIENT.");





    }



    QString REF,NOM,PRENOM,CIN,image ;

    QSqlQuery   qry ;





//badel i table w les attribues

    qDebug() << qry.prepare("select * from client order by REF ");



    painter.drawPixmap(600,50,100,100,QPixmap::fromImage(QImage("A:/photo/logo.png")));//chemin mta3 il logo

    painter.drawText(400,800, image);

    if ( qry.exec() )

    {

        while(qry.next())

        {





            if (!printer.newPage())

            {

                qWarning("failed");

                return ;

            }

            painter.setFont(QFont("Arial",20));

            QPen penblack(Qt::black);



            painter.setPen(penblack);



            REF = qry.value(0).toString();

            painter.drawText(50,100,"REF :");

            painter.drawText(400,100, REF);



            painter.drawText(50,200,"NOM :");

            NOM=qry.value(1).toString();

            painter.drawText(400,200, NOM);



            painter.drawText(50,300,"PRENOM :");

            PRENOM=qry.value(2).toString();

            painter.drawText(400,300, PRENOM);



            painter.drawText(50,400,"CIN :");

            CIN=qry.value(3).toString();

            painter.drawText(400,400, CIN);




            /* QString A= QString::number(p);



             painter.drawText(400,1100,A);

             p++;

             QString::number(p);*/



        }

    }





    painter.end();


}


void MainWindow::on_pushButton_4_pressed()
{
    ui->tabWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_5_pressed()
{
    ui->tabWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_6_pressed()
{
    ui->tabWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_3_pressed()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_pressed()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->tabWidget->setCurrentIndex(6);
}












void MainWindow::on_comboBox_ref_modifier_activated(const QString &arg1)
{

}
