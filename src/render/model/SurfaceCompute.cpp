#include "SurfaceCompute.hpp"

#include <osg/PrimitiveSet>

void SurfaceCompute::compute(const SurfaceData &data, double t, double a, double b) const {
  const size_t length = data.length;
  const float halfLength = length * 0.5f;

  osg::Vec3Array &vertices = *data.vertices;
  osg::Vec3Array &normals = *data.normals;

  size_t idx = 0;

  for (size_t xx = 0; xx <= length; ++xx) {
    const float x = static_cast<float>(xx) - halfLength;

    for (size_t yy = 0; yy <= length; ++yy) {
      const float y = static_cast<float>(yy) - halfLength;

      const float a2 = a * a;
      const float b2 = b * b;
      const float x2 = x * x;
      const float y2 = y * y;
      const float sin2 = (1.f - std::cos(2.f * t)) * 0.5f;

      const float z =
          std::sqrt(x2 / b2 + y2 / (a2 * sin2) + 1.f);

      // ---------- +z ----------
      {
        vertices[idx].set(x, y, z);

        osg::Vec3 n(
          a2 * sin2 * x,
          b2 * y,
          -a2 * b2 * sin2 * z
        );
        n.normalize();

        normals[idx] = n;
        ++idx;
      }

      // ---------- -z ----------
      {
        vertices[idx].set(x, y, -z);

        osg::Vec3 n(
          a2 * sin2 * x,
          b2 * y,
          a2 * b2 * sin2 * z
        );
        n.normalize();

        normals[idx] = n;
        ++idx;
      }
    }
  }
}
