#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDateTime dt1 = QDateTime::currentDateTime();
    QDateTime dt2 = QDateTime::currentDateTimeUtc();

    qDebug() << dt1;
    qDebug() << dt2;

    qDebug() << dt1.currentMSecsSinceEpoch();
    qDebug() << dt2.currentMSecsSinceEpoch();

    QDateTime outdt1 = QDateTime::fromMSecsSinceEpoch(dt1.toMSecsSinceEpoch());
    QDateTime outdt2 = QDateTime::fromMSecsSinceEpoch(dt2.toMSecsSinceEpoch());

	qDebug() << outdt1;
	qDebug() << outdt2;
	qDebug() << outdt1.currentMSecsSinceEpoch();
    qDebug() << outdt2.currentMSecsSinceEpoch();

    qDebug() << (outdt1==dt1);
    qDebug() << (outdt2==dt2);
    return a.exec();
}
