#include "secdialog.h"
#include "ui_secdialog.h"
#include "QFile"
#include "QTextStream"
#include "QString"
#include "QMessageBox"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("History");
    QFile file1("History.txt");
   if(!file1.open(QFile::ReadWrite | QFile::Text))
   {
        QMessageBox::warning(this,"Warning","File not found");
   }
   QTextStream in1(&file1);
   QString text1 = in1.readAll();
   ui->plainTextEdit->setPlainText(text1);
   file1.flush();
   file1.close();
}

SecDialog::~SecDialog()
{
    delete ui;
}


