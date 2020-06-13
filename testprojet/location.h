#ifndef LOCATION_H
#define LOCATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class location
{
public:
    location();
    location(int,int,QString,QDate,QDate,QString,int);
        bool ajouter();
        QSqlQueryModel* afficher();
        QSqlQueryModel* chercher(int);
        bool supprimer(int);
        QSqlQueryModel* trier_location_id();
        QSqlQueryModel* trier_location_decroi_id();
        QSqlQueryModel* trier_location_alpha();
    private:
        int idc,idv,montant_location;
        QString marque,status;
        QDate date_location,date_expiration;
};

#endif // LOCATION_H
