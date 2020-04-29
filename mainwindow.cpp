#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "depenses.h"
#include <QString>
#include <QtMath>
#include <QDate>
#include<QFileDialog>
#include<QDateEdit>
#include<QMessageBox>
#include <iostream>
#include <QTabWidget>
#include "emplacement.h"
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dep->setModel(tempdep.afficher());
    ui->tableView->setModel(tempemp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}









void MainWindow::on_pushButton_4_clicked()
{
    /*QString ref = ui->lineEdit_8->text();
    QString descrip = ui->textEdit->toPlainText();
    QString montant = ui->lineEdit_10->text();
    QString date = ui->dateEdit_3->date().toString();

    depenses D(ref,descrip,montant,date);

    if(ref.isEmpty() || descrip.isEmpty() || montant.isEmpty() || date.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
        D.Ajouter();
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" La depense a été ajouter."),QMessageBox::Yes);
        ui->dep->setModel(D.rechercher(""));
        ui->dep->clearSelection();
         ui->lineEdit_8->clear();
         ui->textEdit->clear();
          ui->lineEdit_10->clear();
           ui->dateEdit_3->clear();
    }*/

    ui->tabRef->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    QString ref = ui->lineEdit_9->text();
    if(ref.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),
                                  qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
        }
    else
    {
        QMessageBox::critical(0,qApp->tr("attention"),
                              qApp->tr("voulez vous supprimer cette depense?"),QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes)
        {
            bool test= tempdep.supprimer(ref);
            if (test)
            {
                ui->dep->setModel(tempdep.afficher());
                ui->dep->setModel(tempdep.rechercher(""));
                ui->dep->clearSelection();
            }
        }

    }

}

void MainWindow::on_pushButton_13_clicked()
{
    QString ref = ui->lineEdit_8->text();
    QString descrip = ui->textEdit->toPlainText();
    QString montant = ui->lineEdit_10->text();
    QString date = ui->dateEdit_3->date().toString();

    depenses D(ref,descrip,montant,date);

    if(ref.isEmpty() || descrip.isEmpty() || montant.isEmpty() || date.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
        D.Ajouter();
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" La depense a été ajouter."),QMessageBox::Yes);
        ui->dep->setModel(D.rechercher(""));
        ui->dep->clearSelection();
         ui->lineEdit_8->clear();
         ui->textEdit->clear();
          ui->lineEdit_10->clear();
           ui->dateEdit_3->clear();
    }

}

void MainWindow::on_pushButton_25_clicked()
{
    QString ref = ui->lineEdit_5->text();
    QString descrip = ui->lineEdit_6->text();
    QString montant = ui->lineEdit_3->text();
    QString date = ui->lineEdit_7->text();

    emplacement E(ref,descrip,montant,date);

    if(ref.isEmpty() || descrip.isEmpty() || montant.isEmpty() || date.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
        E.Ajouter();
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" L'emplacement a été ajouter."),QMessageBox::Yes);
        ui->tableView->setModel(E.rechercher(""));
        ui->tableView->clearSelection();
         ui->lineEdit_5->clear();
         ui->lineEdit_6->clear();
          ui->lineEdit_3->clear();
           ui->lineEdit_7->clear();
    }

}

void MainWindow::on_pushButton_29_clicked()
{
    QString ref = ui->lineEdit_4->text();
    if(ref.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),
                                  qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
        }
    else
    {
        QMessageBox::critical(0,qApp->tr("attention"),
                              qApp->tr("voulez vous supprimer cet emplacement?"),QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes)
        {
            bool test= tempemp.supprimer(ref);
            if (test)
            {
                ui->tableView->setModel(tempemp.afficher());
                ui->tableView->setModel(tempdep.rechercher(""));
                ui->tableView->clearSelection();
            }
        }

    }

}

void MainWindow::on_pushButton_5_clicked()
{
    QString r=ui->lineEdit_11->text();
       QString d=ui->textEdit_2->toPlainText();
        QString m=ui->lineEdit_2->text();
         QString dd=ui->dateEdit_2->date().toString();

         if(r.isEmpty() || d.isEmpty() || m.isEmpty() || dd.isEmpty())
                          {
                              QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                          }
         else {

             depenses cp(r,d,m,dd);
             cp.modifier();
              ui->dep->setModel(cp.rechercher(""));
             ui->dep->clearSelection();
             QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" La depense a été modifiée."),QMessageBox::Yes);
               ui->textEdit_2->clear();
                 ui->lineEdit_2->clear();
                   ui->lineEdit_11->clear();
                     ui->dateEdit_2->clear();
         }


}

