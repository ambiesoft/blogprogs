#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFileInfo fi("C:/T/");
    qDebug() << fi.canonicalFilePath();

    return a.exec();
}
