#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QProcess>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString u_command;

    QString u_project = "micro_kiting";

    QString u_pro_path = "/home/baichunhui/sc2/sc2api/build/bin/";

    QString u_mode = "-e";

    QString u_engine_path = "/home/baichunhui/StarCraftII/Versions/Base75689/SC2_x64";

    void showProject();

    void showCommand();

private slots:

    void on_lineEdit_cmd_textChanged(const QString &arg1);

    void on_pushButton_run_clicked();

    void on_lineEdit_project_textChanged(const QString &arg1);

    void on_readoutput();

    void on_readerror();

    void on_pushButton_stop_clicked();

    void on_pushButton_run_2_clicked();

private:
    Ui::MainWindow *ui;

    QProcess *process;


};
#endif // MAINWINDOW_H
