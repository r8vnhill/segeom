#pragma once
#include "segment.h"

namespace segeom {
  namespace primitives {
    /**
     * @brief Representation of a polygon.
     *        A polygon is defined by the segments that conform its sides.
     *
     * @tparam T
     *    A numerical data type. Behaviour for non-numerical types is undefined.
     */
    template <class T>
    class Polygon {
    private:
      std::vector<Point2D<T> *> vertices_;
      std::vector<Segment<T> *> sides_;

    public:
      Polygon(/* args */);
      ~Polygon();

      /**
       * @brief Returns a vector containing the vertices of the polygon.
       */
      inline std::vector<Point2D<T> *> vertices() const;

      /**
       * @brief Returns a vector containing the sides of the polygon.
       */
      inline std::vector<Segment<T> *> sides() const;
    };
  } // namespace primitives
} // namespace segeom

using namespace segeom::primitives;

template <class T>
inline std::vector<Point2D<T> *> Polygon<T>::vertices() const {
  return vertices_;
}

template <class T>
inline std::vector<Segment<T> *> Polygon<T>::sides() const {
  return sides_;
}
