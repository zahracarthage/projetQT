#include "auth.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>

auth::auth()
{

    nom="";
    prenom="";
    numero=0;
    role="";
    cin="";
    pwd="";
    question_secrete="";
    rep_qs="";
}
//  auth(int, QString, QString, int, QString);
//    auth(QString, QString, int, QString);


auth::auth(QString nom, QString prenom, int numero, QString role, QString cin, QString pwd, QString question_secrete, QString rep_qs)
{
    this->nom=nom;
    this->prenom=prenom;
    this->numero=numero;
    this->role=role;
    this->cin=cin;
    this->pwd=pwd;
    this->question_secrete=question_secrete;
    this->rep_qs=rep_qs;
}


QString auth::getnom()
{
    return nom;
}
QString auth::getprenom()
{
    return prenom;
}
int auth::getnumero()
{
    return numero;
}
QString auth::getrole()
{
    return role;
}
QString auth::getcin()
{
    return cin;
}
QString auth::getpwd()
{
    return pwd;
}
QString auth::getquestion_secrete()
{
    return question_secrete;
}
QString auth::getrep_qs()
{
    return rep_qs;
}

bool auth::ajouter()
{

    QSqlQuery query;

    QString res2 = QString::number(numero);

    query.prepare("INSERT INTO AUTHENTIFICATION (nom,prenom, numero, role, cin, pwd, question_secrete, rep_qs) VALUES (:nom, :prenom, :numero, :role, :cin, :pwd, :question_secrete, :rep_qs)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":numero", numero);
    query.bindValue(":role", role);
    query.bindValue(":cin", cin);
    query.bindValue(":pwd", pwd);
    query.bindValue(":question_secrete", question_secrete);
    query.bindValue(":rep_qs",rep_qs);


    return query.exec();
}

QSqlQueryModel *auth::chercher(int cin)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from AUTHENTIFICATION where cin = ? ");
    query.addBindValue(cin);
    query.exec();


    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("role"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("pwd"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("question_secrete"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("rep_qs"));


  return model;
}


QSqlQueryModel * auth::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from authentification");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("role"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("cin"));

    return model;
}


bool auth::modifier()
{
     QSqlQuery query;

    QString res1 =QString::number(numero);


    query.prepare(" UPDATE authentification set  NOM = :nom, PRENOM = :prenom, NUMERO = :numero, ROLE = :role, PWD = :pwd, QUESTION_SECRETE = :question_secrete, REP_QS = :rep_qs   where CIN  = :cin ");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":numero",res1);
    query.bindValue(":role",role);
    query.bindValue(":cin",cin);
    query.bindValue(":pwd",pwd);
    query.bindValue(":question_secrete", question_secrete);
    query.bindValue(":rep_qs",rep_qs);

    return query.exec();
}

bool auth::supprimer(int cin)
{

    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("Delete from authentification where cin = :cin ");
    query.bindValue(":cin", cin);
    return    query.exec();
}

bool auth::verifierexcin(QString cin)
{
    QSqlQuery query;
    QString n;
            query.exec("SELECT cin from authentification");
            while (query.next())
            {
               n =query.value("cin").toString();
                if (n==cin)
                {
                    return true;
                }
            }
    return false;



}


QSqlQueryModel *auth::sortcin()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from authentification ORDER BY CIN ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("role"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("cin"));

    return model;
}



