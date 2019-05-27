#include<math.h>
#include<stdint.h>
#include<stdlib.h>
#include "fibonacci.h"
#include "../memoization/memo_long_int.h"

const char * fibonacci_n_parameter = "--fibonacci_n";
const char * fibonacci_version_parameter = "--fibonacci_version";
const char * solutions_fname = "solutions_fibonacci";

int64_t N;
int8_t version;
long int cache_misses, prev_cache_misses;

int64_t fibonacci(int64_t n);

int64_t (*memo_fibonacci_)(int64_t n);

int64_t memo_fibonacci_0a(int64_t n);
int64_t memo_fibonacci_0b(int64_t n);

int64_t memo_fibonacci_1a(int64_t n);
int64_t memo_fibonacci_1b(int64_t n);
int64_t memo_fibonacci_1c(int64_t n);
int64_t memo_fibonacci_1d(int64_t n);

int64_t memo_fibonacci_2a(int64_t n);

int64_t memo_fibonacci_2b(int64_t n);
int64_t memo_fibonacci_2c(int64_t n);
int64_t memo_fibonacci_2d(int64_t n);
int64_t memo_fibonacci_2e(int64_t n);

int64_t memo_fibonacci_2f(int64_t n);
int64_t memo_fibonacci_2g(int64_t n);
int64_t memo_fibonacci_2h(int64_t n);
int64_t memo_fibonacci_2i(int64_t n);
int64_t memo_fibonacci_2j(int64_t n);
int64_t memo_fibonacci_2k(int64_t n);

int64_t memo_fibonacci_2l(int64_t n);
int64_t memo_fibonacci_2m(int64_t n);
int64_t memo_fibonacci_2n(int64_t n);
int64_t memo_fibonacci_2o(int64_t n);

int64_t memo_fibonacci_2p(int64_t n);



int64_t memo_fibonacci_3a(int64_t n);

int64_t memo_fibonacci_3b(int64_t n);
int64_t memo_fibonacci_3c(int64_t n);
int64_t memo_fibonacci_3d(int64_t n);
int64_t memo_fibonacci_3e(int64_t n);

int64_t memo_fibonacci_3f(int64_t n);
int64_t memo_fibonacci_3g(int64_t n);
int64_t memo_fibonacci_3h(int64_t n);
int64_t memo_fibonacci_3i(int64_t n);
int64_t memo_fibonacci_3j(int64_t n);
int64_t memo_fibonacci_3k(int64_t n);

int64_t memo_fibonacci_3l(int64_t n);
int64_t memo_fibonacci_3m(int64_t n);
int64_t memo_fibonacci_3n(int64_t n);
int64_t memo_fibonacci_3o(int64_t n);

int64_t memo_fibonacci_3p(int64_t n);



int64_t memo_fibonacci_1(int64_t n);
int64_t memo_fibonacci_2(int64_t n);
int64_t memo_fibonacci_3(int64_t n);
int64_t memo_fibonacci_4(int64_t n);
int64_t memo_fibonacci_5(int64_t n);
int64_t memo_fibonacci_6(int64_t n);
int64_t memo_fibonacci_7(int64_t n);

char (*check_preemptive_halt_fibonacci_)();
char check_preemptive_halt_fibonacci_activated();
char check_preemptive_halt_fibonacci_deactivated();

/* PUBLIC */

