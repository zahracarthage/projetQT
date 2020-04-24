#ifndef CLIENT_FIDELE_H
#define CLIENT_FIDELE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class client_fidele
{public:
    client_fidele();
    client_fidele(int,QString,QString,QString,QString);
     int get_MATRICULE_FISCALE();
    QString get_NOM();
   QString  get_CIN();
     QString get_ADRESSE();
      QString get_ADRESSE_MAIL();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
private:
    QString NOM,CIN,ADRESSE,ADRESSE_MAIL;
int MATRICULE_FISCALE;
};
























#endif // CLIENT_FIDELE_H
