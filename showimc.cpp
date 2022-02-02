#include "showimc.h"
#include "ui_showimc.h"

ShowIMC::ShowIMC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShowIMC)
{
    ui->setupUi(this);
}

ShowIMC::~ShowIMC()
{
    delete ui;
}

