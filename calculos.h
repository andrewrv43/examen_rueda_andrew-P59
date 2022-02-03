#ifndef CALCULOS_H
#define CALCULOS_H

#include <QObject>

class Calculos : public QObject
{
    Q_OBJECT
public:
    explicit Calculos(QObject *parent = nullptr);
    Calculos(const QString &peso, float altura,const QString &fecha);

    const QString &peso() const;
    void setPeso(const QString &newPeso);
    float altura() const;
    void setAltura(float newAltura);

    float imc() const;
    void setImc(float newImc);

    const QString &fecha() const;
    void setFecha(const QString &newFecha);

private:
    float m_imc;
    QString m_peso;
    QString m_fecha;
    float m_altura;

signals:

};

#endif // CALCULOS_H
