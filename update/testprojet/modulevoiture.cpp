#include "modulevoiture.h"
#include "ui_modulevoiture.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QDebug>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    notifier = new QSystemTrayIcon(this);
        notifier->setIcon(QIcon(":/notification.jpg"));
        notifier->show();



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{

//        QSqlQuery query;

    QSound::play(":/click.wav");



bool test;

        voiture v(
                    ui->nomv->text(),
                    ui->prix->text(),
                    ui->nbrloca->text() ,
                    ui->nbrrep->text(),
                    ui->dispo->currentText(),
                    ui->cbx1->currentText()

                    );



          test= v.ajouter_voiture();


        if (ui->nomv->text().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom voiture !!!!") ;

         }

        if (ui->prix->text().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;

         }
        if (ui->nbrloca->text().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nombre location !!!!") ;

         }

        if (ui->nbrrep->text().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nombre reparation !!!!") ;

         }


        if (ui->dispo->currentText().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP disponibilite !!!!") ;

         }




        if(test)
      {
            notifier->showMessage("Ok"," vehicule ajoutée",QSystemTrayIcon::Information,10000);


      QMessageBox::information(nullptr, QObject::tr("Ajouter une voiture "),
                        QObject::tr("voiture ajoutée.\n"
                                    "Click ok pour quitter."), QMessageBox::Ok);

      QSqlQueryModel * model= new QSqlQueryModel;
      model->setQuery("SELECT id_voiture FROM voiture");
      ui->nid->setModel(model);
      ui->rid->setModel(model);
      ui->lineEdit_6->setModel(model);
      ui->cbx3->setModel(model);
      ui->cbx4->setModel(model);
      ui->comboBox_9->setModel(model);
      ui->comboBox_8->setModel(model);
      ui->cbsupp->setModel(model);

}
        else
            QMessageBox::critical(0, qApp->tr("Ajout"),

                            qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);



         ui->prix->setText("");
         ui->nomv->setText("");
         ui->nbrloca->setText("");
         ui->nbrrep->setText("");
         ui->dispo->setCurrentText("disponibilite");
         ui->cbx1->setCurrentText("");


}

void MainWindow::on_pushButton_clicked()
{

    ui->affichelv->setModel(tmpv.afficher_voiture());
}

void MainWindow::on_voiture_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_b_ajouterv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_b_modifierv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(6);



}

void MainWindow::on_b_afficherv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(4);
     ui->affichelv->setModel(tmpv.afficher_voiture());



}
void MainWindow::on_pushButton_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_b_supprimerv_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(5);



}


void MainWindow::on_supprimerid_clicked()
{

 QSqlQuery query;


 QString reff = ui->rid->currentText();
 bool test = tmpv.supprimer_voiture(reff);

     if(test)
 {



         QString str = "Vous voulez vraiment supprimer \n le vehicule ayant pour reference : "+ ui->rid->currentText();
                       int ret = QMessageBox::question(this, tr("vehicule"),str,QMessageBox::Ok|QMessageBox::Cancel);

                       switch (ret) {
                         case QMessageBox::Ok:
                             if (tmpv.supprimer_voiture(reff))
                               {  notifier->showMessage("Ok","vehicule supprimé",QSystemTrayIcon::Information,10000);


                                 QMessageBox ::information(0, qApp->tr("Suppression"),
                                                           qApp->tr("le vehicule a été supprimé"), QMessageBox::Ok);
                                 QSqlQueryModel * model= new QSqlQueryModel;
                                 model->setQuery("SELECT id_voiture FROM voiture");
                                 ui->nid->setModel(model);
                                 ui->rid->setModel(model);
                                 ui->lineEdit_6->setModel(model);
                                 ui->comboBox_8->setModel(model);
                                 ui->comboBox_9->setModel(model);
                                ui->cbsupp->setModel(model);
                             }
                           break;
                         case QMessageBox::Cancel:

                             break;
                         default:
                             break;
                       }
     }
                       else
                                 {

                                     QMessageBox::critical(0, qApp->tr("Suppression"),
                                         qApp->tr("vehicule non trouvé"), QMessageBox::Cancel);

                                 }

}

void MainWindow::on_nid_activated(const QString &arg1)
{
    QString id_voiture = ui->nid->currentText();

    QSqlQuery query;
   query.prepare("SELECT * FROM voiture WHERE id_voiture = :id_voiture");
   query.bindValue(":id_voiture",id_voiture);
   query.exec();

   while(query.next()){

   ui->nnom->setText(query.value(1).toString());
   ui->nprix->setText(query.value(2).toString());
  ui->nnbrloca->setText(query.value(3).toString());
  ui->nnbrrepa->setText(query.value(4).toString());
  ui->ndispo->setCurrentText(query.value(5).toString());
   }
}

void MainWindow::on_pushButton_3_clicked() //function modifier
{

QString id_voiture = ui->nid->currentText();
QString nom_voiture = ui->nnom->text();
QString prix = ui->nprix->text();
QString nbr_location = ui->nnbrloca->text();
QString nbr_reparation = ui->nnbrrepa->text();
QString disponibilite = ui->ndispo->currentText();



voiture *v = new voiture(id_voiture, nom_voiture, prix, nbr_location, nbr_reparation, disponibilite);

    if (v->modifier_voiture())

    {
        notifier->showMessage("Ok","vehicule modifié",QSystemTrayIcon::Information,10000);

        QMessageBox::information(0, qApp->tr("Update"),
            qApp->tr("Successful"), QMessageBox::Ok);


    }

    else
        QMessageBox::critical(0, qApp->tr("Update"),
            qApp->tr("you got some problems there check out "), QMessageBox::Cancel);

}



void MainWindow::on_icon4_10_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_icon2_13_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(5);


}

void MainWindow::on_icon3_11_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(6);


}

void MainWindow::on_icon4_15_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(4);
    ui->affichelv->setModel(tmpv.afficher_voiture());


}

void MainWindow::on_icon4_9_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(4);
    ui->affichelv->setModel(tmpv.afficher_voiture());


}

void MainWindow::on_pushButton_8_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_icon3_12_clicked() /* modifier */
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(6);



}

void MainWindow::on_icon2_14_clicked() /* supp*/
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(5);



}

void MainWindow::on_icon4_12_clicked() /*ajouter */
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_icon4_14_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_icon3_13_clicked()
{


}

void MainWindow::on_icon4_13_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(4);
    ui->affichelv->setModel(tmpv.afficher_voiture());


}

void MainWindow::on_icon2_16_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(5);


}

void MainWindow::on_pushButton_5_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();

    ui->stackedWidget->setCurrentIndex(6);


}

