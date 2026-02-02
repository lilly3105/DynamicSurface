#pragma once

#include <osg/Callback>

class Model;

class ModelUpdateCallback final : public osg::NodeCallback {
public:
  void operator()(osg::Node *node, osg::NodeVisitor *nv) override;
};