#ifndef TASK_H
#define TASK_H

/**
 * @author Iagoh Ribeiro Lima
 * @date 11/29/2021
 */

#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QtDebug>

class Task : public QObject
{
    Q_OBJECT

public:
    explicit Task(QObject *parent = nullptr);

     ~Task();

    QCheckBox* CheckBox;
    QLabel* Description;
    QPushButton* EditButton;
    QPushButton* DeleteButton;
    QString descriptionStore;

    void setCheckBox();
    void setDescription();
    void setEditButton();
    void setDeleteButton();
    void finishTask();

    void editCheckBox(QString priority);
    void editDescription(QString color);

    QCheckBox* getCheckBox();
    QLabel* getDescription();
    QPushButton* getEditButton();
    QPushButton* getDeleteButton();

signals:

};

#endif // TASK_H