void MainWindow::on_b_vehicules_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_b_ajouter_auth_clicked()
{
    bool test;



    auth a(
                ui->nom_a->text(),
                ui->prenom_a->text(),
                ui->numero->text().toInt(),
                ui->role->currentText(),
                ui->cin->text(),
                ui->pwd->text(),
                ui->qS->currentText(),
                ui->rep_qs->text()

                );

    test = a.ajouter();



            if (ui->nom_a->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom  !!!!") ;

             }

            if (ui->prenom_a->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom !!!!") ;

             }
            if (ui->numero->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP numero !!!!") ;

             }



            if (ui->role->currentText().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP role !!!!") ;
            }
            if (ui->cin->text().isEmpty())
            {
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP cin !!!!") ;

            }
            if (ui->pwd->text().isEmpty())
            {
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP mot de passe !!!!") ;

            }
            if (ui->qS->currentText().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP question secrete  !!!!") ;

             }
            if (ui->rep_qs->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP reponse de la question secrete  !!!!") ;

             }





            if(test)
          {
                notifier->showMessage("Ok"," ajouté",QSystemTrayIcon::Information,10000);


          QMessageBox::information(nullptr, QObject::tr("Ajouter un admin/moderateur "),
                            QObject::tr(" ajoutée.\n"
                                        "Click ok pour quitter."), QMessageBox::Ok);

          QSqlQueryModel * model= new QSqlQueryModel;
          model->setQuery("SELECT CIN FROM AUTHENTIFICATION");
          ui->ncin->setModel(model);
          ui->ncin_2->setModel(model);
          ui->rcin->setModel(model);
          }
            else
                QMessageBox::critical(0, qApp->tr("Ajout"),

                                qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);


    ui->nom_a->setText("");
    ui->prenom_a->setText("");
    ui->numero->setText("");
    ui->role->setCurrentText("");
    ui->cin->setText("");
    ui->pwd->setText("");
    ui->qS->setCurrentText("");
    ui->rep_qs->setText("");

}



void MainWindow::on_afficher_auth_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->table_auth->setModel(tmpa.afficher());

}

void MainWindow::on_icon4_17_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(10); //afficher
    ui->table_auth->setModel(tmpa.afficher());



}

void MainWindow::on_icon2_18_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_supprimer_auth_clicked()
{

    QSqlQuery query;


    int cin = ui->ncin->currentText().toInt();
    bool test = tmpa.supprimer(cin);

        if(test)
    {
            /*ui->affichage_voiture->setModel(tmpv.afficher_voiture());
   */


            QString str = " Vous voulez vraiment supprimer \n la personne ayant pour numero de CIN : "+ ui->rid->currentText();
                          int ret = QMessageBox::question(this, tr("authentitication"),str,QMessageBox::Ok|QMessageBox::Cancel);

                          switch (ret) {
                            case QMessageBox::Ok:
                                if (tmpa.supprimer(cin))

                                {    QMessageBox ::information(0, qApp->tr("Suppression"),
                                                              qApp->tr("cet personne a été supprimé"), QMessageBox::Ok);

                                    notifier->showMessage("Ok","Moderateur supprimé",QSystemTrayIcon::Information,10000);

                                QSqlQueryModel * model= new QSqlQueryModel;
                                model->setQuery("SELECT CIN FROM AUTHENTIFICATION");
                                ui->ncin->setModel(model);
                                ui->ncin_2->setModel(model);
                                ui->rcin->setModel(model);
                                }

                              break;
                            case QMessageBox::Cancel:

                                break;
                            default:
                                break;
                          }
        }
                          else
                                    {

                                        QMessageBox::critical(0, qApp->tr("Suppression"),
                                            qApp->tr(" verifier le CIN "), QMessageBox::Cancel);

                                    }

}

void MainWindow::on_icon4_21_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(10);
    ui->table_auth->setModel(tmpa.afficher());

}

void MainWindow::on_icon4_22_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_ncin_2_activated(const QString &arg1)
{
    QString cin = ui->ncin_2->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM authentification where cin = :cin");
    query.bindValue(":cin",cin);
    query.exec();


    while(query.next())
    {
        ui->nnom_2->setText(query.value(0).toString());
       ui->nprenom->setText(query.value(1).toString());
       ui->nnumero->setText(query.value(2).toString());
       ui->nrole->setCurrentText(query.value(3).toString());
       ui->npwd->setText(query.value(5).toString());
       ui->qS_4->setCurrentText(query.value(6).toString());
       ui->rep_m->setText(query.value(7).toString());

    }


}


void MainWindow::on_pushButton_2_clicked()
{
    QString cin = ui->ncin_2->currentText();
    QString nom = ui->nnom_2->text();
    QString prenom = ui->nprenom->text();
    int numero = ui->nnumero->text().toInt();
    QString role = ui->nrole->currentText();
    QString pwd = ui->npwd->text();
    QString question_secrete = ui->qS_4->currentText();
    QString rep_qs = ui->rep_m->text();


    auth *a = new auth(nom, prenom, numero, role, cin ,pwd, question_secrete, rep_qs);



        if (a->modifier() )

        {
            QMessageBox::information(0, qApp->tr("Update"),
                qApp->tr("Successful"), QMessageBox::Ok);
            notifier->showMessage("Ok","moderateur modifié",QSystemTrayIcon::Information,10000);




        }

        else
            QMessageBox::critical(0, qApp->tr("Update"),

                                  qApp->tr("you got some problems there check out "), QMessageBox::Cancel);
}



void MainWindow::on_b_statv_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
  QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);  // gives more crisp, pixel aligned bar borders
 nuclear->setAntialiased(false);

    regen->setStackingGap(1);
 nuclear->setStackingGap(1);

    // set names and colors:
    regen->setName("nombre de location");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));
   nuclear->setName("nombre de reparation");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));

    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:

   // regen->moveAbove(nuclear);

    // prepare x axis with  labels:
    QVector<double> ticks;
    QVector<QString> labels;
    int i=0;
    QSqlQuery q;
    q.exec("select nom_voiture from voiture");
    while (q.next())
    {
        QString nom_voiture=q.value(0).toString();
        i++;
           ticks<<i;
        labels<<nom_voiture;
        qDebug()<<":nom_voiture"<<nom_voiture<<endl;

            }

            QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 50);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("nbr de reparation et locations par voiture");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> nuclearData, regenData;

int j=0;
QSqlQuery q2, q1;
q2.exec("select nbr_location from voiture");
   while (q2.next())
   {
       int nbr_location = q2.value(0).toInt();
       qDebug()<<"nbr_location :"<<nbr_location<<endl;

       j++;

       regenData <<nbr_location;



   }
   int v=0;
   q1.exec("select nbr_reparation from voiture");
   while (q1.next())
   {
       int nbr_reparation = q1.value(0).toInt();
                qDebug()<<"nbr_reparation :"<<nbr_reparation<<endl;
                nuclearData<<nbr_reparation;
  v++;
   }
   nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}



void MainWindow::on_icon2_17_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(11);//supprimer

}

void MainWindow::on_icon3_15_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(12); //modifier

}

void MainWindow::on_icon4_19_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_icon3_16_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(12); //modifier

}

void MainWindow::on_icon3_17_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(12); //modifier

}

void MainWindow::on_icon4_23_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(9); //ajouter

}


void MainWindow::on_icon2_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(11); //

}

void MainWindow::on_icon4_24_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(10); //
    ui->table_auth->setModel(tmpa.afficher());


}

void MainWindow::on_pushButton_24_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(7); //main auth //done +3

}

void MainWindow::on_a_ajouter_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(9); //ajouter

}

void MainWindow::on_a_modifier_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(12); //modifier

}



void MainWindow::on_a_supprimer_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(11);

}

void MainWindow::on_a_afficher_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(10);
    ui->table_auth->setModel(tmpa.afficher());


}