void initialize_fibonacci(int argc, char **argv){
  N = -1;
  cache_misses = 0;
  char version[10];
  char found_version = 0;
  for(int g = 1; g < argc; g++){
    if(strcmp(argv[g], fibonacci_n_parameter) == 0){
      if(g+1 < argc){
        N = (int32_t) atoi(argv[++g]);
      }
    }
    if(strcmp(argv[g], fibonacci_version_parameter) == 0){
      if(g+1 < argc){
        strcpy(version, argv[++g]);
        found_version = 1;
      }
    }
  }

  memo_fibonacci_ = NULL;
  if(strcmp(version,"0a") == 0) memo_fibonacci_ = memo_fibonacci_0a;
  if(strcmp(version,"0b") == 0) memo_fibonacci_ = memo_fibonacci_0b;

  if(strcmp(version,"1a") == 0) memo_fibonacci_ = memo_fibonacci_1a;
  if(strcmp(version,"1b") == 0) memo_fibonacci_ = memo_fibonacci_1b;
  if(strcmp(version,"1c") == 0) memo_fibonacci_ = memo_fibonacci_1c;
  if(strcmp(version,"1d") == 0) memo_fibonacci_ = memo_fibonacci_1d;

  if(strcmp(version,"2a") == 0) memo_fibonacci_ = memo_fibonacci_2a;

  if(strcmp(version,"2b") == 0) memo_fibonacci_ = memo_fibonacci_2b;
  if(strcmp(version,"2c") == 0) memo_fibonacci_ = memo_fibonacci_2c;
  if(strcmp(version,"2d") == 0) memo_fibonacci_ = memo_fibonacci_2d;
  if(strcmp(version,"2e") == 0) memo_fibonacci_ = memo_fibonacci_2e;

  if(strcmp(version,"2f") == 0) memo_fibonacci_ = memo_fibonacci_2f;
  if(strcmp(version,"2g") == 0) memo_fibonacci_ = memo_fibonacci_2g;
  if(strcmp(version,"2h") == 0) memo_fibonacci_ = memo_fibonacci_2h;
  if(strcmp(version,"2i") == 0) memo_fibonacci_ = memo_fibonacci_2i;
  if(strcmp(version,"2j") == 0) memo_fibonacci_ = memo_fibonacci_2j;
  if(strcmp(version,"2k") == 0) memo_fibonacci_ = memo_fibonacci_2k;

  if(strcmp(version,"2l") == 0) memo_fibonacci_ = memo_fibonacci_2l;
  if(strcmp(version,"2m") == 0) memo_fibonacci_ = memo_fibonacci_2m;
  if(strcmp(version,"2n") == 0) memo_fibonacci_ = memo_fibonacci_2n;
  if(strcmp(version,"2o") == 0) memo_fibonacci_ = memo_fibonacci_2o;

  if(strcmp(version,"2p") == 0) memo_fibonacci_ = memo_fibonacci_2p;


  if(strcmp(version,"3a") == 0) memo_fibonacci_ = memo_fibonacci_3a;

  if(strcmp(version,"3b") == 0) memo_fibonacci_ = memo_fibonacci_3b;
  if(strcmp(version,"3c") == 0) memo_fibonacci_ = memo_fibonacci_3c;
  if(strcmp(version,"3d") == 0) memo_fibonacci_ = memo_fibonacci_3d;
  if(strcmp(version,"3e") == 0) memo_fibonacci_ = memo_fibonacci_3e;

  if(strcmp(version,"3f") == 0) memo_fibonacci_ = memo_fibonacci_3f;
  if(strcmp(version,"3g") == 0) memo_fibonacci_ = memo_fibonacci_3g;
  if(strcmp(version,"3h") == 0) memo_fibonacci_ = memo_fibonacci_3h;
  if(strcmp(version,"3i") == 0) memo_fibonacci_ = memo_fibonacci_3i;
  if(strcmp(version,"3j") == 0) memo_fibonacci_ = memo_fibonacci_3j;
  if(strcmp(version,"3k") == 0) memo_fibonacci_ = memo_fibonacci_3k;

  if(strcmp(version,"3l") == 0) memo_fibonacci_ = memo_fibonacci_3l;
  if(strcmp(version,"3m") == 0) memo_fibonacci_ = memo_fibonacci_3m;
  if(strcmp(version,"3n") == 0) memo_fibonacci_ = memo_fibonacci_3n;
  if(strcmp(version,"3o") == 0) memo_fibonacci_ = memo_fibonacci_3o;

  if(strcmp(version,"3p") == 0) memo_fibonacci_ = memo_fibonacci_3p;


  if( ! found_version ){
    fprintf(stderr, "Parameter --fibonacci_version not supplied, abort.\n");
    exit(1);
  }
  if(memo_fibonacci_ == NULL){
    fprintf(stderr, "Parameter --fibonacci_version invalid value, abort.\n");
    exit(1);
  }
  if(N == -1){
    fprintf(stderr, "Parameter --fibonacci_n not supplied, abort.\n");
    exit(1);
  }
  printf("initialize_fibonacci, N = %ld\n", N);
  printf("initialize_fibonacci, version = %s\n", version);
}

void reset_fibonacci(long int p){
  cache_misses = 0;
}

long int get_cache_misses_fibonacci(){
  return cache_misses;
}

