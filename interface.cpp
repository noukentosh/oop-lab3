#include "interface.h"
#include "ui_interface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TInterface)
{
    ui->setupUi(this);
}

TInterface::~TInterface()
{
    delete ui;
}


void TInterface::on_find_roots_btn_pressed()
{
    number a (ui->ai->text().toDouble(), ui->ar->text().toDouble());
    number b (ui->bi->text().toDouble(), ui->br->text().toDouble());
    number c (ui->ci->text().toDouble(), ui->cr->text().toDouble());

    TPolinom p (a, b, c);

    number x[2];

    QString s;

    switch (p.roots(x)) {
    case 0: {
        ui->r1->setText("no roots");
        ui->r2->setText("no roots");
        break;
    }
    case 1: {
        s << x[0];
        ui->r1->setText(s);
        ui->r2->setText(s);
        break;
    }
    case 2: {
        s << x[0];
        ui->r1->setText(s);
        s = "";
        s << x[1];
        ui->r2->setText(s);
        break;
    }
    }
}

void TInterface::on_find_value_btn_pressed()
{
    number a (ui->ai->text().toDouble(), ui->ar->text().toDouble());
    number b (ui->bi->text().toDouble(), ui->br->text().toDouble());
    number c (ui->ci->text().toDouble(), ui->cr->text().toDouble());

    TPolinom p (a, b, c);

    QString s;

    number temp = p.value(ui->xi->text().toDouble());

    s << temp;

    ui->val->setText(s);
}

void TInterface::on_find_polinom_btn_pressed()
{
    number a (ui->ai->text().toDouble(), ui->ar->text().toDouble());
    number b (ui->bi->text().toDouble(), ui->br->text().toDouble());
    number c (ui->ci->text().toDouble(), ui->cr->text().toDouble());

    TPolinom p (a, b, c);

    QString s;

    s << p;

    ui->polinom->setText(s);
}
