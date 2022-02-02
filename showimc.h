#ifndef SHOWIMC_H
#define SHOWIMC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ShowIMC; }
QT_END_NAMESPACE

class ShowIMC : public QMainWindow
{
    Q_OBJECT

public:
    ShowIMC(QWidget *parent = nullptr);
    ~ShowIMC();

private:
    Ui::ShowIMC *ui;
};
#endif // SHOWIMC_H
