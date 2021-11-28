#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    CheckBox = new QCheckBox();
    Description = new QLabel();
    EditButton = new QPushButton();
    DeleteButton = new QPushButton();
    descriptionStore = "";
    createCheckBox();
    createDescription();
    createEditButton();
    createDeleteButton();

    connect(this->CheckBox, &QCheckBox::clicked, this, &Task::finishTask);

}
Task::~Task()
{
    delete getCheckBox();
    delete getDescription();
    delete getEditButton();
    delete getDeleteButton();
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

void Task::editCheckBox(QString priority)
{
    CheckBox->setObjectName(QString::fromUtf8("checkBox"));

    CheckBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    if (priority == "High")
    {
        CheckBox->setStyleSheet(QString::fromUtf8(
        "QCheckBox::indicator::unchecked\n"
        "{\n"
        "	background-color: rgb(210, 77, 90);\n"
        "	width : 15px;\n"
        "	height : 15px;\n"
        "	border-top-left-radius: 5px;	\n"
        "	border-top-right-radius: 5px;\n"
        "	border-bottom-right-radius: 5px;\n"
        "	border-bottom-left-radius: 5px;\n"
        "}\n"
        "\n"
        ""));
    }
    else if (priority == "Medium")
    {
        CheckBox->setStyleSheet(QString::fromUtf8(
        "QCheckBox::indicator::unchecked\n"
        "{\n"
        "	background-color: rgb(233, 196, 87);\n"
        "	width : 15px;\n"
        "	height : 15px;\n"
        "	border-top-left-radius: 5px;	\n"
        "	border-top-right-radius: 5px;\n"
        "	border-bottom-right-radius: 5px;\n"
        "	border-bottom-left-radius: 5px;\n"
        "}"));
    }
    else if (priority == "Low")
    {
        CheckBox->setStyleSheet(QString::fromUtf8(
        "QCheckBox::indicator::unchecked\n"
        "{\n"
        "	background-color: rgb(115, 193, 139);\n"
        "	width : 15px;\n"
        "	height : 15px;\n"
        "	border-top-left-radius: 5px;	\n"
        "	border-top-right-radius: 5px;\n"
        "	border-bottom-right-radius: 5px;\n"
        "	border-bottom-left-radius: 5px;\n"
        "}"));
    }
    else
    {
        CheckBox->setStyleSheet(QString::fromUtf8(
        "QCheckBox::indicator::unchecked\n"
        "{\n"
        "	background-color: rgb(255, 255, 255);\n"
        "	width : 15px;\n"
        "	height : 15px;\n"
        "	border-top-left-radius: 5px;	\n"
        "	border-top-right-radius: 5px;\n"
        "	border-bottom-right-radius: 5px;\n"
        "	border-bottom-left-radius: 5px;\n"
        "}"));

    }

}

void Task::editDescription(QString color)
{
    QString setColor;

    if (color.toUpper() == "RED")
    {
        setColor = " background-color: rgb(210, 77, 90); color: rgb(255, 255, 255);";
    }
    else if (color.toUpper() == "YELLOW")
    {
        setColor = " background-color: rgb(233, 196, 87); color: rgb(255, 255, 255);";
    }
    else if (color.toUpper() == "GREEN")
    {
        setColor = " background-color: rgb(115, 193, 139); color: rgb(255, 255, 255);";
    }
    else
    {
        setColor = " background-color: rgb(230, 230, 230);";
    }

    Description->setStyleSheet(setColor);

}

void Task::finishTask()
{
    QColor color = Description->palette().color(QPalette::Background);

    if(CheckBox->isChecked())
    {
        descriptionStore = QString(" background-color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue());
        Description->setDisabled(true);
        EditButton->setDisabled(true);
        DeleteButton->setDisabled(true);

        EditButton->setStyleSheet("image: url(:/icons/icons/editIconDeactivated.png);");
        DeleteButton->setStyleSheet("image: url(:/icons/icons/trashIconDeactivated.png);");
        Description->setStyleSheet(QString::fromUtf8(" background-color: rgb(230, 230, 230);"));
    }
    else
    {
        Description->setDisabled(false);
        EditButton->setDisabled(false);
        DeleteButton->setDisabled(false);

        EditButton->setStyleSheet("image: url(:/icons/icons/editIcon.png);");
        DeleteButton->setStyleSheet("image: url(:/icons/icons/trashIcon.png);");
        Description->setStyleSheet(descriptionStore);

    }

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