void MainWindow::on_pushButton_18_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_20_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_21_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_a_filtrer_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_pushButton_26_clicked()
{
    int reff =ui->rcin->currentText().toInt();

    if (ui->rcin->currentText().isEmpty())
     {

         QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Reference  !!!!") ;

     }
    else{
            QSqlQueryModel *model =tmpa.chercher(reff);
          int IDref = model->data(model->index(0,4)).toInt();
           qDebug()<<(IDref);

            if(reff == IDref)
            {
                QMessageBox::information(this," ok ","  trouvé  !!!!") ;
                ui->tabrauth->show();
              ui->tabrauth->setModel(model);

            }
             else
            {
                QMessageBox::critical(0, qApp->tr(""),
                    qApp->tr("reference non trouvé"), QMessageBox::Ok);
}
}
}

void MainWindow::on_icon4_16_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(3); //done
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_12_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_29_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_28_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_7_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();ui->stackedWidget->setCurrentIndex(7); //done

}

void MainWindow::on_login_clicked()  //login
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();

    QString name= ui->pseudo->text();

    QString mdp=ui->mdp->text();

//passwordField->setEchoMode(QLineEdit::Password);

    QSqlQuery  qry;
    if (qry.exec("select * from AUTHENTIFICATION where nom='"+name+"' and pwd='"+mdp+"'"))
    {
       int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(this," ok "," infos are correct  !!!!") ;
            ui->stackedWidget->setCurrentIndex(16);
            notifier->showMessage("Ok"," vous etes connecté",QSystemTrayIcon::Information,10000);


        }
        if (count>1)
        {
            QMessageBox::information(this," ok "," duplicate  !!!!") ;

        }
        if (count<1)
        {
            QMessageBox::information(this," ok "," wrong credentials  !!!!") ;

        }
        qDebug()<<(count);

    }
}

void MainWindow::on_pushButton_25_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_tri_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->affichelv->setModel(tmpv.sortprix());

}

void MainWindow::on_pushButton_33_clicked()
{
    ui->affichelv->setModel(tmpv.sortnom());
}


void MainWindow::on_pushButton_30_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
}

void MainWindow::on_b_ajouter_auth_2_clicked()
{
    notifier->showMessage("Ok","vehicule ajoutée",QSystemTrayIcon::Information,10000);

    bool test;



    auth a(
                ui->nom_a_2->text(),
                ui->prenom_a_2->text(),
                ui->numero_2->text().toInt(),
                ui->role_2->currentText(),
                ui->cin_2->text(),
                ui->pwd_2->text(),
                ui->qs2->currentText(),
                ui->rep_qs2->text()

                );


    test = a.ajouter();



            if (ui->nom_a_2->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom  !!!!") ;

             }

            if (ui->prenom_a_2->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prenom !!!!") ;

             }
            if (ui->numero_2->text().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP numero !!!!") ;

             }



            if (ui->role_2->currentText().isEmpty())
             {

                 QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP role !!!!") ;
            }
            if (ui->cin_2->text().isEmpty())
            {
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP cin !!!!") ;

            }
            if (ui->pwd_2->text().isEmpty())
            {
                QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP mot de passe !!!!") ;

            }



            if(test)
          {


          QMessageBox::information(nullptr, QObject::tr("Ajouter un admin/moderateur "),
                            QObject::tr(" ajoutée.\n"
                                        "Click ok pour quitter."), QMessageBox::Ok);

          }
            else
                QMessageBox::critical(0, qApp->tr("Ajout"),

                                qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);


    ui->nom_a_2->setText("");
    ui->prenom_a_2->setText("");
    ui->numero_2->setText("");
    ui->role_2->setCurrentText("");
    ui->cin_2->setText("");
    ui->pwd_2->setText("");
    ui->qs2->setCurrentText("");
    ui->rep_qs2->setText("");
}



void MainWindow::on_pushButton_37_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_a_ajouter_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_39_clicked()
{
    int id_dep = ui->lineEdit_29->text().toInt();
    QString nom_dep= ui->lineEdit_30->text();
    QString nb_emp_dep= ui->lineEdit_28->text();

  departement  d(id_dep,nom_dep,nb_emp_dep);
  bool testt=d.verifierId(id_dep);


  if(testt)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                  QObject::tr("déjà existant !.\n"
                              "Click Ok to exit."), QMessageBox::Ok);

    }

  else {

      bool test=d.ajouter();
      if(test)
    {

        //  ui->tableView->setModel(tmpd.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un Departement"),
                      QObject::tr("Departement ajouté.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);


      QSqlQueryModel * model = new QSqlQueryModel;
      QSqlQueryModel * model2 = new QSqlQueryModel;

      model->setQuery("SELECT id_dep from departement");
      ui->mid_dept->setModel(model);
      ui->siddep->setModel(model);
      ui->riddep->setModel(model);

      model2->setQuery("select nom_dep from DEPARTEMENT");
       model2->setHeaderData(0, Qt::Horizontal, tr("nom_dep"));
       ui->cbx->setModel(model2);
       ui->cbx2->setModel(model2);

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);
}
  }

void MainWindow::on_mid_dept_activated(const QString &arg1)
{
    int id_dep =ui->mid_dept->currentText().toInt();
    QSqlQuery query;
    query.prepare("SELECT* from DEPARTEMENT where id_dep = :id_dep");
   query.bindValue(":id_dep",id_dep);
 ;    query.exec();
    while (query.next())
    {
        ui->lineEdit_20->setText(query.value(1).toString());
        ui->lineEdit_73->setText(query.value(2).toString());
    }
}

void MainWindow::on_pushButton_43_clicked()
{
    int id_dep = ui->mid_dept->currentText().toInt();
    QString nom_dep= ui->lineEdit_20->text();
    QString nb_emp_dep= ui->lineEdit_73->text();



     departement c;
       bool test;
       test=c.modifier(id_dep,nom_dep,nb_emp_dep);
       if(test)
       {
           //ui->tableView->setModel(tmpdepartement.afficher());

          QMessageBox::information(nullptr,QObject::tr("modifier Departement"),
            QObject::tr(" Departement modifer") ,QMessageBox::Ok);

        QSqlQueryModel * model = new QSqlQueryModel;
          model->setHeaderData(0, Qt::Horizontal, tr("nom_dep"));
          ui->cbx->setModel(model);

         }else

             QMessageBox::critical(nullptr,QObject::tr("modifier Departement"),
               QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_icon4_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(20); //affichage dept
    ui->af_dep->setModel(tmpd.afficher());
}

void MainWindow::on_icon3_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(19); //modifierdep
}

void MainWindow::on_icon4_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_81_clicked()
{
ui->stackedWidget->setCurrentIndex(20);
ui->af_dep->setModel(tmpd.afficher());

}

void MainWindow::on_pushButton_82_clicked()
{
    int id_dep = ui->siddep->currentText().toInt();
        bool test=tmpd.supprimer(id_dep);
        if(test)
        {
            //ui->tableView->setModel(tmpdepartement.afficher());;//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                        QObject::tr("departement supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

            QSqlQueryModel * model = new QSqlQueryModel;
            model->setQuery("SELECT id_dep from departement");
            ui->mid_dept->setModel(model);
            ui->siddep->setModel(model);

              model->setHeaderData(0, Qt::Horizontal, tr("nom_dep"));
              ui->cbx->setModel(model);
              ui->cbx2->setModel(model);
              ui->riddep->setModel(model);


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

}

void MainWindow::on_icon4_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(18); //ajouter
}

void MainWindow::on_icon3_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(19); //modifier
}

void MainWindow::on_icon4_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(20); //afficher
       ui->af_dep->setModel(tmpd.afficher());

}

