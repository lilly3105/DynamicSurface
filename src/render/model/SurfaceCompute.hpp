#pragma once
#include <osg/Array>


struct SurfaceData {
  osg::ref_ptr<osg::Vec3Array> vertices;
  osg::ref_ptr<osg::Vec3Array> normals;
  size_t length;
};

class SurfaceCompute {
public:
  void compute(const SurfaceData &data, double t, double a, double b) const;
};
