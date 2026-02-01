#pragma once

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QThread>

class Application {
public:
  explicit Application(int argc, char **argv);
  ~Application();

  int exec();

private:
  void initQt();
  void initOSG();

  QApplication app_;
  QQmlApplicationEngine engine_;
  QThread renderThread_;
};