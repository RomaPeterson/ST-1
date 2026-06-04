// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(CheckPrimeTests, TestZeroIsNotPrime) {
  EXPECT_FALSE(checkPrime(0));
}

TEST(CheckPrimeTests, TestOneIsNotPrime) {
  EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrimeTests, TestTwoIsPrime) {
  EXPECT_TRUE(checkPrime(2));
}

TEST(CheckPrimeTests, TestSmallPrimes) {
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(13));
}

TEST(CheckPrimeTests, TestCompositeNumbers) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(8));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(10));
}

TEST(CheckPrimeTests, TestLargePrime) {
  EXPECT_TRUE(checkPrime(7919));
  EXPECT_TRUE(checkPrime(97));
}

TEST(NPrimeTests, TestZeroIndex) {
  EXPECT_EQ(nPrime(0), 0);
}

TEST(NPrimeTests, TestFirstThreePrimes) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
}

TEST(NPrimeTests, TestTenthPrime) {
  EXPECT_EQ(nPrime(10), 29);
}

TEST(NPrimeTests, TestFiftiethPrime) {
  EXPECT_EQ(nPrime(50), 229);
}

TEST(NextPrimeTests, TestAfterZero) {
  EXPECT_EQ(nextPrime(0), 2);
}

TEST(NextPrimeTests, TestAfterTwo) {
  EXPECT_EQ(nextPrime(2), 3);
}

TEST(NextPrimeTests, TestAfterFour) {
  EXPECT_EQ(nextPrime(4), 5);
}

TEST(NextPrimeTests, TestAfterEleven) {
  EXPECT_EQ(nextPrime(11), 13);
}

TEST(SumPrimeTests, TestSumBelowTwo) {
  EXPECT_EQ(sumPrime(2), 0);
}

TEST(SumPrimeTests, TestSumBelowThree) {
  EXPECT_EQ(sumPrime(3), 2);
}

TEST(SumPrimeTests, TestSumBelowTen) {
  EXPECT_EQ(sumPrime(10), 17);
}

TEST(SumPrimeTests, TestSumBelowSix) {
  EXPECT_EQ(sumPrime(6), 10);  // Исправлено: 2 + 3 + 5 = 10
}

TEST(SumPrimeTests, TestSumBelowTwelve) {
  EXPECT_EQ(sumPrime(12), 28);
}

TEST(SumPrimeTests, TestSumBelowHundred) {
  EXPECT_EQ(sumPrime(100), 1060);
}
