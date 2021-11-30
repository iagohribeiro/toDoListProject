/**
 * @author Iagoh Ribeiro Lima
 * @date 11/29/2021
 */

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

    //Connection between the behavior of the Submit button and the slot that adds the task to the list.
    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::addTask);

    //Connection to enable a task to be added via the return button.
    QObject::connect(ui->descriptionField, &QLineEdit::returnPressed, ui->submitButton, &QPushButton::click);

    //Connection to enable the creation of Exclusive checkboxes.
    QObject::connect(ui->high, &QCheckBox::clicked, this, [=]{editCheckBox(ui->high);});
    QObject::connect(ui->medium, &QCheckBox::clicked, this, [=]{editCheckBox(ui->medium);});
    QObject::connect(ui->low, &QCheckBox::clicked, this, [=]{editCheckBox(ui->low);});
    QObject::connect(ui->none, &QCheckBox::clicked, this, [=]{editCheckBox(ui->none);});

    //Connection to add to the save button behavior.
    QObject::connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveTasks);
}

MainWindow::~MainWindow()
{
    delete ui;
    taskList.clear();
}

void MainWindow::addTask()
{
    /**
     * @brief The tasks will be added in a Grid layout. Thus, for each row of the grid,
     * a group of elements of a task will be added. Each column will be a task element
     * in that row.
     *
     * Furthermore, the task's checkbox will be customized according to its priority.
     */

    QGridLayout* layout = qobject_cast<QGridLayout*>(ui->gridLayout->layout());

    int row = ui->gridLayout->rowCount();

    if (ui->descriptionField->text().isEmpty())
    {
        /**
         * @note If the description field is empty, you cannot add a task.
         */

        QMessageBox msgBox;
        msgBox.setText("The Description field cannot be empty.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        Task* newTask = new Task ();
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

        //The tasks will be added to a list to make it easier to save them to a file.
        taskList.append(newTask);

        //The buttons of a Task are connected to the functions responsible for their respective behaviors.
        QObject::connect(
                    newTask->getDeleteButton(), &QPushButton::clicked,
                    this, [=]{removeTask(newTask);});

        QObject::connect(
                    newTask->getEditButton(), &QPushButton::clicked,
                    this, [=]{editTask(newTask);});
    }

}
void MainWindow::removeTask(Task* object)
{
    /**
     * @brief Responsible for deleting the task from the
     * interface and from the task list
     */

    taskList.removeAll(object);
    delete object;

}
void MainWindow::editTask(Task* object)
{
    /**
     * @brief Responsible for generating a QDialog for
     * the user to choose the color of the task.
     */

    QInputDialog colorDialog = new QInputDialog();

    QStringList colorList = {" ", "Red", "Yellow", "Green"};

    QString color = colorDialog.getItem(this, "Select a background color for the task",
                                        "Color:                                                                              ",
                                        colorList);
    object->editDescription(color);

}

void MainWindow::editCheckBox(QCheckBox* checkBox)
{
    /**
     * @brief Transform the Priority checkboxes into exclusive checkboxes.
     */

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

void MainWindow::saveTasks()
{
    /**
     * @brief The tasks will be saved per line in a .txt file.
     * The task's checkbox status, description and current background color
     * will be saved.
     */

    QDir directory = (QDir::currentPath());
    QFile file = directory.filePath("TasksList.txt");

    QString message = QString("The activities are being saved in: %1").arg(directory.path());

    qInfo() << message;

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        /**
         * @note If it is not possible to open the file,
         *  a screen will be presented to the user.
         */

        QMessageBox msgBox;
        msgBox.setText("The Tasks could not be saved.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    else
    {
        /**
         * @note scrolls through the list to get the task data to be saved.
         */
        for(Task* taskElem:qAsConst(taskList))
        {
            QString line = QString("State: %1; Description: %2; BackgroundDescription: rgb(%3, %4, %5);\n")
                    .arg(taskElem->CheckBox->isChecked())
                    .arg(taskElem->Description->text())
                    .arg(taskElem->Description->palette().background().color().red())
                    .arg(taskElem->Description->palette().background().color().green())
                    .arg(taskElem->Description->palette().background().color().blue());

            QTextStream out(&file);
            out << line;
        }
        file.close();
        qInfo() << "The Tasks have been successfully saved.";
    }
}

