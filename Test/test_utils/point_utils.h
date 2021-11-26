#pragma once

#include "common_utils.h"
#include "main/primitives/point.h"

namespace segeom {
  namespace test_utils {
    /**
     * @brief Generates a new random 3D point using a given random number generator.
     */
    segeom::primitives::Point3D<double> rand_point_3d(Random *rng, double lo, double hi);

    /**
     * @brief Generates a new random 3D point using a given random number generator.
     */
    segeom::primitives::Point2D<double> rand_point_2d(Random *rng, double lo = -1000000, double hi = 1000000);
  } // namespace test_utils
} // namespace segeom