#ifndef CHAUFFEURE_H
#define CHAUFFEURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class chauffeure
{public:
    chauffeure();
    chauffeure(int,QString);
    int get_MATRICULE_FISCALE();
    QString get_NOM();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);


private:
    QString NOM;
    int MATRICULE_FISCALE;
};

#endif // CHAUFFEURE_H
