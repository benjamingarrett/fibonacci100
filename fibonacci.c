#include "fibonacci.h"

char * fibonacci_n_parameter = "--fibonacci_n";
char * fibonacci_version_parameter = "--fibonacci_version";

int64_t n;
int8_t version;
long int cache_misses, cache_hits;

int64_t fibonacci(int64_t n);

int64_t (*memo_fibonacci_)(int64_t n);
int64_t memo_fibonacci_1(int64_t n);
int64_t memo_fibonacci_2(int64_t n);

/* PUBLIC */

void initialize_fibonacci(int argc, char **argv){

  n = -1;
  cache_misses = cache_hits = 0;
  for(int g = 1; g < argc; g++){
    if(strcmp(argv[g], fibonacci_n_parameter) == 0){
      if(g+1 < argc){
        n = (int32_t) atoi(argv[++g]);
      }
    }
    if(strcmp(argv[g], fibonacci_version_parameter) == 0){
      if(g+1 < argc){
        version = (int8_t) atoi(argv[++g]);
      }
    }
  }
  switch(version){
    case 1:
      memo_fibonacci_ = memo_fibonacci_1;
      break;
    case 2:
      memo_fibonacci_ = memo_fibonacci_2;
      break;
    default:
      fprintf(stderr, "Parameter --fibonacci_version not supplied, abort.\n");
  }
  if(n == -1){
    fprintf(stderr, "Parameter --fibonacci_n not supplied, abort.\n");
    exit(1);
  }
}

void reset_fibonacci(){
  cache_misses = cache_hits = 0;
}

int32_t get_cache_misses_fibonacci(){
  return cache_misses;
}

int32_t get_cache_hits_fibonacci(){
  return cache_hits;
}

void solve_fibonacci(){
  fibonacci(n);
}

/* PRIVATE */

int64_t fibonacci(int64_t n){
  int64_t * val;
  uint64_t * key;
  int64_t result;
  *key = n;
  val = cache_read_long_int(key);
  if(val == NULL){
    cache_misses++;
    result = memo_fibonacci_(n);
    val = &result;
    cache_write_long_int(key, val);
  } else {
    cache_hits++;
  }
  result = *val;
  return result;
}

int64_t memo_fibonacci_1(int64_t n){
  if(n==0){
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int64_t memo_fibonacci_2(int64_t n){
  if(n==0){
    return 1;
  }
  return fibonacci(n-2) + fibonacci(n-1);
}
