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
        }else{
            ui->label_4->setText("Invalid");
        }
    }else{
        ui->label_4->setText("Invalid Input");
    }
    ui->label_6->setNum(digit);

 while(temp2>10)
 {
     temp2 = temp2/10;
 }
 switch(temp2)
 {
        case 4:
         ui->label_8->setText("Visa");
         break;

         case 2:
         ui->label_8->setText("Master");
         break;

         case 5:
         ui->label_8->setText("Master");
         break;

         case 3:
         ui->label_8->setText("American");
         break;

         case 6:
         ui->label_8->setText("Discover");
         break;

         default:
         ui->label_8->setText("Not Supported");
 }
}

