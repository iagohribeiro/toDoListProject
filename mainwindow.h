#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <QInputDialog>
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void addTask();
    void removeTask(QObject* object);
    void editTask(Task* object);
    void editCheckBox(QCheckBox* checkBox);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
