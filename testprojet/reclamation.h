#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class reclamation
{
    QString id_reclamation;
    QString etat;
    QString idc;
    QString idv;
    QString description;

public:
    reclamation();
    reclamation(QString, QString,QString, QString, QString);
    reclamation (QString, QString,QString,QString);

    QString getid();
    QString getetat();
    QString getidv();
    QString getidc();
    QString getdescription();

    bool ajouter_reclamation();
    QSqlQueryModel *afficher_reclamation();
    bool supprimer_reclamation(QString id_reclamation);
    QSqlQueryModel *chercher_reclamation(QString id_reclamation);
    bool modifier_reclamation();
    QSqlQueryModel *sort();
};

#endif // RECLAMATION_H
