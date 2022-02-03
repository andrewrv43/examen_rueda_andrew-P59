#ifndef SHOWIMC_H
#define SHOWIMC_H
#include <QPainter>
#include <QMainWindow>
#include "calculos.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
QT_BEGIN_NAMESPACE
namespace Ui { class ShowIMC; }
QT_END_NAMESPACE

class ShowIMC : public QMainWindow
{
    Q_OBJECT

public:
    ShowIMC(QWidget *parent = nullptr);
    ~ShowIMC();
    void envioDatos();
    void obtenerDatos();
    void archivo();
    void paint();
    void moverLine();
    QString name;
    QString printed;
private slots:
    void on_pushButton_released();
    void on_actionGuardar_Imagen_triggered();
    void guardar();
    void print();
private:
    QList<Calculos*>m_datos;
    Ui::ShowIMC *ui;
    QPixmap lienzo;


};
#endif // SHOWIMC_H
