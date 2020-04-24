#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client
{public:
    client();
    client(int,QString,QString,int,QString,QString,QString);
    int get_REF();
    QString get_NOM();
    QString get_PRENOM();
    int get_CIN();
     QString get_ADRESSE();
      QString get_DATE1();
       QString get_NBR_JOURS();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();

private:
    QString NOM,PRENOM,ADRESSE,DATE1,NBR_JOURS;
    int REF,CIN;
};

#endif // CLIENT_H