void MainWindow::on_icon2_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(21); //supprimer
}

void MainWindow::on_icon2_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_icon4_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}


void MainWindow::on_icon2_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_icon3_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_icon4_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->af_dep->setModel(tmpd.afficher());
}

void MainWindow::on_b_vehicules_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}


void MainWindow::on_a_ajouter_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(23); //ajouter personnel
}

void MainWindow::on_pushButton_118_clicked()
{
    int id_personnel = ui->lineEdit_24->text().toInt();
    QString nom= ui->lineEdit_25->text();
    QString prenom= ui->lineEdit_36->text();
    QString adresse= ui->lineEdit_35->text();
    QString grade= ui->lineEdit_34->text();
    int salaire = ui->lineEdit_27->text().toInt();
    int num = ui->lineEdit_26->text().toInt();
    QString dep= ui->cbx->currentText();

  personnel p(id_personnel,nom, prenom,adresse,grade, salaire,num,dep);

  bool testt=p.verifierId(id_personnel);

  if(testt)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("déjà existant !.\n"
                              "Click Ok to exit."), QMessageBox::Ok);

    }
  else
  {
 bool test=p.ajouter();
  if(test)
{

     // ui->tableView_3->setModel(tmppersonnel.afficher());
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("personnel ajouté.\n"
                              "Click Ok to exit."), QMessageBox::Ok);


QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("SELECT id_personnel from personnel");
ui->modifiidperso->setModel(model);
ui->supppersonnel->setModel(model);
ui->recheridpersonnel->setModel(model);


  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Ok to exit."), QMessageBox::Ok);
}
}

void MainWindow::on_a_modifier_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(24); //modifier p
}
void MainWindow::on_modifiidperso_activated(const QString &arg1)
{
    int id_personnel = ui->modifiidperso->currentText().toInt();

    QSqlQuery query;
   query.prepare("SELECT * FROM personnel WHERE id_personnel = :id_personnel");
   query.bindValue(":id_personnel",id_personnel);
   query.exec();

   while(query.next()){

   ui->lineEdit_38->setText(query.value(1).toString());
   ui->lineEdit_92->setText(query.value(2).toString());
  ui->lineEdit_96->setText(query.value(3).toString());
  ui->lineEdit_93->setText(query.value(4).toString());
  ui->lineEdit_94->setText(query.value(5).toString());
  ui->lineEdit_95->setText(query.value(6).toString());
  ui->cbx2->setCurrentText(query.value(7).toString());

   }
}

void MainWindow::on_pushButton_119_clicked()
{
    int id_personnel = ui->modifiidperso->currentText().toInt();
    QString nom= ui->lineEdit_38->text();
    QString prenom= ui->lineEdit_92->text();
    QString adresse= ui->lineEdit_96->text();
    QString grade= ui->lineEdit_93->text();
    int salaire = ui->lineEdit_94->text().toInt();
    int num = ui->lineEdit_95->text().toInt();
    QString dep = ui->cbx2->currentText();



     personnel p;
       bool test;
       test=p.modifier(id_personnel,nom,prenom,adresse,grade,salaire,num,dep);
       if(test)
       {
          //ui->tableView_3->setModel(tmppersonnel.afficher());

          QMessageBox::information(nullptr,QObject::tr("modifier personnel"),
            QObject::tr(" personnel modifer") ,QMessageBox::Ok);

         }else

             QMessageBox::critical(nullptr,QObject::tr("modifier personnel"),
               QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_a_supprimer_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);  // supprimer p
}

void MainWindow::on_pushButton_201_clicked()
{
    int id_personnel = ui->supppersonnel->currentText().toInt();
        bool test=tmpp.supprimer(id_personnel);
        if(test)
        {//ui->tableView_3->setModel(tmpp.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                        QObject::tr("personnel supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("SELECT id_personnel from personnel");
ui->modifiidperso->setModel(model);
ui->supppersonnel->setModel(model);
ui->recheridpersonnel->setModel(model);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_a_afficher_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(26); //affichage personnel
    ui->affi_pers->setModel(tmpp.afficher());
}

void MainWindow::on_icon2_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_icon3_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
}

void MainWindow::on_icon4_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
    ui->affi_pers->setModel(tmpp.afficher());

}

void MainWindow::on_icon4_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}

void MainWindow::on_icon2_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}


void MainWindow::on_icon4_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
    ui->affi_pers->setModel(tmpp.afficher());

}

void MainWindow::on_icon4_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}

void MainWindow::on_icon3_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
}


void MainWindow::on_icon4_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
    ui->affi_pers->setModel(tmpp.afficher());

}

void MainWindow::on_icon4_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}

void MainWindow::on_icon2_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}

void MainWindow::on_icon3_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
}

void MainWindow::on_b_vehicules_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_53_clicked()
{
    QString id_dep = ui->riddep->currentText();
     ui->af_dep->setModel(tmpd.chercher_Dep(id_dep));
}

void MainWindow::on_a_filtrer_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}

void MainWindow::on_b_vehicules_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_b_vehicules_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_b_vehicules_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_a_modifier_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_a_supprimer_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_a_afficher_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->af_dep->setModel(tmpd.afficher());
}

void MainWindow::on_b_vehicules_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_pushButton_48_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}



void MainWindow::on_a_filtrer_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot2->setBackground(QBrush(gradient));

    // create empty bar chart objects:

    QCPBars *fossil = new QCPBars(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
    // gives more crisp, pixel aligned bar borders

    fossil->setAntialiased(false);

    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("salaire");
    fossil->setPen(QPen(QColor(100,149,237).lighter(170)));
    fossil->setBrush(QColor(100,149,237));

    // stack bars on top of each other:


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
     QSqlQuery q;
    int i=0;
    q.exec("select nom from personnel ");
    while (q.next()) {
        QString adresse= q.value(0).toString();
        i++;
        ticks<<i;
        labels <<adresse;
    }

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot2->xAxis->setTicker(textTicker);
    ui->customPlot2->xAxis->setTickLabelRotation(60);
    ui->customPlot2->xAxis->setSubTicks(false);
    ui->customPlot2->xAxis->setTickLength(0, 4);
    ui->customPlot2->xAxis->setRange(0, 8);
    ui->customPlot2->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot2->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot2->xAxis->grid()->setVisible(true);
    ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot2->yAxis->setRange(0, 1000);
    ui->customPlot2->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot2->yAxis->setLabel("Salaire");
    ui->customPlot2->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot2->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->yAxis->setLabelColor(Qt::white);
    ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

 QVector<double> fossilData;
    QVector<double> tickss;

    int ii=0;
    q.exec("select salaire from personnel ");
    while (q.next()) {
        int adresse= q.value(0).toInt();
        ii++;
        tickss<<ii;
        fossilData  <<adresse;
    }
    // Add data:
    fossil->setData(tickss, fossilData);


    // setup legend:
    ui->customPlot2->legend->setVisible(true);
    ui->customPlot2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot2->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot2->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot2->legend->setFont(legendFont);
    ui->customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

void MainWindow::on_pushButton_35_clicked()
{
   ui->stackedWidget->setCurrentIndex(29);
   QMediaPlayer *player = new QMediaPlayer;
   player->setMedia(QUrl("qrc:/click2.wav"));
   player->play();
}

void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_55_clicked()
{
   QString cin = ui->cin_3->text();
   QString rep_qs = ui->repqss->text();
   QSqlQuery qry;


   if (qry.exec("select *from AUTHENTIFICATION where cin='"+cin+"' and rep_qs='"+rep_qs+"'"))
   {
       int count =0;


                  while(qry.next())
                {
                    count++;
                }
                if(count==1)
                {
                    QMessageBox::information(this," ok "," infos are correct  !!!!") ;
                    ui->stackedWidget->setCurrentIndex(16);

                }
                if (count>1)
                {
                    QMessageBox::information(this," ok "," duplicate  !!!!") ;

                }
                if (count<1)
                {
                    QMessageBox::information(this," ok "," wrong credentials  !!!!") ;

                }
                qDebug()<<(count);

            }
}

void MainWindow::on_pushButton_51_clicked()
{
ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_52_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/click2.wav"));
    player->play();

    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_b_ajouterv_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(31);
}

void MainWindow::on_pushButton_59_clicked()
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
        QMessageBox::critical(0,qApp->tr("done"),qApp->tr(" La depense a été ajouter."),QMessageBox::Ok);
     //   ui->dep->setModel(D.rechercher(""));
   //     ui->dep->clearSelection();
         ui->lineEdit_8->clear();
         ui->textEdit->clear();
          ui->lineEdit_10->clear();
           ui->dateEdit_3->clear();





           QSqlQueryModel * model= new QSqlQueryModel;
           model->setQuery("SELECT ref FROM depense");

          ui->lineEdit_9->setModel(model);
         ui->lineEdit_11->setModel(model);
         ui->cmb->setModel(model);


    }

}


