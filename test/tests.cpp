// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}


TEST(CheckPrimeTest, SmallPrimes) {
  EXPECT_TRUE(checkPrime(29));
  EXPECT_TRUE(checkPrime(53));
  EXPECT_TRUE(checkPrime(79));
  EXPECT_TRUE(checkPrime(97));
}

TEST(CheckPrimeTest, LargePrimes) {
  EXPECT_TRUE(checkPrime(999959));
  EXPECT_TRUE(checkPrime(1000003));
  EXPECT_TRUE(checkPrime(1000033));
}

TEST(CheckPrimeTest, Composites) {
  EXPECT_FALSE(checkPrime(15));
  EXPECT_FALSE(checkPrime(20));
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(30));
  EXPECT_FALSE(checkPrime(35));
  EXPECT_FALSE(checkPrime(40));
}


TEST(NPrimeTest, EdgeCases) {
  EXPECT_EQ(nPrime(0), 0);
  EXPECT_EQ(nPrime(1), 2);
}

TEST(NPrimeTest, SmallN) {
  EXPECT_EQ(nPrime(5), 11);
  EXPECT_EQ(nPrime(10), 29);
  EXPECT_EQ(nPrime(15), 47);
}

TEST(NPrimeTest, LargerN) {
  EXPECT_EQ(nPrime(20), 71);
  EXPECT_EQ(nPrime(25), 97);
  EXPECT_EQ(nPrime(30), 113);
}


TEST(NextPrimeTest, SmallValues) {
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(4), 5);
  EXPECT_EQ(nextPrime(10), 11);
  EXPECT_EQ(nextPrime(11), 13);
}

TEST(NextPrimeTest, LargeGaps) {
  EXPECT_EQ(nextPrime(113), 127);
  EXPECT_EQ(nextPrime(114), 127);
}


TEST(SumPrimeTest, EdgeCases) {
  EXPECT_EQ(sumPrime(2), 0);
  EXPECT_EQ(sumPrime(3), 2);
}

TEST(SumPrimeTest, SmallBounds) {
  EXPECT_EQ(sumPrime(6), 10);
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(20), 77);
}

TEST(SumPrimeTest, LargerBounds) {
  EXPECT_EQ(sumPrime(100), 1060);
  EXPECT_EQ(sumPrime(1000), 76127);
}
