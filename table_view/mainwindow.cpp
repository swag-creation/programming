#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"
#include "mymodel.cpp"
#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr)
{
    ui->setupUi(this);
    model = new MyModel(this);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_text_load_clicked()
{
    QFile filename("adress.txt");
    if (!filename.open(QIODevice::ReadOnly)) {
        return;
    }
    if (model) {
         delete model;
    }
    model = new MyModel(this);
    QTextStream in(&filename);
    in >> *model;
    ui->tableView->setModel(model);
    filename.close();
}


void MainWindow::on_sort_adress_clicked()
{
    if (model && model->modelData.size() > 0) {
        model->SortAdres();
    }
}


void MainWindow::on_sort_names_clicked()
{
    if (model && model->modelData.size() > 0) {
        model->SortNames();
        }
}


void MainWindow::on_save_text_clicked()
{
    QFile filename("out.txt");
    if (!filename.open(QIODevice::WriteOnly)) {
        return;
    }
    if (model && model->modelData.size() > 0) {
        QTextStream out(&filename);
        out << *model;
        filename.close();
    }
}

