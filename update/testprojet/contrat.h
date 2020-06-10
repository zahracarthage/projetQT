#ifndef CONTRAT_H
#define CONTRAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>
class contrat
{
public:
    contrat();

    contrat(int, QString, QString, QString, QDate);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id_contrat);
    bool modifier(int id_voiture, QString nom,QString prenom,QString tel,QDate datee);
    QSqlQueryModel * chercher_voiture(QString id);
    QSqlQueryModel *  afficher_tri_ID();
    bool verifierId_voiture(int Id_voiture);
private:
    int id_voiture;
    QString nom;
    QString prenom;
    QString tel;
    QDate datee;
};

#endif // CONTRAT_H
