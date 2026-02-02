#include "MainWindow.hpp"

#include "ui_Main.h"
#include "../app/SurfaceViewModel.hpp"

MainWindow::MainWindow(SurfaceViewModel *viewModel, QWidget *parent)
    : QMainWindow(parent)
      , ui_(new Ui::AppMainWindow)
      , viewModel_(viewModel) {
    ui_->setupUi(this);

    ui_->lineEditA->setText(QString::number(viewModel_->a(), 'f', 2));
    ui_->lineEditB->setText(QString::number(viewModel_->b(), 'f', 2));

    auto parameterCalculation = [](QLineEdit& lineEdit, int pos, float param) {
        const float posF = pos / 100.f;
        const float value = powf(posF, 3);
        param += value;
        if(param < 0.1f) param = 0.1f;
        lineEdit.setText(QString::number(param, 'f', 2));
    };

    connect(ui_->horizontalSliderA,&QSlider::sliderMoved, [this, &parameterCalculation](int pos) {
        parameterCalculation(*ui_->lineEditA, pos, viewModel_->a());
    });
    connect(ui_->horizontalSliderA, &QSlider::sliderReleased, [this]() {
       ui_->horizontalSliderA->setSliderPosition(0);
    });
    connect(ui_->lineEditA, &QLineEdit::textChanged, [this](const QString& value) {
        viewModel_->setA(value.toFloat());
    });

    connect(ui_->horizontalSliderB,&QSlider::sliderMoved, [this, &parameterCalculation](int pos) {
        parameterCalculation(*ui_->lineEditB, pos, viewModel_->b());
    });
    connect(ui_->horizontalSliderB, &QSlider::sliderReleased, [this]() {
       ui_->horizontalSliderB->setSliderPosition(0);
    });
    connect(ui_->lineEditB, &QLineEdit::textChanged, [this](const QString& value) {
        viewModel_->setB(value.toFloat());
    });
}

MainWindow::~MainWindow() {
    delete ui_;
}

