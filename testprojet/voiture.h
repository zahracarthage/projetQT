
#include <QString>
#include<QSqlQuery>
#include <QSqlQueryModel>

class voiture
{
    QString id_voiture ;
    QString nom_voiture;
    QString prix;
    QString nbr_location;
    QString nbr_reparation;
    QString disponibilite;
public:
    voiture();
    voiture(QString ,QString, QString, QString, QString);

    voiture(QString, QString ,QString, QString, QString, QString);
    QString getid();
    QString getnom();
    QString getprix();
    QString getnbrlocation();
    QString getnbrreparation();
    QString getdispo();


    bool ajouter_voiture();
    bool verif(QString id);
    QSqlQueryModel * afficher_voiture();
    bool supprimer_voiture(QString id_voiture);
    QSqlQueryModel *chercher_voiture(QString id_voiture);
    bool modifier_voiture();
    QSqlQueryModel *sortnom();
    QSqlQueryModel *sortnbrloca();
    QSqlQueryModel *sortprix();
   QSqlQueryModel * aff();



};