void MainWindow::on_pushButton_clicked()
{
    QString ref = ui->lineEdit_12->text();
    QString descrip = ui->lineEdit_14->text();
    QString montant = ui->lineEdit_15->text();
    QString date = ui->lineEdit_13->text();




    emplacement E(ref,descrip,montant,date);

    if(ref.isEmpty() || descrip.isEmpty() || montant.isEmpty() || date.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
        E.modifier();
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" L'emplacement a été modifié."),QMessageBox::Yes);
        ui->tableView->setModel(E.rechercher(""));
        ui->tableView->clearSelection();
         ui->lineEdit_12->clear();
         ui->lineEdit_14->clear();
          ui->lineEdit_15->clear();
           ui->lineEdit_13->clear();
    }

}

void MainWindow::on_pushButton_3_clicked()
{
   QPrinter print;
    print.setPrinterName("imprmer");
    QPrintDialog dialog(&print,this);
    if(dialog.exec()==QDialog ::Rejected) return;
    ui->tableView->render(&print);
}

void MainWindow::on_pushButton_2_clicked()
{
    emplacement cp;
        QString id=ui->lineEdit_16->text();
       // QString name=ui->lineEdit->text();

       ui->tableView->setModel(cp.rechercher(id));
       // ui->tableView_2->setModel(cp.rechercher_nom(name));
       ui->tableView->clearSelection();
}

void MainWindow::on_pushButton_12_clicked()
{
    depenses cp;
        QString id=ui->lineEdit_17->text();
       // QString name=ui->lineEdit->text();

       ui->dep->setModel(cp.rechercher(id));
       // ui->tableView_2->setModel(cp.rechercher_nom(name));
       ui->dep->clearSelection();
}



void MainWindow::on_pushButton_7_clicked()
{
    ui->tabRef->setCurrentIndex(1);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tabRef->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->tabRef->setCurrentIndex(3);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->Gtab->setCurrentIndex(0);
    ui->tabDep->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->Gtab->setCurrentIndex(1);
    ui->tabRef->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->Gtab->setCurrentIndex(0);
    ui->tabDep->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->Gtab->setCurrentIndex(1);
    ui->tabRef->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->tabDep->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tabDep->setCurrentIndex(1);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->tabDep->setCurrentIndex(2);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tabDep->setCurrentIndex(3);
}

void MainWindow::on_pushButton_20_clicked()
{
    QPrinter print;
     print.setPrinterName("imprmer");
     QPrintDialog dialog(&print,this);
     if(dialog.exec()==QDialog ::Rejected) return;
     ui->dep->render(&print);
}

void MainWindow::on_pushButton_21_clicked()
{
   /* // prepare data:
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 = customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = customPlot->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::NoPen);
    bars2->setBrush(QColor(10, 100, 50, 70));
    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
    customPlot->addLayer("abovemain", customPlot->layer("main"), QCustomPlot::limAbove);
    customPlot->addLayer("belowmain", customPlot->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    customPlot->xAxis->grid()->setLayer("belowmain");
    customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    customPlot->axisRect()->setBackground(axisRectGradient);

    customPlot->rescaleAxes();
    customPlot->yAxis->setRange(0, 2);*/
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->Gtab_2->setCurrentIndex(0);
    ui->client->setCurrentIndex(0);
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->Gtab_2->setCurrentIndex(1);
    ui->fidele->setCurrentIndex(0);
}

void MainWindow::on_pushButton_33_clicked()
{
    ui->client->setCurrentIndex(0);
}

void MainWindow::on_pushButton_34_clicked()
{
    ui->client->setCurrentIndex(1);
}

void MainWindow::on_pushButton_35_clicked()
{
    ui->client->setCurrentIndex(2);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->client->setCurrentIndex(3);
}

void MainWindow::on_pushButton_42_clicked()
{
    ui->Gtab_2->setCurrentIndex(0);
    ui->client->setCurrentIndex(0);
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->Gtab_2->setCurrentIndex(1);
    ui->fidele->setCurrentIndex(0);
}

void MainWindow::on_pushButton_43_clicked()
{
    ui->fidele->setCurrentIndex(0);
}

void MainWindow::on_pushButton_44_clicked()
{
    ui->fidele->setCurrentIndex(1);
}

void MainWindow::on_pushButton_45_clicked()
{
    ui->fidele->setCurrentIndex(2);
}

