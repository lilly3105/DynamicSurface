#include "OsgBackend.hpp"

#include <osg/Group>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>

OsgBackend::OsgBackend() = default;

OsgBackend::~OsgBackend() { shutdown(); }

void OsgBackend::init() {
  viewer_ = new osgViewer::Viewer;
  root_ = new osg::Group;

  viewer_->setUpViewInWindow(1000, 100, 800, 800);
  viewer_->setKeyEventSetsDone(0);
  viewer_->setThreadingModel(osgViewer::Viewer::SingleThreaded);
  viewer_->setCameraManipulator(new osgGA::TrackballManipulator);

  viewer_->setSceneData(root_.get());
}

void OsgBackend::frame() { viewer_->frame(); }

void OsgBackend::shutdown() {
  if (viewer_)
    viewer_->setDone(true);
}

bool OsgBackend::done() const { return viewer_->done(); }

osg::ref_ptr<osg::Group> &OsgBackend::root() { return root_; }