#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }
  if (value == 2 || value == 3) {
    return true;
  }

  if (value % 2 == 0 || value % 3 == 0) {
    return false;
  }

  uint64_t sqrt_val = static_cast<uint64_t>(sqrt(value));
  for (uint64_t i = 5; i <= sqrt_val; i += 6) {
    if (value % i == 0) {
      return false;
    }
    if (value % (i + 2) == 0) {
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

  if (n == 2) {
    return 3;
  }

  uint64_t count = 2;
  uint64_t candidate = 5;
  int increment = 2;

  while (count < n) {
    if (checkPrime(candidate)) {
      count++;
    }
    if (count < n) {
      candidate += increment;
      increment = (increment == 2) ? 4 : 2;
    }
  }

  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }

  if (value == 2) {
    return 3;
  }

  uint64_t next_val = value + 1;
  if (next_val % 2 == 0) {
    next_val++;
  }

  while (true) {
    if (checkPrime(next_val)) {
      return next_val;
    }
    next_val += 2;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t num = 2; num < hbound; num++) {
    if (checkPrime(num)) {
      sum += num;
    }
  }

  return sum;
}
