// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }

  uint64_t limit = static_cast<uint64_t>(sqrt(value));
  for (uint64_t divisor = 3; divisor <= limit; divisor += 2) {
    if (value % divisor == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 2;
  }

  uint64_t counter = 1;
  uint64_t current_number = 3;

  while (counter < n) {
    if (checkPrime(current_number)) {
      counter++;
    }
    if (counter < n) {
      current_number += 2;
    }
  }

  return current_number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next_candidate = value + 1;

  while (!checkPrime(next_candidate)) {
    next_candidate++;
  }

  return next_candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t total = 0;

  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      total += i;
    }
  }

  return total;
}