void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}


void MainWindow::on_b_modifierv_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(32);
}

void MainWindow::on_pushButton_64_clicked()
{
    QString r=ui->lineEdit_11->currentText();
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
              //ui->dep->setModel(cp.rechercher(""));
             //ui->dep->clearSelection();
             QMessageBox::critical(0,qApp->tr("Ok"),qApp->tr(" La depense a été modifiée."),QMessageBox::Ok);
               ui->textEdit_2->clear();
                 ui->lineEdit_2->clear();
                   ui->lineEdit_11->clear();
                     ui->dateEdit_2->clear();
         }

}

void MainWindow::on_pushButton_66_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_b_supprimerv_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(33);
}


void MainWindow::on_pushButton_67_clicked()
{
    QString ref = ui->lineEdit_9->currentText();
    bool test = tempdep.supprimer(ref);
    if (test)

        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer une depense"),
                        QObject::tr("depense supprimée.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

            QSqlQueryModel * model= new QSqlQueryModel;
            model->setQuery("SELECT ref FROM depense");

           ui->lineEdit_9->setModel(model);
          ui->lineEdit_11->setModel(model);
          ui->cmb->setModel(model);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une depense"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
}


void MainWindow::on_pushButton_69_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_b_afficherv_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(34);
    ui->afficherdepense->setModel(tempdep.afficher());
            //ui->tableView->setModel(tmpdepartement.afficher());
}


void MainWindow::on_pushButton_72_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_b_statv_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(35);
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot3->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->customPlot3->xAxis, ui->customPlot3->yAxis);
    regen->setAntialiased(false);  // gives more crisp, pixel aligned bar borders

    regen->setStackingGap(1);

    // set names and colors:
    regen->setName("montant");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));


    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:

   // regen->moveAbove(nuclear);

    // prepare x axis with  labels:
    QVector<double> ticks;
    QVector<QString> labels;
    int i=0;
    QSqlQuery q;
    q.exec("select date_d from depense");
    while (q.next())
    {
        QString date_d=q.value(0).toString();
        i++;
           ticks<<i;
        labels<<date_d;
        qDebug()<<":date_d"<<date_d<<endl;

            }

            QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot3->xAxis->setTicker(textTicker);
    ui->customPlot3->xAxis->setTickLabelRotation(60);
    ui->customPlot3->xAxis->setSubTicks(false);
    ui->customPlot3->xAxis->setTickLength(0, 4);
    ui->customPlot3->xAxis->setRange(0, 8);
    ui->customPlot3->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot3->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot3->xAxis->grid()->setVisible(true);
    ui->customPlot3->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot3->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot3->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot3->yAxis->setRange(0, 1000);
    ui->customPlot3->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot3->yAxis->setLabel("depenses ");
    ui->customPlot3->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot3->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot3->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot3->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot3->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot3->yAxis->setLabelColor(Qt::white);
    ui->customPlot3->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot3->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;

int j=0;
QSqlQuery q2;
q2.exec("select montant from depense");
   while (q2.next())
   {
       int montant = q2.value(0).toInt();
       qDebug()<<"montant :"<<montant<<endl;

       j++;

       regenData <<montant;



   }
       regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot3->legend->setVisible(true);
    ui->customPlot3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot3->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot3->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot3->legend->setFont(legendFont);
    ui->customPlot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

void MainWindow::on_pushButton_74_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_pushButton_73_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);
}

void MainWindow::on_b_ajouterv_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
}

void MainWindow::on_pushButton_70_clicked()
{
    QString ref = ui->lineEdit_5->text();
    QString id_voiture = ui->lineEdit_6->currentText();
    QString nom = ui->lineEdit_3->text();
    QString etat = ui->lineEdit_7->text();

    emplacement E(ref,id_voiture,nom,etat);

    if(ref.isEmpty() || id_voiture.isEmpty() || nom.isEmpty() || etat.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
        E.Ajouter();
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr(" L'emplacement a été ajouter."),QMessageBox::Yes);
       // ui->tableView->setModel(E.rechercher(""));
        //ui->tableView->clearSelection();
         ui->lineEdit_5->clear();
          ui->lineEdit_3->clear();

           ui->lineEdit_7->clear();QSqlQueryModel * model= new QSqlQueryModel;
           model->setQuery("SELECT REF_EMPLACEMENT FROM emplacement");
           ui->lineEdit_12->setModel(model);
           ui->lineEdit_4->setModel(model);
            ui->cmbbb->setModel(model);



}
}


void MainWindow::on_lineEdit_12_activated(const QString &arg1)
{
   QString ref_emplacement = ui->lineEdit_12->currentText();
   QSqlQuery query;

   query.prepare("SELECT * FROM emplacement where ref_emplacement = :ref_emplacement");
   query.bindValue(":ref_emplacement",ref_emplacement);
   query.exec();

   while(query.next())
   {
       ui->lineEdit_14->setText(query.value(1).toString());
       ui->lineEdit_15->setText(query.value(2).toString());
       ui->lineEdit_13->setText(query.value(3).toString());
   }


}

void MainWindow::on_pushButton_80_clicked()
{
    QString ref = ui->lineEdit_12->currentText();
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
        QMessageBox::critical(0,qApp->tr("ok"),qApp->tr(" L'emplacement a été modifié."),QMessageBox::Ok);
        //ui->tableView->setModel(E.rechercher(""));
       // ui->tableView->clearSelection();
         ui->lineEdit_12->clear();
         ui->lineEdit_14->clear();
          ui->lineEdit_15->clear();
           ui->lineEdit_13->clear();
    }
}

void MainWindow::on_b_modifierv_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_b_supprimerv_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);
}

