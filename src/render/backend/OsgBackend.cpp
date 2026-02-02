#include "OsgBackend.hpp"

#include "../model/Model.hpp"
#include "../model/ModelUpdateCallback.hpp"

#include <osg/Group>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>


OsgBackend::OsgBackend(const ISurfaceParameters *params) : params_(params) {}

OsgBackend::~OsgBackend() { shutdown(); }

void OsgBackend::init() {
    viewer_ = new osgViewer::Viewer;
    root_ = new osg::Group;

    viewer_->setUpViewInWindow(1000, 100, 800, 800);
    viewer_->setKeyEventSetsDone(0);
    viewer_->setThreadingModel(osgViewer::Viewer::SingleThreaded);
    viewer_->setCameraManipulator(new osgGA::TrackballManipulator);
    viewer_->addEventHandler(new osgViewer::StatsHandler);

    model_ = new Model(params_);
    model_->setUpdateCallback(new ModelUpdateCallback);

    root_->addChild(model_);

    viewer_->setSceneData(root_.get());
    viewer_->home();
}

void OsgBackend::frame() { viewer_->frame(); }

void OsgBackend::shutdown() {
    if (viewer_)
        viewer_->setDone(true);
}

bool OsgBackend::done() const { return viewer_->done(); }
