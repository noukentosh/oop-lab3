#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include "number.h"
#include "polinom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QWidget
{
    Q_OBJECT

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

private slots:
    void on_find_roots_btn_pressed();

    void on_find_value_btn_pressed();

    void on_find_polinom_btn_pressed();

private:
    Ui::TInterface *ui;
};
#endif // TINTERFACE_H
