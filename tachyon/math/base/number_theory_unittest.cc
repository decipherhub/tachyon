#include "tachyon/math/base/number_theory.h"

#include "gtest/gtest.h"

#include "tachyon/math/base/big_int.h"

namespace tachyon::math {

TEST(NumberTheoryTest, GreatestCommonDivisorSmallNumber) {
  BigInt<1> a = BigInt<1>(10403);
  BigInt<1> b = BigInt<1>(103);
  BigInt<1> c = GreatestCommonDivisor(a, b);

  BigInt<1> expected_result = BigInt<1>(103);

  EXPECT_EQ(expected_result, c);

  a = BigInt<1>(1048576);
  b = BigInt<1>(4096);

  c = GreatestCommonDivisor(a, b);

  EXPECT_EQ(b, c);
}

TEST(NumberTheoryTest, GreatestCommonDivisorBigNumber) {
  BigInt<2> a = *BigInt<2>::FromDecString("883035439563027");
  BigInt<2> b = *BigInt<2>::FromDecString("3042269397984931");
  BigInt<2> c = GreatestCommonDivisor(a, b);

  BigInt<2> expected_result = BigInt<2>(1);

  EXPECT_EQ(expected_result, c);
}

}  // namespace tachyon::math
