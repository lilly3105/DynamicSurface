#include "SurfaceViewModel.hpp"

SurfaceViewModel::SurfaceViewModel(QObject* parent)
  : QObject(parent) {}

double SurfaceViewModel::a() const noexcept {
    return a_.load(std::memory_order_relaxed);
}

double SurfaceViewModel::b() const noexcept {
    return b_.load(std::memory_order_relaxed);
}

void SurfaceViewModel::setA(double v) {
    a_.store(v, std::memory_order_relaxed);
    emit aChanged();
}

void SurfaceViewModel::setB(double v) {
    b_.store(v, std::memory_order_relaxed);
    emit bChanged();
}
