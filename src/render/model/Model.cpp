#include "Model.hpp"

#include "SurfaceCompute.hpp"

#include <osg/Geometry>

#include "ISurfaceParameters.hpp"

Model::Model(const ISurfaceParameters* params) : params_(params) {
  geometry_ = new osg::Geometry;
  addDrawable(geometry_);

  data_.length = 250;
  const size_t verts = 2 * (data_.length + 1) * (data_.length + 1);
  data_.vertices = new osg::Vec3Array(verts);
  data_.normals = new osg::Vec3Array(verts);

  const osg::ref_ptr indices = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES);
  buildGridIndices(indices.get(), data_.length);

  geometry_->setVertexArray(data_.vertices.get());
  geometry_->setNormalArray(
      data_.normals.get(),
      osg::Array::BIND_PER_VERTEX);

  const float r = data_.length * 0.75f;
  setInitialBound(osg::BoundingBox(
      -r, -r, -r,
       r,  r,  r
  ));


  geometry_->addPrimitiveSet(indices.get());

  geometry_->setUseDisplayList(false);
  geometry_->setUseVertexBufferObjects(true);

  compute_ = std::make_unique<SurfaceCompute>();
}

void Model::update(double t) const {
  compute_->compute(data_, t, params_->a(), params_->b());

  data_.vertices->dirty();
  data_.normals->dirty();

  geometry_->dirtyBound();
}

void Model::buildGridIndices(osg::DrawElementsUInt *indices, size_t length) {
  indices->resize(6 * (length * length) * 2);

  size_t idx = 0;

  for (size_t i = 0; i < length; ++i) {
    for (size_t j = 0; j < length; ++j) {
      const size_t v00 = (i * (length + 1) + j) * 2;
      const size_t v10 = ((i + 1) * (length + 1) + j) * 2;
      const size_t v01 = (i * (length + 1) + (j + 1)) * 2;
      const size_t v11 = ((i + 1) * (length + 1) + (j + 1)) * 2;

      // +z -> branch = 0
      (*indices)[idx] = v00;
      (*indices)[++idx] = v10;
      (*indices)[++idx] = v01;

      (*indices)[++idx] = v01;
      (*indices)[++idx] = v10;
      (*indices)[++idx] = v11;

      ++idx;
    }
  }
  for (size_t i = 0; i < length; ++i) {
    for (size_t j = 0; j < length; ++j) {

      const size_t v00 = (i * (length + 1) + j) * 2 + 1;
      const size_t v10 = ((i + 1) * (length + 1) + j) * 2 + 1;
      const size_t v01 = (i * (length + 1) + (j + 1)) * 2 + 1;
      const size_t v11 = ((i + 1) * (length + 1) + (j + 1)) * 2 + 1;

      // −z -> branch = 1
      (*indices)[idx] = v00;
      (*indices)[++idx] = v01;
      (*indices)[++idx] = v10;

      (*indices)[++idx] = v01;
      (*indices)[++idx] = v11;
      (*indices)[++idx] = v10;

      ++idx;
    }
  }
}