void MainWindow::on_pushButton_85_clicked()
{
    QString ref = ui->lineEdit_4->currentText();
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
           tempemp.supprimer(ref);
            QMessageBox::critical(0,qApp->tr("ok"),
                                  qApp->tr("emplacement supprimer"),QMessageBox::Ok);
            ui->lineEdit_7->clear();QSqlQueryModel * model= new QSqlQueryModel;
            model->setQuery("SELECT REF_EMPLACEMENT FROM emplacement");
            ui->lineEdit_12->setModel(model);
            ui->lineEdit_4->setModel(model);
             ui->cmbbb->setModel(model);

        }

    }

}

void MainWindow::on_pushButton_83_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);
}

void MainWindow::on_pushButton_79_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);

}

void MainWindow::on_pushButton_77_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);

}

void MainWindow::on_b_afficherv_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(40);
    ui->afficher_emp->setModel(tempemp.afficher());

}

void MainWindow::on_pushButton_87_clicked()
{
   ui->stackedWidget->setCurrentIndex(36);
}

void MainWindow::on_icon4_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
}

void MainWindow::on_icon3_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_icon4_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(40);
    ui->afficher_emp->setModel(tempemp.afficher());

}

void MainWindow::on_icon4_52_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
}

void MainWindow::on_icon2_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);
}

void MainWindow::on_icon4_51_clicked()
{
 ui->stackedWidget->setCurrentIndex(40);
 ui->afficher_emp->setModel(tempemp.afficher());

}

void MainWindow::on_icon2_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);
}

void MainWindow::on_icon3_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
}


void MainWindow::on_icon4_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(40);
    ui->afficher_emp->setModel(tempemp.afficher());

}

void MainWindow::on_icon4_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(37);
}


void MainWindow::on_icon2_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(39);
}

void MainWindow::on_icon3_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::on_pushButton_75_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::on_pushButton_91_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_90_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_93_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}

void MainWindow::on_b_ajouterv_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}

void MainWindow::on_pushButton_94_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int REF = ui->lineEdit_ref_2->text().toInt();
    QString NOM= ui->lineEdit_nom_3->text();
    QString PRENOM= ui->lineEdit_prenom_2->text();
     int CIN = ui->lineEdit_cin_3->text().toInt();
     QString ADRESSE= ui->lineEdit_adresse_3->text();
      QString DATE1= ui->lineEdit_date1_2->text();
       QString NBR_JOURS= ui->lineEdit_nbr_jours_2->text();
       QString IDV = ui->cbx4->currentText();
  client c(REF,NOM,PRENOM,CIN,ADRESSE,DATE1,NBR_JOURS,IDV);
  bool test=c.ajouter();
  if(test)

    {
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click ok to exit."), QMessageBox::Ok);

QSqlQueryModel * model= new QSqlQueryModel;

model->setQuery("SELECT REF FROM client");
ui->reffmodifier->setModel(model);
ui->refsup->setModel(model);
ui->rechercherref->setModel(model);

    }
  else
     { QMessageBox::information(nullptr, QObject::tr("Ajout"),
                                QObject::tr("Erreur "), QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_99_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}

void MainWindow::on_b_modifierv_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_reffmodifier_activated(const QString &arg1)
{
    int ref = ui->reffmodifier->currentText().toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE REF = :REF");
    query.bindValue(":REF",ref);
    query.exec();

    while(query.next()){
        ui->lineEdit_nom_6->setText(query.value(1).toString());
        ui->lineEdit_prenom_4->setText(query.value(2).toString());
        ui->lineEdit_cin_6->setText(query.value(3).toString());
        ui->lineEdit_adresse_6->setText(query.value(4).toString());
        ui->lineEdit_date1_4->setText(query.value(5).toString());
        ui->lineEdit_nbr_jours_4->setText(query.value(6).toString());
        ui->cbx3->setCurrentText(query.value(7).toString());


}
}

void MainWindow::on_pushButton_modifierClient_3_clicked()
{
    int ref = ui->reffmodifier->currentText().toInt();
    QString nom= ui->lineEdit_nom_6->text();
    QString prenom= ui->lineEdit_prenom_4->text();
     int cin = ui->lineEdit_cin_6->text().toInt();
     QString adresse= ui->lineEdit_adresse_6->text();
      QString date1= ui->lineEdit_date1_4->text();
       QString nbr_jours= ui->lineEdit_nbr_jours_4->text();
       QString IDV = ui->cbx3->currentText();

  client c(ref,nom,prenom,cin,adresse,date1,nbr_jours,IDV);
  bool test=c.modifier(ref);
  if(test)
{//ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("client modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_101_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}

void MainWindow::on_icon4_59_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}

void MainWindow::on_b_supprimerv_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}

void MainWindow::on_pb_supprimer_3_clicked()
{
    int ref = ui->refsup->currentText().toInt();
     bool test=tmpclient.supprimer(ref);
     if(test)
     {//ui->tabclientf->setModel(tmpclientf.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("CLIENT supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

         QSqlQueryModel * model= new QSqlQueryModel;

         model->setQuery("SELECT REF FROM client");
         ui->reffmodifier->setModel(model);
         ui->refsup->setModel(model);
         ui->rechercherref->setModel(model);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_icon4_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}


void MainWindow::on_icon3_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_pushButton_103_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}

void MainWindow::on_b_afficherv_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(45);
    ui->afficherclient->setModel(tmpclient.afficher());
}

void MainWindow::on_pushButton_104_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}
/*
void MainWindow::on_pushButton_105_clicked()
{

    //int ref = ui->rref->text().toInt();
   // if (ui->rref->text().isEmpty())


    {
        QMessageBox::information(this, "erreur", "Veuillez verifier le champ ref!!!");
    }
    else {

  //      QSqlQueryModel *model =tmpclient.r(ref);
        int IDref= model->data(model->index(0,0)).toInt();



            if(ref == IDref)
            {
 QMessageBox::information(this, "ok", "produit trouvé");

                ui->afficherclient->show();
                ui->afficherclient->setModel(model);
            }
             else
            {
                QMessageBox::critical(0, qApp->tr(""),
                    qApp->tr("reference non trouvé"), QMessageBox::Ok);
            }
}
}
*/
void MainWindow::on_pushButton_106_clicked()
{
    ui->afficherclient->setModel(tmpclient.tri());

}

void MainWindow::on_icon3_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_icon2_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}

void MainWindow::on_icon4_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(42);
}

void MainWindow::on_icon4_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(45);
    ui->afficherclient->setModel(tmpclient.afficher());
}

void MainWindow::on_icon2_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}

void MainWindow::on_icon4_60_clicked()
{
    ui->stackedWidget->setCurrentIndex(45);
    ui->afficherclient->setModel(tmpclient.afficher());


}

void MainWindow::on_icon2_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(44);
}

void MainWindow::on_icon3_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(43);
}

void MainWindow::on_icon4_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(45);
    ui->afficherclient->setModel(tmpclient.afficher());
}

void MainWindow::on_pushButton_97_clicked()
{
ui->stackedWidget->setCurrentIndex(46);

}

void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_b_ajouterv_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(47);
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
    {//ui->tabclientf->setModel(tmpclientf.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client fidéle"),
                      QObject::tr("client fidéle ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
   QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
    ui->supprimerref->setModel(model);
    ui->modifiermatricule->setModel(model);

    ui->cbx7->setModel(model);
    }
}

void MainWindow::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentIndex(46);
}

void MainWindow::on_b_modifierv_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(48);
   }

void MainWindow::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(46);
}


