#pragma once

#include <QObject>
#include <atomic>
#include "../render/model/ISurfaceParameters.hpp"

class SurfaceViewModel final
    : public QObject
    , public ISurfaceParameters
{
    Q_OBJECT
    Q_PROPERTY(double a READ a WRITE setA NOTIFY aChanged)
    Q_PROPERTY(double b READ b WRITE setB NOTIFY bChanged)

  public:
    explicit SurfaceViewModel(QObject* parent = nullptr);

    double a() const noexcept override;
    double b() const noexcept override;

public slots:
    void setA(double v);
    void setB(double v);

signals:
    void aChanged();
    void bChanged();

private:
    std::atomic<double> a_{1.0};
    std::atomic<double> b_{1.0};
};
