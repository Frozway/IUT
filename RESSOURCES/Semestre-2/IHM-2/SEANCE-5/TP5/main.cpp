#include "widget.h"

#include <QtSql>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QInputDialog>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Création de la base de donnée

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("session.db");

    if (!db.open())
    {
        qDebug() << "Error: Connection with database failed";
    }

    else
    {
        qDebug() << "Database: Connection ok";
    }

    QApplication::setStyle(QStyleFactory::create("fusion"));
    Widget w;
    w.show();
    return a.exec();

}
