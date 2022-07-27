#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int count_digit(long long number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

QString card_type;
QString validity;

void MainWindow::on_pushButton_clicked()
{
    long long card;
       card = ui->lineEdit->text().toLongLong();
       long long temp2 = card;
       int digit = count_digit(card);
    if (digit>=13 && digit<=19){

        int a=0,b=0,count =1;
        for(int i =digit;i>0;i--)
        {
            if (count%2== 0)
            {
                if((card%10*2)%10!=0 || card%10*2==10){
                    int temp1=card%10*2;
                    for (int i =0;i<2;i++){
                        a+=temp1%10;
                        temp1 =temp1/10;
                    }
                }else{

                    a +=card%10*2;
                }

            }else{
                b+=card%10;

            }
            count++;
            card=card/10;
        }
        if((a +b)%10==0){

            ui->label_4->setText("Valid");
            validity = "Valid";

            while(temp2>10)
            {
                temp2 = temp2/10;
            }
            switch(temp2)
            {
                   case 4:
                    ui->label_8->setText("Visa");
                    card_type = "Visa";
                    break;

                    case 2:
                    ui->label_8->setText("Master");
                    card_type = "Master";
                    break;

                    case 5:
                    ui->label_8->setText("Master");
                    card_type = "Master";
                    break;

                    case 3:
                    ui->label_8->setText("American");
                    card_type = "American";
                    break;

                    case 6:
                    ui->label_8->setText("Discover");
                    card_type = "Discover";
                    break;

                    default:
                    ui->label_8->setText("Not Supported");
                    card_type = "Not _ Found";
                    break;
            }
        }else{
            ui->label_4->setText("Invalid");
            validity = "Invalid";
            card_type = "- - - - -";
        }
        QFile file1("History.txt");
       if(!file1.open(QFile::ReadWrite | QFile::Text))
       {
            QMessageBox::warning(this,"Warning","File not found");
       }
       QTextStream in1(&file1);
       QTextStream out1(&file1);
       QString text1 = in1.readAll();
       QString text2 = ui->lineEdit->text();
       out1<<"Card_Number\t\t"<<text2 <<"\t\t"<<validity<<"\t\t"<<card_type<<"\n";

       file1.flush();
       file1.close();
    }else{
        ui->label_4->setText("Invalid Input");
        ui->label_8->setText("Not Found");
    }
    ui->label_6->setNum(digit);





}


void MainWindow::on_pushButton_2_clicked()
{
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::about(this,"About","This is a project");
}

