#include "ModelUpdateCallback.hpp"

#include "Model.hpp"

void ModelUpdateCallback::operator()(osg::Node *node, osg::NodeVisitor *nv) {
  auto *model = static_cast<Model*>(node);

  const double time = nv->getFrameStamp()->getSimulationTime();

  model->update(time);

  traverse(node, nv);
}