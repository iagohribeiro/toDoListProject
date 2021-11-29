#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QObject>
#include <QCheckBox>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QThread>
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

    QList<Task*> taskList;

    void addTask();
    void removeTask(Task* object);
    void editTask(Task* object);
    void editCheckBox(QCheckBox* checkBox);
    void saveTasks();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
