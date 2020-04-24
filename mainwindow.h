#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "client_fidele.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_client_f_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_modifierClient_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_tri_decr_clicked();

    void on_pushButton_rechercher_2_linkActivated(const QString &link);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_modifier_2_clicked();

    void on_pb_ajouter_client_f_3_clicked();



    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_comboBox_ref_modifier_2_activated(const QString &arg1);

    void on_comboBox_ref_modifier_activated(const QString &arg1);

    void on_label_49_linkActivated(const QString &link);

    void on_pushButton_modifierClient_2_clicked();

    void on_pushButton_modifierClient_3_clicked();

private:
    Ui::MainWindow *ui;
     client tmpclient;
     client_fidele tmpclientf;
};

#endif // MAINWINDOW_H
