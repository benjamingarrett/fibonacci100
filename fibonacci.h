/*
 * File:   fibonacci.h
 * Author: benjamin
 *
 * Created on July 30, 2018, 3:09 PM
 */

#ifndef FIBONACCI_H
#define FIBONACCI_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "../memoization/memo_long_int.h"
  void initialize_fibonacci(int argc, char **argv);
  void reset_fibonacci(long int p);
  long int get_cache_misses_fibonacci();
  void solve_fibonacci();
  void set_cache_miss_threshold_fibonacci(int64_t t);
  void set_preemptive_halt_fibonacci(int p);
  int64_t get_problem_size_fibonacci();

#ifdef __cplusplus
}
#endif

#endif 
