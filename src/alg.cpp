// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  
  if (value % 2 == 0 || value % 3 == 0) return false;
  
  uint64_t limit = static_cast<uint64_t>(sqrt(value));
  for (uint64_t k = 5; k <= limit; k += 6) {
    if (value % k == 0 || value % (k + 2) == 0) {
      return false;
    }
  }
  
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;
  if (n == 2) return 3;
  
  uint64_t primes_found = 2;
  uint64_t current = 5;
  
  bool check_plus_one = true;
  
  while (primes_found < n) {
    if (checkPrime(current)) {
      primes_found++;
      if (primes_found == n) return current;
    }
    
    current += check_plus_one ? 2 : 4;
    check_plus_one = !check_plus_one;
  }
  
  return current;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  if (value == 2) return 3;
  
  uint64_t next = (value % 2 == 0) ? value + 1 : value + 2;
  
  while (next % 3 == 0) {
    next += 2;
  }
  
  bool step_two = ((next - 1) % 6 == 0);
  
  while (!checkPrime(next)) {
    next += step_two ? 4 : 2;
    step_two = !step_two;
  }
  
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  
  uint64_t accumulator = 0;
  
  if (hbound > 2) accumulator += 2;
  if (hbound > 3) accumulator += 3;
  
  for (uint64_t base = 6; base < hbound; base += 6) {
    uint64_t candidate1 = base - 1;
    uint64_t candidate2 = base + 1;
    
    if (candidate1 < hbound && checkPrime(candidate1)) {
      accumulator += candidate1;
    }
    
    if (candidate2 < hbound && checkPrime(candidate2)) {
      accumulator += candidate2;
    }
  }
  
  return accumulator;
}
