#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);

    connect(process , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));
    connect(process , SIGNAL(readyReadStandardError()) , this , SLOT(on_readerror()));

    process->start("bash");
    process->waitForStarted();
}

MainWindow::~MainWindow()
{
    if(process){
        process->terminate();
        process->waitForFinished();
    }
    delete ui;
}

void MainWindow::showProject()
{
    QString str_pro=u_project;
    ui->lineEdit_project->setText(str_pro);
}

void MainWindow::showCommand()
{
    QString str_cmd=u_pro_path + u_project + " " + u_mode + " " + u_engine_path;
    ui->lineEdit_cmd->setText(str_cmd);
}

void MainWindow::on_lineEdit_project_textChanged(const QString &arg1)
{
    this->u_project=ui->lineEdit_project->text();
    QString str_cmd=u_pro_path + u_project + " " + u_mode + " " + u_engine_path;
    ui->lineEdit_cmd->setText(str_cmd);
}

void MainWindow::on_lineEdit_cmd_textChanged(const QString &arg1)
{
    this->u_command=ui->lineEdit_cmd->text();
}

void MainWindow::on_pushButton_run_clicked()
{
    this->u_project=ui->lineEdit_project->text();
//    showCommand();
    qDebug() << u_command;

    process->write(u_command.toLocal8Bit()+'\n');
}

void MainWindow::on_readoutput()
{
    ui->textEdit_readoutput->append(process->readAllStandardOutput());
}

void MainWindow::on_readerror()
{
    ui->textEdit_readoutput->append(process->readAllStandardError());
//    QMessageBox::information(0, "Error", process->readAllStandardError().data());
}


void MainWindow::on_pushButton_stop_clicked()
{
    process->write("\n");
}


void MainWindow::on_pushButton_run_2_clicked()
{
    ui->textEdit_readoutput->clear();
}

