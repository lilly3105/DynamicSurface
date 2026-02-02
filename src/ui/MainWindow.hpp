#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class AppMainWindow;
}
QT_END_NAMESPACE

class SurfaceViewModel;

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(SurfaceViewModel* viewModel, QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    Ui::AppMainWindow* ui_;
    SurfaceViewModel* viewModel_;
};