void MainWindow::on_pushButton_46_clicked()
{
    ui->fidele->setCurrentIndex(3);
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
QSqlQueryModel * model= new QSqlQueryModel;
model->setQuery("SELECT REF FROM client");
ui->comboBox_3->setModel(model);
ui->comboBox_2->setModel(model);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_tri_decr_clicked()
{
    client c;
    ui->tabclient->setModel(tmpclient.tri());
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    QString search=ui->lineEdit_search->text();
    ui->tabclient->setModel(tmpclient.rechercher(search));
}

void MainWindow::on_pushButton_modifierClient_clicked()
{
    int ref = ui->comboBox_3->currentText().toInt();
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
QSqlQueryModel * model= new QSqlQueryModel;
model->setQuery("SELECT REF FROM client");
ui->comboBox_3->setModel(model);
ui->comboBox_2->setModel(model);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    /*QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT REF FROM CLIENT");*/

    int ref=ui->comboBox_3->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE REF = :REF");
    query.bindValue(":REF",ref);
    query.exec();
    //ui->tabWidget->setCurrentIndex(3);
    //ui->comboBox_3->setModel(model);
    while(query.next()){
        //ui->comboBox_3->setText(query.value(0).toString());
        ui->lineEdit_nom_5->setText(query.value(1).toString());
        ui->lineEdit_prenom_3->setText(query.value(2).toString());
        ui->lineEdit_cin_5->setText(query.value(3).toString());
        ui->lineEdit_adresse_5->setText(query.value(4).toString());
        ui->lineEdit_date1_3->setText(query.value(5).toString());
        ui->lineEdit_nbr_jours_3->setText(query.value(6).toString());



    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->comboBox_2->currentText().toInt();
    bool test=tmpclient.supprimer(id);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        QSqlQueryModel * model= new QSqlQueryModel;
        model->setQuery("SELECT MATRICULE_FISCALE FROM client");
        ui->comboBox_3->setModel(model);
        ui->comboBox_2->setModel(model);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

/*void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT REF FROM client");
    ui->comboBox_3->setModel(model);
}*/

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
QSqlQueryModel * model= new QSqlQueryModel;
model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
ui->comboBox->setModel(model);
ui->comboBox_ref_modifier_2->setModel(model);
}
}

void MainWindow::on_comboBox_ref_modifier_2_activated(const QString &arg1)
{
    /*QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");*/

    int MAT=ui->comboBox_ref_modifier_2->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM client_fidele WHERE MATRICULE_FISCALE = :MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE",MAT);
    query.exec();
   // ui->tabWidget->setCurrentIndex(12);
   // ui->comboBox_ref_modifier_2->setModel(model);
    while(query.next()){
        //ui->lineEdit_matricule_11->setText(query.value(0).toString());
        ui->lineEdit_nom_12->setText(query.value(1).toString());
        ui->lineEdit_nom_13->setText(query.value(2).toString());
        ui->lineEdit_nom_14->setText(query.value(3).toString());
        ui->lineEdit_nom_15->setText(query.value(4).toString());



}
}

/*void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
    ui->comboBox->setModel(model);
}*/

void MainWindow::on_pb_supprimer_2_clicked()
{
    int MATRICULE_FISCALE = ui->comboBox->currentText().toInt();
     bool test=tmpclientf.supprimer(MATRICULE_FISCALE);
     if(test)
     {ui->tabclientf->setModel(tmpclientf.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("CLIENT supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         QSqlQueryModel * model= new QSqlQueryModel;
         model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
         ui->comboBox->setModel(model);
         ui->comboBox_ref_modifier_2->setModel(model);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifierClient_2_clicked()
{
    int MAT = ui->comboBox_ref_modifier_2->currentText().toInt();
    QString nom= ui->lineEdit_nom_12->text();
     QString cin = ui->lineEdit_nom_13->text();
     QString adresse= ui->lineEdit_nom_14->text();
      QString adresse_mail= ui->lineEdit_nom_15->text();
  client_fidele cf(MAT,nom,cin,adresse,adresse_mail);
  bool test=cf.modifier(MAT);
  if(test)
{ui->tabclientf->setModel(tmpclientf.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client fidéle"),
                  QObject::tr("client fidéle modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
QSqlQueryModel * model= new QSqlQueryModel;
model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
ui->comboBox->setModel(model);
ui->comboBox_ref_modifier_2->setModel(model);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier CLIENT FIDELE"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_48_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_51_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_52_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_56_clicked()
{
    emplacement c;
    ui->tableView->setModel(tempemp.tri1());
}

void MainWindow::on_pushButton_55_clicked()
{
    emplacement c;
    ui->tableView->setModel(tempemp.tri2());
}

void MainWindow::on_pushButton_53_clicked()
{
    depenses c;
    ui->dep->setModel(tempdep.tri1());
}

void MainWindow::on_pushButton_54_clicked()
{
    depenses c;
    ui->dep->setModel(tempdep.tri2());
}
