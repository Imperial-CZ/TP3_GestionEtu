#include "promotion.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QString>

Promotion::Promotion()
{
}

void Promotion::add(Student xstud)
{
    studentsList.append(xstud);
}

void Promotion::remove(Student student)
{
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentsList[i].getId() == student.getId()) {
            studentsList.remove(i);
        }
        return;
    }
}
void Promotion::remove(QString student) {
    QString studentSearched;
    for (int i = 0; i < studentsList.length(); i++) {
        studentSearched = studentsList[i].getId() + " - " + studentsList[i].getLastname() + " " + studentsList[i].getFirstname() + " (" + studentsList[i].getDepartement() + ")";
        if (student == studentSearched) {
            studentsList.remove(i); 
            return;
        }
        
    }
}
Student Promotion::find(QString studentId) {
    for (int i = 0; i < studentsList.length(); i++) {
        if (studentId == studentsList[i].getId()) {
            return studentsList[i];
        }
    }
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

}
void Promotion::removeObserver(Observer* observer) {

}
void Promotion::notifyObserver() const {

}