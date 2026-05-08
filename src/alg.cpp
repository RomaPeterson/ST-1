// Copyright 2025 UNN-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  for (uint64_t i = 2; i * i <= value; ++i) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t counter_simp_num = 0;
  uint64_t result = 1;

  while (counter_simp_num < n) {
    result++;
    if (checkPrime(result)) {
      counter_simp_num++;
    }
  }

  return result;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t result = value + 1;

  while (!checkPrime(result)) {
    result++;
  }

  return result;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }

  return sum;
}
