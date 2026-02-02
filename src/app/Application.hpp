#pragma once

#include <QApplication>
#include <QThread>

#include "SurfaceViewModel.hpp"

class MainWindow;

class Application {
public:
  explicit Application(int argc, char **argv);
  ~Application();

  int exec();

private:
  void initQt();
  void initOSG();

  QApplication app_;
  QThread renderThread_;
  std::unique_ptr<MainWindow> mainWindow_;
  SurfaceViewModel viewModel_;
};
