#include "../../GeometricFault/Primitives/PointND.h"
#include "../TestUtils/PointUtils.h"
#include "../Testing.h"
#include "gtest/gtest.h"

namespace Utils = Segeom::TestUtils;
using namespace Segeom::Primitives;

class PointNDTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
  double x = 0;
  double y = 0;
  PointND<double>* testPoint = nullptr;
  std::vector<double> testCoordinates;
};

void PointNDTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  rng->randDoubleStdVector(-1000000, 1000000, &this->testCoordinates);
  this->testPoint = new PointND<double>(this->testCoordinates);
}

void PointNDTest::TearDown() { notifyOnFailure(this->seed); }

#pragma region EQUALITY
/// <summary>
/// Two points with the same coordinates are equal.
/// </summary>
TEST_F(PointNDTest, Equality) {
  PointND<double> expected(this->testCoordinates);
  EXPECT_EQ(expected, *testPoint);
}

/// <summary>
/// Two points with different dimensions are different
/// </summary>
TEST_F(PointNDTest, DifferentDimensions) {
  std::vector<double> unexpected;
  do {
    this->rng->randDoubleStdVector(-1000000, 1000000, &unexpected);
  } while (unexpected.size() == this->testCoordinates.size());
  EXPECT_NE(PointND<double>{unexpected}, *testPoint);

  int length = rng->nextInt(0, this->testCoordinates.size());
  std::vector<double> sublist =
      *Utils::sublist(this->testCoordinates, 0, length);
  EXPECT_NE(PointND<double>{sublist}, *this->testPoint);
}

/// <summary>
/// Points with different elements but same length are different.
/// </summary>
TEST_F(PointNDTest, Distinct) {
  std::vector<double> displacedVector =
      Utils::translateStdVec(this->testCoordinates, *this->rng);
  PointND<double> unexpected(displacedVector);
  EXPECT_NE(unexpected, *this->testPoint);
}
#pragma endregion

#pragma region ADDITION
TEST_F(PointNDTest, IdentityAdditionTest) {
  std::vector<double> zeroVec(this->testPoint->getSize(), 0);
  PointND<double> zeroPoint(zeroVec);
  EXPECT_EQ(zeroPoint + *testPoint, *testPoint);
}
#pragma endregion

#pragma region UTILITY
TEST_F(PointNDTest, Size) {
  EXPECT_EQ(this->testCoordinates.size(), this->testPoint->getSize());
}
#pragma endregion
//
// TEST_F(PointTest, AdditionTest) {
//  Point<double> other(rng->nextDouble(-5000000, 5000000),
//                      rng->nextDouble(-5000000, 5000000));
//  Point<double> expectedPoint(testPoint->getX() + other.getX(),
//                              testPoint->getY() + other.getY());
//  Point<double> actualPoint = *testPoint + other;
//  EXPECT_EQ(expectedPoint, actualPoint);
//}
//
// TEST_F(PointTest, SubtractionTest) {
//  Point<double> other(rng->nextDouble(-5000000, 5000000),
//                      rng->nextDouble(-5000000, 5000000));
//  Point<double> expectedPoint(testPoint->getX() - other.getX(),
//                              testPoint->getY() - other.getY());
//  Point<double> actualPoint = *testPoint - other;
//  EXPECT_EQ(expectedPoint, actualPoint);
//}
//
// TEST_F(PointTest, MultiplicationTest) {
//  Point<double> other(rng->nextDouble(-5000000, 5000000),
//                      rng->nextDouble(-5000000, 5000000));
//  double scalar = rng->nextDouble(-1000, 1000);
//  Point<double> expectedPoint(testPoint->getX() * scalar,
// testPoint->getY() * scal