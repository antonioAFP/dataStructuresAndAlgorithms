#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qDebug() << "Hola :D";

  return a.exec();
}
