#include "promotion.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Promotion::Promotion()
{
}

void Promotion::add(Student xstud)
{
    studentsList.append(xstud);
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

QVector<Student> Promotion::getStudentslist()
{
    return studentsList;
}

