#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent),
   ui(new Ui::Widget)
{
   ui->setupUi(this);
   initDatabase();
   populateDataItem();
   connect(ui->deleteButton, SIGNAL(clicked(bool)),this,
      SLOT(remove()));
   connect(ui->addButton, SIGNAL(clicked(bool)),this,
      SLOT(addNew()));
   connect(ui->submitButton, SIGNAL(clicked(bool)),this,
      SLOT(save()));
}

void Widget::populateDataItem(){
   model=new QSqlTableModel(0, db);
   model->setTable("seance");
   model->setEditStrategy(QSqlTableModel::OnManualSubmit);
   model->select();
   model->setHeaderData(0, Qt::Horizontal, tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, tr("Matiere"));
   model->setHeaderData(2, Qt::Horizontal, tr("Nature"));
   model->setHeaderData(3, Qt::Horizontal, tr("Date"));
   model->setHeaderData(4, Qt::Horizontal, tr("Duree"));
   model->setHeaderData(5, Qt::Horizontal, tr("Salle"));
   model->setHeaderData(6, Qt::Horizontal, tr("Enseignant"));

   ui->tableView->setModel(model);
   ui->tableView->setAlternatingRowColors(true);
}

bool Widget::initDatabase(){
   db=QSqlDatabase::addDatabase("QMYSQL","MyLibrary");
   db.setHostName("localhost");
   db.setDatabaseName("test");
   db.setUserName("user1");
   db.setPassword("secret");
   return db.open();
}

void Widget::closeDatabase(){
   db.close();
}

Widget::~Widget()
{
   closeDatabase();
   delete model;
   delete ui;
}

void Widget::addNew(){
   int row=0;
   model->insertRows(row,1);
   model->setData(model->index(row,0),ui->edId->text());
   model->setData(model->index(row,1),ui->edMatiere->text());
   model->setData(model->index(row,2),ui->edNature->text());
   model->setData(model->index(row,3),ui->edDate->text());
   model->setData(model->index(row,4),ui->edDuree->text());
   model->setData(model->index(row,5),ui->edSalle->text());
   model->setData(model->index(row,6),ui->edEnseignant->text());
}

void Widget::remove(){
   int row=ui->tableView->currentIndex().row();
   if(QMessageBox::question(0,"Delete", "Record no. "
                            +QString::number(row+1)
                            +" will be deleted. Are you sure?",
                            QMessageBox::No,QMessageBox::Yes)==
                            QMessageBox::Yes){
      model->removeRow(row);
   }
}

void Widget::save(){
   bool flag=model->submitAll();
   if(flag==false)
      QMessageBox::critical(0,"Failed", "cannot save changes.");
   else
      QMessageBox::information(0,"success",
      "changes saved successfully.");
}
