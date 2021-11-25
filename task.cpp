#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    CheckBox = new QCheckBox();
    Description = new QLabel();
    EditButton = new QPushButton();
    DeleteButton = new QPushButton();

    createCheckBox();
    createDescription();
    createEditButton();
    createDeleteButton();

}

void Task::createCheckBox()
{
    CheckBox->setObjectName(QString::fromUtf8("checkBox"));
}

void Task::createDescription()
{
    Description->setObjectName(QString::fromUtf8("description"));
    Description->setMaximumSize(QSize(800, 20));

}
void Task::createEditButton()
{
    EditButton->setObjectName(QString::fromUtf8("editButton"));
    EditButton->setMinimumSize(QSize(30, 30));
    EditButton->setMaximumSize(QSize(40, 40));
    EditButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/editIcon.png)"));
}
void Task::createDeleteButton()
{
    DeleteButton->setObjectName(QString::fromUtf8("deleteButton"));
    DeleteButton->setMinimumSize(QSize(30, 30));
    DeleteButton->setMaximumSize(QSize(40, 40));
    DeleteButton->setStyleSheet(QString::fromUtf8("image:url(:/icons/icons/trashIcon.png)"));
}

QCheckBox* Task::getCheckBox()
{
    return CheckBox;
}

QLabel* Task::getDescription()
{
    return Description;
}

QPushButton* Task::getEditButton()
{
    return EditButton;
}

QPushButton* Task::getDeleteButton()
{
    return DeleteButton;
}

