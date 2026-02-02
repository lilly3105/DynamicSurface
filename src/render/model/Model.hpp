#pragma once

#include <memory>
#include <osg/Geode>

#include "SurfaceCompute.hpp"

class ISurfaceParameters;
class SurfaceCompute;

class Model final : public osg::Geode {
public:

  Model(const ISurfaceParameters* params);
  void update(double t) const;
private:
  static void buildGridIndices(osg::DrawElementsUInt *indices, size_t length);

  osg::ref_ptr<osg::Geometry> geometry_;
  std::unique_ptr<SurfaceCompute> compute_;
  SurfaceData data_;

  const ISurfaceParameters* params_;
};