void MainWindow::on_icon4_67_clicked()
{
    ui->stackedWidget->setCurrentIndex(47);
}



void MainWindow::on_icon2_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(49);

}

void MainWindow::on_icon4_68_clicked()
{
    ui->stackedWidget->setCurrentIndex(50);
    ui->afficherclientc->setModel(tmpclientf.afficher());

}

void MainWindow::on_modifiermatricule_activated(const QString &arg1)
{
    int MATRICULE_FISCALE = ui->modifiermatricule->currentText().toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM client_fidele WHERE MATRICULE_FISCALE = :MATRICULE_FISCALE");
    query.bindValue(":MATRICULE_FISCALE",MATRICULE_FISCALE);
    query.exec();
    while (query.next())
    {
        ui->lineEdit_nom_12->setText(query.value(1).toString());
        ui->lineEdit_nom_13->setText(query.value(2).toString());
       ui->lineEdit_nom_14->setText(query.value(3).toString());
       ui->lineEdit_nom_15->setText(query.value(4).toString());

    }
}

void MainWindow::on_pushButton_modifierClient_2_clicked()
{
    int MATRICULE_FISCALE = ui->modifiermatricule->currentText().toInt();
    QString nom= ui->lineEdit_nom_12->text();
     QString cin = ui->lineEdit_nom_13->text();
     QString adresse= ui->lineEdit_nom_14->text();
      QString adresse_mail= ui->lineEdit_nom_15->text();

  client_fidele cf(MATRICULE_FISCALE,nom,cin,adresse,adresse_mail);
  bool test=cf.modifier(MATRICULE_FISCALE);
  if(test)
{//ui->tabclientf->setModel(tmpclientf.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client fidéle"),
                  QObject::tr("client fidéle modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier CLIENT FIDELE"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_b_supprimerv_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(49);
}

void MainWindow::on_icon4_69_clicked()
{
    ui->stackedWidget->setCurrentIndex(47);
}

void MainWindow::on_icon3_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(48);
}

void MainWindow::on_pushButton_116_clicked()
{
    ui->stackedWidget->setCurrentIndex(46);
}


void MainWindow::on_icon4_70_clicked()
{
    ui->stackedWidget->setCurrentIndex(50);
    ui->afficherclientc->setModel(tmpclientf.afficher());

}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int MATRICULE_FISCALE = ui->supprimerref->currentText().toInt();
     bool test=tmpclientf.supprimer(MATRICULE_FISCALE);
     if(test)
     {//ui->tabclientf->setModel(tmpclientf.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("CLIENT supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         QSqlQueryModel * model= new QSqlQueryModel;
          model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");
          ui->supprimerref->setModel(model);
          ui->modifiermatricule->setModel(model);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un CLIENT"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_120_clicked()
{
    ui->stackedWidget->setCurrentIndex(46);
}

void MainWindow::on_icon2_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(49);
}

void MainWindow::on_icon3_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(48);
}

void MainWindow::on_icon4_71_clicked()
{
    ui->stackedWidget->setCurrentIndex(47);
}

void MainWindow::on_b_afficherv_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(50);
    ui->afficherclientc->setModel(tmpclientf.afficher());
}

void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(36);
}

void MainWindow::on_icon4_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(34);
    ui->afficherdepense->setModel(tempdep.afficher());

}

void MainWindow::on_icon4_48_clicked()
{

}

void MainWindow::on_pushButton_110_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_pushButton_122_clicked()
{
    int id_personnel = ui->recheridpersonnel->currentText().toInt();
    ui->apr->setModel(tmpp.chercher_pers(id_personnel));

}

void MainWindow::on_a_filtrer_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(51);
}

void MainWindow::on_pushButton_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}

void MainWindow::on_pushButton_121_clicked()
{
    ui->affi_pers->setModel(tmpp.afficher_tri_ID());
}

void MainWindow::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::on_icon3_30_clicked() //modifier depense
{
    ui->stackedWidget->setCurrentIndex(32);

}

void MainWindow::on_icon2_32_clicked()//supprimer depense
{
    ui->stackedWidget->setCurrentIndex(33);

}

void MainWindow::on_icon2_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(33);

}

void MainWindow::on_icon4_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(31);

}

void MainWindow::on_icon4_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(31);

}

void MainWindow::on_icon3_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(32);

}

void MainWindow::on_icon4_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(34);
    ui->afficherdepense->setModel(tempdep.afficher());


}

void MainWindow::on_icon4_47_clicked()//ajouter
{
    ui->stackedWidget->setCurrentIndex(31);

}

void MainWindow::on_icon4_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(34);
    ui->afficherdepense->setModel(tempdep.afficher());

}

void MainWindow::on_lineEdit_11_activated(const QString &arg1)
{
    QString ref = ui->lineEdit_11->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM depense where ref = :ref");
    query.bindValue(":ref",ref);
    query.exec();


    while(query.next())
    {
        ui->textEdit_2->setText(query.value(1).toString());
       ui->lineEdit_2->setText(query.value(2).toString());

    }

}

void MainWindow::on_pushButton_123_clicked()
{
    QString ref = ui->cmb->currentText();
    ui->afficherdepense->setModel(tempdep.rechercher(ref));
}

void MainWindow::on_pushButton_124_clicked() //croissant
{
    ui->afficherdepense->setModel(tempdep.tri1());
}

void MainWindow::on_pushButton_125_clicked() //decroissant
{
    ui->afficherdepense->setModel(tempdep.tri2());
}

void MainWindow::on_pushButton_126_clicked()
{
    QString ref = ui->cmbbb->currentText();
    ui->afficher_emp->setModel(tempemp.rechercher(ref));
}

void MainWindow::on_pushButton_127_clicked()
{
    //croi
    ui->afficher_emp->setModel(tempemp.tri1());
}

void MainWindow::on_pushButton_128_clicked()
{
    ui->afficher_emp->setModel(tempemp.tri2());
}

void MainWindow::on_pushButton_129_clicked()
{
    QPrinter print;
    print.setPrinterName("imprimer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->afficher_emp->render(&print);
}

void MainWindow::on_pushButton_130_clicked()
{
    QPrinter print;
    print.setPrinterName("imprimer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->afficherdepense->render(&print);
}

void MainWindow::on_comboBox_activated(const QString &arg1) //id vehicule
{


}
void MainWindow::on_lineEdit_6_activated(const QString &arg1)
{
    QString id_voiture = ui->lineEdit_6->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM voiture WHERE id_voiture = :id_voiture");
    query.bindValue(":id_voiture",id_voiture);
    query.exec();

    while(query.next()){
    ui->lineEdit_3->setText(query.value(1).toString());
    }
    }



void MainWindow::on_pushButton_105_clicked()
{
    int ref = ui->rechercherref->currentText().toInt();
    ui->afficherclient->setModel(tmpclient.rechercher(ref));
}

void MainWindow::on_pushButton_131_clicked() //save
{

}

void MainWindow::on_icon2_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(49);

}



void MainWindow::on_icon4_66_clicked()
{
    ui->stackedWidget->setCurrentIndex(50);
    ui->afficherclientc->setModel(tmpclientf.afficher());


}

void MainWindow::on_icon3_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(48);

}



void MainWindow::on_pushButton_108_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}



void MainWindow::on_b_ajouterv_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(53);
}

