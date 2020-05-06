#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "voiture.h"
#include "auth.h"
#include "departement.h"
#include "personnel.h"
#include "depenses.h"
#include "client.h"
#include "client_fidele.h"
#include "emplacement.h"
#include <qsystemtrayicon.h>
#include "connexion.h"
#include <QStandardItemModel>
#include "qcustomplot.h"
#include <QSqlTableModel>
#include <QSoundEffect>
#include <QSound>
#include <QMediaPlayer>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;


             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

        voiture tmpv;
        auth tmpa;
        personnel tmpp;
        departement tmpd;
        depenses tempdep;
        emplacement tempemp;
        client tmpclient;
        client_fidele tmpclientf;

        void make_plot();


private slots:

    void on_ajouter_clicked();

    void on_pushButton_clicked();

    void on_voiture_clicked();

    void on_b_ajouterv_clicked();


    void on_b_modifierv_clicked();

    void on_b_afficherv_clicked();



    void on_supprimerid_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_b_supprimerv_clicked();

    void on_icon4_10_clicked();

    void on_icon2_13_clicked();

    void on_icon3_11_clicked();

    void on_icon4_15_clicked();

    void on_icon4_9_clicked();

    void on_pushButton_8_clicked();

    void on_icon3_12_clicked();

    void on_icon2_14_clicked();

    void on_icon4_12_clicked();

    void on_icon4_14_clicked();

    void on_icon3_13_clicked();

    void on_icon4_13_clicked();

    void on_icon2_16_clicked();

    void on_pushButton_5_clicked();

    void on_b_vehicules_clicked();


    void on_b_ajouter_auth_clicked();


    void on_afficher_auth_clicked();

    void on_icon4_17_clicked();

    void on_icon2_18_clicked();

    void on_supprimer_auth_clicked();

    void on_icon4_21_clicked();

    void on_icon4_22_clicked();

    void on_pushButton_2_clicked();



    void on_b_statv_clicked();

    void on_icon2_17_clicked();

    void on_icon3_15_clicked();

    void on_icon4_19_clicked();

    void on_icon3_16_clicked();

    void on_icon3_17_clicked();

    void on_icon4_23_clicked();

    void on_icon2_20_clicked();

    void on_icon4_24_clicked();

    void on_pushButton_24_clicked();

    void on_a_ajouter_clicked();

    void on_a_modifier_clicked();

    void on_a_supprimer_clicked();

    void on_a_afficher_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_a_filtrer_clicked();

    void on_pushButton_26_clicked();

    void on_icon4_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_7_clicked();

    void on_login_clicked();

    void on_pushButton_25_clicked();

    void on_tri_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_30_clicked();


    void on_b_ajouter_auth_2_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_a_ajouter_2_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_43_clicked();

    void on_icon4_28_clicked();

    void on_icon3_21_clicked();

    void on_icon4_29_clicked();

    void on_pushButton_81_clicked();

    void on_pushButton_82_clicked();

    void on_icon4_32_clicked();

    void on_icon3_22_clicked();

    void on_icon4_31_clicked();

    void on_icon2_23_clicked();

    void on_icon2_22_clicked();

    void on_icon4_27_clicked();

    void on_icon2_21_clicked();

    void on_icon3_19_clicked();

    void on_icon4_26_clicked();

    void on_b_vehicules_3_clicked();

    void on_a_ajouter_3_clicked();

    
    
    
   void on_pushButton_118_clicked();

    void on_a_modifier_3_clicked();

   void on_pushButton_119_clicked();

    void on_a_supprimer_3_clicked();

    void on_pushButton_201_clicked();

    void on_a_afficher_3_clicked();

    void on_icon2_25_clicked();

    void on_icon3_23_clicked();

    void on_icon4_34_clicked();

    void on_icon4_35_clicked();

    void on_icon2_26_clicked();

    void on_icon4_36_clicked();

    void on_icon4_37_clicked();

    void on_icon3_25_clicked();

    void on_icon4_38_clicked();

    void on_icon4_39_clicked();

    void on_icon2_28_clicked();

    void on_icon3_26_clicked();

    void on_b_vehicules_7_clicked();

    void on_pushButton_53_clicked();

    void on_a_filtrer_2_clicked();

    void on_b_vehicules_12_clicked();

    void on_b_vehicules_4_clicked();

    void on_b_vehicules_5_clicked();

    void on_a_modifier_2_clicked();

    void on_a_supprimer_2_clicked();

    void on_a_afficher_2_clicked();

    void on_b_vehicules_6_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_48_clicked();

    void on_a_filtrer_4_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_58_clicked();

    void on_b_ajouterv_2_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_62_clicked();

    void on_b_modifierv_2_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_66_clicked();

    void on_b_supprimerv_2_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_69_clicked();

    void on_b_afficherv_2_clicked();

    void on_pushButton_72_clicked();

    void on_b_statv_2_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_73_clicked();

    void on_b_ajouterv_3_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_80_clicked();

    void on_b_modifierv_3_clicked();

    void on_b_supprimerv_3_clicked();

    void on_pushButton_85_clicked();

    void on_pushButton_83_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_77_clicked();

    void on_b_afficherv_3_clicked();

    void on_pushButton_87_clicked();

    void on_icon4_53_clicked();

    void on_icon3_33_clicked();

    void on_icon4_54_clicked();

    void on_icon4_52_clicked();

    void on_icon2_34_clicked();

    void on_icon4_51_clicked();

    void on_icon2_33_clicked();

    void on_icon3_31_clicked();

    void on_icon4_49_clicked();

    void on_icon4_55_clicked();

    void on_icon2_36_clicked();

    void on_icon3_34_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_86_clicked();

    void on_pushButton_93_clicked();

    void on_pushButton_57_clicked();

    void on_b_ajouterv_4_clicked();

    void on_pushButton_94_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_99_clicked();

    void on_b_modifierv_4_clicked();

    void on_pushButton_modifierClient_3_clicked();

    void on_pushButton_101_clicked();

    void on_icon4_59_clicked();

    void on_b_supprimerv_4_clicked();

    void on_pb_supprimer_3_clicked();

    void on_icon4_62_clicked();

    void on_icon3_38_clicked();

    void on_pushButton_103_clicked();

    void on_b_afficherv_4_clicked();

    void on_pushButton_104_clicked();

   // void on_pushButton_105_clicked();

    void on_pushButton_106_clicked();

    void on_icon3_39_clicked();

    void on_icon2_40_clicked();

    void on_icon4_64_clicked();

    void on_icon4_61_clicked();

    void on_icon2_38_clicked();

    void on_icon4_60_clicked();

    void on_icon2_37_clicked();

    void on_icon3_35_clicked();

    void on_icon4_58_clicked();

    void on_pushButton_97_clicked();

    void on_pushButton_109_clicked();

    void on_b_ajouterv_5_clicked();

    void on_pb_ajouter_client_f_clicked();

    void on_pushButton_111_clicked();

    void on_b_modifierv_5_clicked();

    void on_pushButton_113_clicked();

    void on_icon4_67_clicked();


    void on_icon2_42_clicked();

    void on_icon4_68_clicked();

    void on_pushButton_modifierClient_2_clicked();

    void on_b_supprimerv_5_clicked();

    void on_icon4_69_clicked();

    void on_icon3_42_clicked();

    void on_pushButton_116_clicked();

    void on_icon4_70_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_120_clicked();

    void on_icon2_44_clicked();

    void on_icon3_43_clicked();

    void on_icon4_71_clicked();

    void on_b_afficherv_5_clicked();

    void on_pushButton_61_clicked();

    void on_icon4_41_clicked();

    void on_icon4_48_clicked();


    void on_nid_activated(const QString &arg1);

    void on_ncin_2_activated(const QString &arg1);

    void on_mid_dept_activated(const QString &arg1);

    void on_modifiidperso_activated(const QString &arg1);

    void on_pushButton_110_clicked();

    void on_pushButton_122_clicked();

    void on_a_filtrer_3_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_121_clicked();

    void on_pushButton_50_clicked();

    void on_icon3_30_clicked();

    void on_icon2_32_clicked();

    void on_icon2_30_clicked();

    void on_icon4_43_clicked();

    void on_icon4_45_clicked();

    void on_icon3_29_clicked();

    void on_icon4_46_clicked();

    void on_icon4_47_clicked();

    void on_icon4_44_clicked();

    void on_lineEdit_11_activated(const QString &arg1);

    void on_pushButton_123_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_127_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_130_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_6_activated(const QString &arg1);

    void on_lineEdit_12_activated(const QString &arg1);

    void on_reffmodifier_activated(const QString &arg1);

    void on_pushButton_105_clicked();

    void on_pushButton_131_clicked();

    void on_icon2_41_clicked();

    void on_modifiermatricule_activated(const QString &arg1);

    void on_icon4_66_clicked();

    void on_icon3_40_clicked();


    void on_pushButton_108_clicked();

private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *notifier;
    QByteArray data;


};
#endif // MAINWINDOW_H
