#include "promotion.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QString>

Promotion::Promotion()
{
    
}

void Promotion::initMapDept() {
    mapDept.clear();
    mapDept["1"] = 0;
    mapDept["35"] = 0;
    mapDept["38"] = 0;
    mapDept["39"] = 0;
    mapDept["69"] = 0;
    mapDept["71"] = 0;
    mapDept["84"] = 0;
    mapDept["Autre"] = 0;
    for (int i = 0; i < studentsList.length(); i++) {
        mapDept[studentsList[i].getDepartement()]+=1;
    }
}

void Promotion::add(Student xstud)
{
    studentsList.append(xstud);
    notifyObserver();
}

void Promotion::remove(Student student)
{
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentsList[i].getId() == student.getId()) {
            studentsList.remove(i);
            notifyObserver();
            return;
        }
    }
}

void Promotion::remove(QString student) {
    QString studentSearched;
    for (int i = 0; i < studentsList.length(); i++) {
        studentSearched = studentsList[i].getId() + " - " + studentsList[i].getLastname() + " " + studentsList[i].getFirstname() + " (" + studentsList[i].getDepartement() + ")";
        if (student == studentSearched) {
            studentsList.remove(i);
            notifyObserver();
            return;
        }
    }
}

void Promotion::remove(QVector<Student> students) {
    QString studentSearched;
    for (int i = 0; i < studentsList.length(); i++) {
        studentSearched = studentsList[i].getId();
        for (int j = 0; j < students.length(); j++) {
            if (students[j].getId() == studentSearched) {
                studentsList.remove(i);
                break;
            }
        }
    }
    notifyObserver();
}

Student Promotion::find(QString studentId) {
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentId == studentsList[i].getId()) {
            return studentsList[i];
        }
    }
    return Student(0,"","","","");
}

void Promotion::readList(const QString& filename)
{
    QString line;
    QFile myfile(filename + ".csv");
    if (myfile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&myfile);
        QStringList wordList;

        while (!in.atEnd())
        {
            wordList = in.readLine().split(';');
            add(Student(wordList[0], wordList[1], wordList[2], wordList[4], wordList[3]));
        }
        myfile.close();
    }

    else qDebug() << "Unable to open file" << filename << ": error" << myfile.error() << "," << myfile.errorString();
}

QStringList Promotion::getStudentslist() {
    QStringList temp;
    for (int i = 0; i != studentsList.size(); i++) {
        temp.append(studentsList[i].getId() + " - " + studentsList[i].getLastname() + " " + studentsList[i].getFirstname() + " (" + studentsList[i].getDepartement() + ")");
    }

    return temp;
}
QMap<QString, int>* Promotion::getMapDept() {
    return &mapDept;
}
int Promotion::compterS() {
    int nbS = 0;
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentsList[i].getBac() == "S") {
            nbS++;
        }
    }
    return nbS;
}
int Promotion::compterES() {
    int nbES = 0;
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentsList[i].getBac() == "ES") {
            nbES++;
        }
    }
    return nbES;
}
int Promotion::compterSTI() {
    int nbSTI = 0;
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentsList[i].getBac() == "STI") {
            nbSTI++;
        }
    }
    return nbSTI;
}

void Promotion::addObserver(Observer* observer) {
    observersList.append(observer);
}
void Promotion::removeObserver(Observer* observer) {
    observersList.removeOne(observer);
}
void Promotion::notifyObserver() const {
    for (int i = 0; i < observersList.length(); i++) {
        observersList[i]->update();
    }
}