void MainWindow::on_pushButton_711_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel;
    model->setQuery("SELECT MATRICULE_FISCALE FROM client_fidele");

    int MAT=ui->cbx7->currentText().toInt();
      QString NOM= ui->lineEdit_matricule_8->text();






    //ui->tabWidget->setCurrentIndex(14);

    chauffeure ch(MAT,NOM);
    bool test=ch.ajouter();
    if(test)
  {
  QMessageBox::information(nullptr, QObject::tr("Ajouter un chauffeure"),
                    QObject::tr("chauffeure disponible.\n"
                                "Click ok to exit."), QMessageBox::Ok);

  QSqlQueryModel * model = new QSqlQueryModel();
 // model->setQuery("SELECT VOITURE.CHAUFFEUR, CHAUFFEURE.MATRICULE_FISCALE from VOITURE INNER JOIN CHAUFFEURE ON VOITURE.CHAUFFEUR = CHAUFFEURE.MATRICULE_FISCALE");
  model->setQuery("SELECT MATRICULE_FISCALE FROM CHAUFFEURE ");
  ui->cbx1->setModel(model);

}
}

void MainWindow::on_pushButton_723_clicked()
{
    ui->stackedWidget->setCurrentIndex(52);
}

void MainWindow::on_pushButton_139_clicked()
{
    ui->stackedWidget->setCurrentIndex(41);
}

void MainWindow::on_icon4_73_clicked()
{
    ui->stackedWidget->setCurrentIndex(54);
   ui->tabchauffeur->setModel(tmpc.afficher());
}

void MainWindow::on_b_afficherv_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(54);
    ui->tabchauffeur->setModel(tmpc.afficher());
}

void MainWindow::on_pushButton_724_clicked()
{
    ui->stackedWidget->setCurrentIndex(52);
}

void MainWindow::on_pushButton_133_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_727_clicked()
{
    //affichelv
    ui->affichelv->setModel(tmpv.aff());
}

void MainWindow::on_new_2_clicked()
{

        QSqlQueryModel * model= new QSqlQueryModel;
        model->setQuery("SELECT DISPONIBILITE FROM VOITURE ");
        ui->cbx8->setModel(model);
        cout<<"fffffffffffffffffffffffffé"<<endl;

}



void MainWindow::on_cbx8_activated(const QString &arg1)
{

    QString id=ui->cbx8->currentText();
    ui->afficher_emp->setModel(tempemp.metierCommun(id));
}

void MainWindow::on_pushButton_714_clicked()
{
    ui->stackedWidget->setCurrentIndex(52);
}

void MainWindow::on_pbbb_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_b_vehicules_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_a_ajouter_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(56);
}

void MainWindow::on_pushButton_141_clicked()
{
    int id_voiture = ui->comboBox_9->currentText().toInt();
    QString nom= ui->lineEdit_32->text();
    QString prenom= ui->lineEdit_40->text();
    QString tel= ui->lineEdit_33->text();
    QDate datee=ui->dateEdit_9->date();

    contrat  d(id_voiture,nom,prenom, tel,datee);
  bool testt=d.verifierId_voiture(id_voiture);


  if(testt)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Contrat"),
                  QObject::tr("déjà existant !.\n"
                              "Click Ok to exit."), QMessageBox::Ok);

    }

  else {

      bool test=d.ajouter();
      if(test)
    {

    QMessageBox::information(nullptr, QObject::tr("Ajouter un Contrat"),
                      QObject::tr("Contrat ajouté.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Contrat"),
                      QObject::tr("Erreur !.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);
}

  /*QSqlQueryModel *model2 = new QSqlQueryModel;
  model2->setQuery("select id_voiture from voiture");
  ui->comboBox_7->setModel(model2);
  QSqlQueryModel *model = new QSqlQueryModel;*/

}

void MainWindow::on_b_vehicules_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_pushButton_143_clicked()
{
    int id_voiture = ui->comboBox_8->currentText().toInt();
    QString nom= ui->lineEdit_39->text();
    QString prenom= ui->lineEdit_43->text();
    QString tel= ui->lineEdit_33->text();
    QDate datee=ui->dateEdit_10->date();

    QSqlQueryModel *model3 = new QSqlQueryModel;
    model3->setQuery("select id_voiture from voiture");
    ui->comboBox_8->setModel(model3);



     contrat c;
       bool test;
       test=c.modifier(id_voiture,nom,prenom, tel,datee);
       if(test)
       {

          QMessageBox::information(nullptr,QObject::tr("modifier contrat"),
            QObject::tr(" contrat modifer") ,QMessageBox::Ok);

         }else

             QMessageBox::critical(nullptr,QObject::tr("modifier contrat"),
               QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}


void MainWindow::on_icon3_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(57);
}

void MainWindow::on_comboBox_8_activated(const QString &arg1)
{
    QString id_voiture = ui->comboBox_8->currentText();
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRAT WHERE id_voiture = :id_voiture");
    query.bindValue(":id_voiture",id_voiture);
    query.exec();
    while(query.next()){
        ui->lineEdit_39->setText(query.value(2).toString());
        ui->lineEdit_43->setText(query.value(3).toString());
        ui->lineEdit_41->setText(query.value(4).toString());

    }
}

void MainWindow::on_icon3_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(57);
}


void MainWindow::on_supprimeridc_clicked()
{
    int idd = ui->cbsupp->currentText().toInt();
    bool test=tmpcontrat.supprimer(idd);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un contrat"),
                    QObject::tr("Contrat supprimé.\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("Supprimer un contrat"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }
    QSqlQueryModel *model2 = new QSqlQueryModel;
    model2->setQuery("select id_voiture from contrat");
    ui->comboBox_8->setModel(model2);
    ui->comboBox_9->setModel(model2);
}

void MainWindow::on_icon2_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(58);

}

void MainWindow::on_icon4_80_clicked()
{
    ui->stackedWidget->setCurrentIndex(59);
    ui->affichercontrat->setModel(tmpcontrat.afficher());


}

void MainWindow::on_icon4_75_clicked()
{
    ui->stackedWidget->setCurrentIndex(59);
    ui->affichercontrat->setModel(tmpcontrat.afficher());

}

void MainWindow::on_icon4_78_clicked()
{
    ui->stackedWidget->setCurrentIndex(59);
    ui->affichercontrat->setModel(tmpcontrat.afficher());

}

void MainWindow::on_print_clicked()
{
    QPrinter print;
    print.setPrinterName("imprimer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->affichercontrat->render(&print);
}


void MainWindow::on_trierdept_clicked()
{
    ui->af_dep->setModel(tmpd.afficher_tri_ID());

}

void MainWindow::on_b_vehicules_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_a_modifier_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(57);
}

void MainWindow::on_a_supprimer_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(58);
}

void MainWindow::on_a_afficher_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(59);
}

void MainWindow::on_icon2_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(58);
}

void MainWindow::on_b_vehicules_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_b_vehicules_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_icon4_76_clicked()
{
    ui->stackedWidget->setCurrentIndex(56);
}

void MainWindow::on_icon4_82_clicked()
{
    ui->stackedWidget->setCurrentIndex(56);
}

void MainWindow::on_icon3_47_clicked()
{
    ui->stackedWidget->setCurrentIndex(57);
}

void MainWindow::on_icon2_48_clicked()
{
    ui->stackedWidget->setCurrentIndex(58);
}

void MainWindow::on_b_vehicules_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}

void MainWindow::on_icon3_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(57);
}

void MainWindow::on_b_vehicules_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(55);
}
