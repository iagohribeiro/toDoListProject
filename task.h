#ifndef TASK_H
#define TASK_H

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

    void createCheckBox();
    void createDescription();
    void createEditButton();
    void createDeleteButton();
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
