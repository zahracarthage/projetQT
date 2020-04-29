#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "depenses.h"
#include <QMainWindow>
#include "emplacement.h"
#include "qcustomplot.h"
#include "client.h"
#include "client_fidele.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_12_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_tri_decr_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_modifierClient_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pb_supprimer_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pb_ajouter_client_f_clicked();

    void on_comboBox_ref_modifier_2_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_pb_supprimer_2_clicked();

    void on_pushButton_modifierClient_2_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

private:
    Ui::MainWindow *ui;
    depenses tempdep;
    emplacement tempemp;
    client tmpclient;
    client_fidele tmpclientf;
};
#endif // MAINWINDOW_H
