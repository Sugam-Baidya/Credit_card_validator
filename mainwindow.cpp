#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    long int card;
       card = ui->lineEdit->text().toLongLong();
       int digit = count_digit(card);

       int a=0,b=0,count =1;
       for(int i =digit;i>0;i--)
       {
           if (count%2!= 0)
           {
               if((card%10*2)%10!=0 || card%10*2==10){
                   int temp=card%10*2;
                   for (int i =0;i<2;i++){
                       a+=temp%10;
                       temp =temp/10;
                   }
               }else{

                   a +=card%10*2;
               }

           }else{
               b+=card%10;

           }
           count++;
       }
       if((a +b)%10==0){
           ui->label_4->setText("Valid");
       }else{
           ui->label_4->setText("Invalid");
       }
}

