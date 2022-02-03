#include "calculos.h"

Calculos::Calculos(QObject *parent) : QObject(parent)
{

}
const QString &Calculos::peso() const
{
    return m_peso;
}

void Calculos::setPeso(const QString &newPeso)
{
    m_peso = newPeso;
}


float Calculos::altura() const
{
    return m_altura;
}

void Calculos::setAltura(float newAltura)
{
    m_altura = newAltura;
}

float Calculos::imc() const
{
    return m_imc;
}

void Calculos::setImc(float newImc)
{
    m_imc = newImc;
}

const QString &Calculos::fecha() const
{
    return m_fecha;
}

void Calculos::setFecha(const QString &newFecha)
{
    m_fecha = newFecha;
}



Calculos::Calculos(const QString &peso, float altura,const QString &fecha) : m_peso(peso),
   m_fecha(fecha), m_altura(altura)
{
    double p=peso.toDouble();
    m_imc=p/(altura*altura);
}
