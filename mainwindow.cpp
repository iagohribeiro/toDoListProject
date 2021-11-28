#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Hide the task widget to clean the tasks section
    ui->task->hide();

    //ui->descriptionField->setEchoMode(QLineEdit::Normal);
    //ui->descriptionField->echoMode();

    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::addTask);

    QObject::connect(ui->descriptionField, &QLineEdit::returnPressed, ui->submitButton, &QPushButton::click);

    QObject::connect(ui->high, &QCheckBox::clicked, this, [=]{editCheckBox(ui->high);});
    QObject::connect(ui->medium, &QCheckBox::clicked, this, [=]{editCheckBox(ui->medium);});
    QObject::connect(ui->low, &QCheckBox::clicked, this, [=]{editCheckBox(ui->low);});
    QObject::connect(ui->none, &QCheckBox::clicked, this, [=]{editCheckBox(ui->none);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QGridLayout* layout = qobject_cast<QGridLayout*>(ui->gridLayout->layout());

    int row = ui->gridLayout->rowCount();

    Task* newTask = new Task ();

    if (ui->descriptionField->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("The Description field cannot be empty.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        newTask->getDescription()->setText(ui->descriptionField->text());

        if(ui->high->isChecked())
        {
            newTask->editCheckBox("High");
        }
        else if (ui->medium->isChecked())
        {
            newTask->editCheckBox("Medium");
        }
        else if (ui->low->isChecked())
        {
            newTask->editCheckBox("Low");
        }
        else
        {
            newTask->editCheckBox("None");
        }

        layout->addWidget(newTask->getCheckBox(), row, 0);
        layout->addWidget(newTask->getDescription(), row, 1);
        layout->addWidget(newTask->getEditButton(), row, 2);
        layout->addWidget(newTask->getDeleteButton(), row, 3);

        QObject::connect(
                    newTask->getDeleteButton(), &QPushButton::clicked,
                    this, [=]{removeTask(newTask);});

        QObject::connect(
                    newTask->getEditButton(), &QPushButton::clicked,
                    this, [=]{editTask(newTask);});
    }

}
void MainWindow::removeTask(QObject* object)
{
    delete object;

}
void MainWindow::editTask(Task* object)
{
    QInputDialog colorDialog = new QInputDialog();

    QStringList colorList = {" ", "Red", "Yellow", "Green"};

    QString color = colorDialog.getItem(this, "Select a background color for the task",
                                        "Color:                                                                              ",
                                        colorList);
    object->editDescription(color);

}

void MainWindow::editCheckBox(QCheckBox* checkBox)
{
    if (checkBox->text().toUpper() == "HIGH")
    {
        ui->medium->setChecked(false);
        ui->low->setChecked(false);
        ui->none->setChecked(false);
    }
    else if (checkBox->text().toUpper() == "MEDIUM")
    {
        ui->high->setChecked(false);
        ui->low->setChecked(false);
        ui->none->setChecked(false);
    }
    else if (checkBox->text().toUpper() == "LOW")
    {
        ui->high->setChecked(false);
        ui->medium->setChecked(false);
        ui->none->setChecked(false);
    }
    else if (checkBox->text().toUpper() == "NONE")
    {
        ui->high->setChecked(false);
        ui->medium->setChecked(false);
        ui->low->setChecked(false);
    }
}

