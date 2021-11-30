/**
 * @author Iagoh Ribeiro Lima
 * @date 11/29/2021
 */

#include "task.h"

Task::Task(QObject *parent) : QObject(parent)
{
    /**
     * @class Task: This class is responsible for creating a task.
     * A task is composed of a Checkbox, description, edit button
     * and delete button.
     */

    CheckBox = new QCheckBox();
    Description = new QLabel();
    EditButton = new QPushButton();
    DeleteButton = new QPushButton();
    descriptionStore = "";

    /**
     * @note Functions responsible for customizing the UI settings of Task elements.
     */
    setCheckBox();
    setDescription();
    setEditButton();
    setDeleteButton();

    /**
     * When the check box is checked, the finish task function will be
     * called to customize the finished task
     */
    connect(this->CheckBox, &QCheckBox::clicked, this, &Task::finishTask);
}

Task::~Task()
{
    delete CheckBox;
    delete Description;
    delete EditButton;
    delete DeleteButton;
}

void Task::setCheckBox()
{
    CheckBox->setObjectName(QString::fromUtf8("checkBox"));
}

void Task::setDescription()
{
    Description->setObjectName(QString::fromUtf8("description"));
    Description->setMaximumSize(QSize(800, 20));

}

void Task::setEditButton()
{
    EditButton->setObjectName(QString::fromUtf8("editButton"));
    EditButton->setMinimumSize(QSize(30, 30));
    EditButton->setMaximumSize(QSize(40, 40));
    EditButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/editIcon.png)"));
}

void Task::setDeleteButton()
{
    DeleteButton->setObjectName(QString::fromUtf8("deleteButton"));
    DeleteButton->setMinimumSize(QSize(30, 30));
    DeleteButton->setMaximumSize(QSize(40, 40));
    DeleteButton->setStyleSheet(QString::fromUtf8("image:url(:/icons/icons/trashIcon.png)"));
}

void Task::editCheckBox(QString priority)
{
    /**
     * @brief Functions responsible for changing the checkbox UI settings
     * according to the task's priority.
    */

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
    /**
     *  @brief Functions responsible for changing the UI settings
     *  of the description background according to the color chosen by the user.
     *
     */

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
    /**
     *  @brief Functions responsible for changing the UI settings
     *  of Task elements according to the checkbox status.
     *
     *
     */

    QColor color = Description->palette().color(QPalette::Background);

    if(CheckBox->isChecked())
    {
        /**
         * @note If the task checkbox is checked, the background color is saved to
         * restore the color if the checkbox is deselected in the future.
         */

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
