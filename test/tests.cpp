// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(PrimalityTesting, BoundaryValues) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
}

TEST(PrimalityTesting, FirstDozenPrimes) {
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(13));
  EXPECT_TRUE(checkPrime(17));
  EXPECT_TRUE(checkPrime(19));
  EXPECT_TRUE(checkPrime(23));
}

TEST(PrimalityTesting, CompositeDetection) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(21));
  EXPECT_FALSE(checkPrime(25));
}

TEST(PrimalityTesting, LargeNumberValidation) {
  EXPECT_TRUE(checkPrime(7919));
  EXPECT_FALSE(checkPrime(7920));
  EXPECT_TRUE(checkPrime(999983));
}

TEST(NthPrimeFinder, InitialElements) {
  EXPECT_EQ(nPrime(0), 0);
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
}

TEST(NthPrimeFinder, MiddleRangePrimes) {
  EXPECT_EQ(nPrime(7), 17);
  EXPECT_EQ(nPrime(12), 37);
  EXPECT_EQ(nPrime(20), 71);
}

TEST(NthPrimeFinder, HigherOrderPrimes) {
  EXPECT_EQ(nPrime(50), 229);
  EXPECT_EQ(nPrime(100), 541);
}

TEST(SuccessorPrime, AfterSmallIntegers) {
  EXPECT_EQ(nextPrime(0), 2);
  EXPECT_EQ(nextPrime(1), 2);
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(5), 7);
}

TEST(SuccessorPrime, JumpingGaps) {
  EXPECT_EQ(nextPrime(14), 17);
  EXPECT_EQ(nextPrime(20), 23);
  EXPECT_EQ(nextPrime(88), 89);
}

TEST(SuccessorPrime, AfterPrimeItself) {
  EXPECT_EQ(nextPrime(13), 17);
  EXPECT_EQ(nextPrime(37), 41);
}

TEST(PrimeAccumulation, EmptyRanges) {
  EXPECT_EQ(sumPrime(0), 0);
  EXPECT_EQ(sumPrime(1), 0);
  EXPECT_EQ(sumPrime(2), 0);
}

TEST(PrimeAccumulation, TinyBounds) {
  EXPECT_EQ(sumPrime(3), 2);
  EXPECT_EQ(sumPrime(6), 10);
  EXPECT_EQ(sumPrime(12), 28);
}

TEST(PrimeAccumulation, StandardBenchmarks) {
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(100), 1060);
  EXPECT_EQ(sumPrime(2000000), 142913828922);
}
