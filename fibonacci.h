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

#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../memoization/memo_long_int.h"
void initialize_fibonacci(int argc, char **argv);
void reset_fibonacci();
int32_t get_cache_misses_fibonacci();
int32_t get_cache_hits_fibonacci();
void solve_fibonacci();

#ifdef __cplusplus
}
#endif

#endif 
