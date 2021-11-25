#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Hide the task widget to clean the tasks section
    ui->task->hide();

    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QGridLayout* layout = qobject_cast<QGridLayout*>(ui->gridLayout->layout());

    Task* newTask = new Task ();

    newTask->getDescription()->setText(ui->descriptionField->text());

    layout->addWidget(newTask->getCheckBox(), line, 0);
    layout->addWidget(newTask->getDescription(), line, 1);
    layout->addWidget(newTask->getEditButton(), line, 2);
    layout->addWidget(newTask->getDeleteButton(), line, 3);

    line++;

    /*if(ui->high->isChecked())
    {



    }
    else if (ui->medium->isChecked())
    {

    }
    else if (ui->low->isChecked())
    {

    }
    else
    {

    }*/


}
void MainWindow::removeTask()
{

}
void MainWindow::editTask()
{

}


