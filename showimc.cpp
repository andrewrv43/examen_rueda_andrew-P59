#include "showimc.h"
#include "ui_showimc.h"

ShowIMC::ShowIMC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShowIMC)
{
    ui->setupUi(this);
    archivo();
    paint();
}

ShowIMC::~ShowIMC()
{
    delete ui;
}


void ShowIMC::on_pushButton_released()
{
    envioDatos();
    obtenerDatos();
    guardar();
}

void ShowIMC::envioDatos()
{
    QString peso=QString::number(ui->inPeso->value(),'f',2);
    float altura=ui->inAltura->value();
    QString fecha=ui->inFecha->text();
    m_datos.append(new Calculos(peso,altura,fecha));

}

void ShowIMC::obtenerDatos()
{
    float imcActual=m_datos.at(m_datos.length()-1)->imc();
    float valormax=0;
    float valormin=100;
    foreach(Calculos *a,m_datos){
        if(a->peso().toDouble()>valormax){
            valormax=a->peso().toDouble();
        }

        if(a->peso().toDouble()<valormin){
            valormin=a->peso().toDouble();
        }
    }
    ui->outMinimo->setText(QString::number(valormin,'f',2));
    ui->outMaximo->setText(QString::number(valormax,'f',2));
    ui->outImc->setText(QString::number(imcActual,'f',2));


    moverLine();
}

void ShowIMC::archivo()
{
    QString nombre="../archivo.csv";
    QFile archivo(nombre);
    name=nombre;
    if(archivo.exists()){
        if(archivo.open(QFile::ReadOnly|QFile::Text)){
            QTextStream io(&archivo);
            QString fecha,alt,peso;
            while(!io.atEnd()){
                auto linea = io.readLine();
                auto valores=linea.split(";");
                fecha=valores[0];
                alt=valores[1];
                peso=valores[2];
                m_datos.append(new Calculos(peso,alt.toDouble(),fecha));
            }
        }

    obtenerDatos();
    }
}

    void ShowIMC::paint()
    {
        lienzo = QPixmap(500,200);
        lienzo.fill(Qt::transparent);
        QPainter painter(&lienzo);
        int x=0,y=0;
        QPen pincel;
        //primer cuadro
        pincel.setWidth(5);
        QColor colorp(16,205,182);
        pincel.setColor(Qt::transparent);
        pincel.setJoinStyle(Qt::MiterJoin);
        painter.setBrush(colorp);
        painter.setPen(pincel);
        painter.drawRect(x,y+50,35,75);
        //segundo cuadro
        QColor morado(52,74,156);

        painter.setBrush(morado);

        painter.drawRect(x+40, y+50,50 , 75);
        //tercer cuadrado
        QColor tercero(108,225,115);

        painter.setBrush(tercero);

        painter.drawRect(x+95,y+50,100,75);
        //cuarto cuadro
        QColor cuarto(223,231,126);

        painter.setBrush(cuarto);

        painter.drawRect(x+200,y+50,55,75);
        //quinto cuadro

        QColor quinto (255,162,44);
        painter.setBrush(quinto);
        painter.drawRect(x+260,y+50,50,75);

        ui->outGrafico->setPixmap(lienzo);


    }

    void ShowIMC::moverLine()
    {
        float v=ui->outImc->text().toDouble();


        if(v>15&&v<16){
            ui->line->setGeometry(30,0,5,100);
            ui->outLegend->setText("Bajo peso");
        }
        else if(v>16&&v<18.5){
            ui->line->setGeometry(75,0,5,100);
        ui->outLegend->setText("Peso poco bajo ");
        }
        else if(v>18.5&&v<25){
            ui->line->setGeometry(150,0,5,100);
            ui->outLegend->setText("Normal");
        }
        else if(v>25&&v<30){
            ui->line->setGeometry(225,0,5,100);
            ui->outLegend->setText("Un poco pasado de peso");
        }
        else if(v>30&&v<35){
            ui->line->setGeometry(290,0,5,100);
            ui->outLegend->setText("SOBREPESO!");
        }

    }


    void ShowIMC::on_actionGuardar_Imagen_triggered()
    {
        QString nombreArchivo = QFileDialog::getSaveFileName(
                    this,"Guardar imagen",QString(),"Imagenes (*.png)");
        if (!nombreArchivo.isEmpty()){
            if (lienzo.save(nombreArchivo))
                QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
            else
                QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
        }
    }



    void ShowIMC::guardar()
    {
        print();
        QFile archivo(name);
        if(archivo.open(QFile::WriteOnly)){
            archivo.write(printed.toUtf8());
        }
        else{
            QMessageBox::warning(this,"GUARDAR DATOS","No se pudieron guardar los datos");
        }
        archivo.close();
    }

    void ShowIMC::print()
    {
        QString data="";
        foreach(Calculos *a,m_datos){

            data+=a->fecha()+";"+QString::number(a->altura(),'f',2)+";"+a->peso()+"\n";
        }
        printed=data;
    }


