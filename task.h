#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

class Task : public QObject
{
    Q_OBJECT

    int indice;
    QCheckBox* CheckBox;
    QLabel* Description;
    QPushButton* EditButton;
    QPushButton* DeleteButton;
public:
    explicit Task(QObject *parent = nullptr);

    void createCheckBox();
    void createDescription();
    void createEditButton();
    void createDeleteButton();

    QCheckBox* getCheckBox();
    QLabel* getDescription();
    QPushButton* getEditButton();
    QPushButton* getDeleteButton();

signals:

};

#endif // TASK_H
