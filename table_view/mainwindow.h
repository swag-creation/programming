#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mymodel.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_text_load_clicked();

    void on_sort_adress_clicked();

    void on_sort_names_clicked();

    void on_save_text_clicked();

private:
    Ui::MainWindow *ui;
    MyModel* model;
};
#endif // MAINWINDOW_H