void solve_fibonacci(){
  //printf("solve_fibonacci\n");
  int64_t result = fibonacci(N);
  printf("Done. fibonacci(%ld)=%ld\n", N, result);
  /*
  FILE * fp = fopen(solutions_fname, "a");
  if(fp == NULL){
    fprintf(fp, "Could not open %s\n", solutions_fname);
    exit(1);
  }
  fprintf(fp, "%d,%ld,%ld\n", version, N, result);
  fclose(fp);
  */
}

void set_cache_miss_threshold_fibonacci(int64_t t){
  prev_cache_misses = t;
}

void set_preemptive_halt_fibonacci(int p){
  //printf("set preemptive halt fibonacci %d\n", p);
  check_preemptive_halt_fibonacci_ = p ? check_preemptive_halt_fibonacci_activated : check_preemptive_halt_fibonacci_deactivated;
}


/* PRIVATE */

char check_preemptive_halt_fibonacci_deactivated(){
  return 0;
}

char check_preemptive_halt_fibonacci_activated(){
  //printf("check preemptive halt fibonacci activated  %ld  %ld\n", cache_misses, prev_cache_misses);
  return (cache_misses > prev_cache_misses) ? 1 : 0;
}

int64_t fibonacci(int64_t n){
  //printf("fibonacci n = %ld\n", n);
  int64_t key = n;
  int64_t * cache_key;
  cache_key = &key;
  int64_t * val;
  val = cache_read_long_int(cache_key);
  if(val == NULL){
    cache_misses++;
    int64_t result = memo_fibonacci_(n);
    val = &result;
    cache_write_long_int(cache_key, val);
  } 
  return *val;
}

int64_t memo_fibonacci_0a(int64_t n){//printf("0a\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  int64_t result = fibonacci(n-1) + fibonacci(n-2);
  return result;
}

int64_t memo_fibonacci_0b(int64_t n){//printf("0b\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  int64_t result = fibonacci(n-2) + fibonacci(n-1);
  return result;
}

int64_t memo_fibonacci_1a(int64_t n){//printf("1a\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f1 = fibonacci(k+1);
    int64_t f2 = fibonacci(k-1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f3 = fibonacci(k+1);
    int64_t f4 = fibonacci(k-1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1b(int64_t n){//printf("1b\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f2 = fibonacci(k-1);
    int64_t f1 = fibonacci(k+1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f3 = fibonacci(k+1);
    int64_t f4 = fibonacci(k-1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1c(int64_t n){//printf("1c\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f1 = fibonacci(k+1);
    int64_t f2 = fibonacci(k-1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f4 = fibonacci(k-1);
    int64_t f3 = fibonacci(k+1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1d(int64_t n){//printf("1d\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f2 = fibonacci(k-1);
    int64_t f1 = fibonacci(k+1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f4 = fibonacci(k-1);
    int64_t f3 = fibonacci(k+1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_2a(int64_t n){
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2b(int64_t n){//printf("2b\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2c(int64_t n){//printf("2c\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2d(int64_t n){//printf("2d\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2e(int64_t n){//printf("2e\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2f(int64_t n){//printf("2f\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2g(int64_t n){//printf("2g\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2h(int64_t n){//printf("2h\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2i(int64_t n){//printf("2i\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2j(int64_t n){//printf("2j\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2k(int64_t n){//printf("2k\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2l(int64_t n){//printf("2l\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2m(int64_t n){//printf("2m\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2n(int64_t n){//printf("2n\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2o(int64_t n){//printf("2o\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2p(int64_t n){//printf("2p\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}





int64_t memo_fibonacci_3a(int64_t n){
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3b(int64_t n){//printf("2b\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3c(int64_t n){//printf("2c\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3d(int64_t n){//printf("2d\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3e(int64_t n){//printf("2e\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3f(int64_t n){//printf("2f\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3g(int64_t n){//printf("2g\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3h(int64_t n){//printf("2h\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3i(int64_t n){//printf("2i\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3j(int64_t n){//printf("2j\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3k(int64_t n){//printf("2k\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3l(int64_t n){//printf("2l\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3m(int64_t n){//printf("2m\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3n(int64_t n){//printf("2n\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3o(int64_t n){//printf("2o\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_3p(int64_t n){//printf("2p\n");
  if(n <= 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

