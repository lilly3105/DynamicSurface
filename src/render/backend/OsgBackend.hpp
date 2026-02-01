#ifndef OSGBACKEND_HPP
#define OSGBACKEND_HPP
#include "IRenderBackend.hpp"

#include <osg/ref_ptr>

namespace osg {
class Group;
}

namespace osgViewer {
class Viewer;
}

class OsgBackend final : public IRenderBackend {
public:
  OsgBackend();
  ~OsgBackend() override;

  void init() override;
  void frame() override;
  void shutdown() override;
  bool done() const override;

  [[nodiscard]] osg::ref_ptr<osg::Group> &root();

private:
  osg::ref_ptr<osgViewer::Viewer> viewer_;
  osg::ref_ptr<osg::Group> root_;
};

#endif // OSGBACKEND_HPP
