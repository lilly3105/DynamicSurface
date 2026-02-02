#pragma once

#include "IRenderBackend.hpp"

#include <osg/ref_ptr>

class ISurfaceParameters;
class Model;

namespace osg {
class Group;
}

namespace osgViewer {
class Viewer;
}

class OsgBackend final : public IRenderBackend {
public:
  OsgBackend(const ISurfaceParameters* params);
  ~OsgBackend() override;

  void init() override;
  void frame() override;
  void shutdown() override;
  bool done() const override;

private:
  osg::ref_ptr<osgViewer::Viewer> viewer_;
  osg::ref_ptr<osg::Group> root_;

  osg::ref_ptr<Model> model_;

  const ISurfaceParameters* params_;
};
