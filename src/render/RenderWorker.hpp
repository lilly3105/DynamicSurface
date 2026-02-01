#pragma once

#include <QObject>

class IRenderBackend;

namespace osg {
class Group;
}
namespace osgViewer {
class Viewer;
}

class RenderWorker : public QObject {
  Q_OBJECT
public:
  explicit RenderWorker(std::unique_ptr<IRenderBackend> backend);
  ~RenderWorker() override;

public slots:
  void run();
  void stop();
signals:
  void quit();

private:
  std::unique_ptr<IRenderBackend> backend_;
};