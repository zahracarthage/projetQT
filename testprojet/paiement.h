#ifndef PAIEMENT_H
#define PAIEMENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class paiement
{
public:
    paiement();
    paiement(int,int,QString,int,QDate);
    bool ajouter();
            QSqlQueryModel* afficher();
            QSqlQueryModel* chercher(int);
            bool supprimer(int);
            QSqlQueryModel* trier_location_id();
            QSqlQueryModel* trier_location_decroi_id();
            QSqlQueryModel* trier_location_alpha();
        private:
            int idc,idv,prix;
            QString marque;
            QDate date_paiement;
};

#endif // PAIEMENT_H
