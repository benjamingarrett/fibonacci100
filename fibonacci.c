#include<math.h>
#include<stdint.h>
#include<stdlib.h>
#include "fibonacci.h"
#include "../memoization/memo_long_int.h"

const char * fibonacci_n_parameter = "--fibonacci_n";
const char * fibonacci_version_parameter = "--fibonacci_version";
const char * solutions_fname = "solutions_fibonacci";
const char * fibonacci_execution_trace_fname_parameter = "--fibonacci_execution_trace_fname";

int64_t N;
int8_t version;
long int cache_misses, prev_cache_misses;

int64_t fibonacci(int64_t n);

int64_t (*memo_fibonacci_)(int64_t n);

int64_t memo_fibonacci_0a(int64_t n);
int64_t memo_fibonacci_0b(int64_t n);
int64_t memo_fibonacci_0c(int64_t n);

int64_t memo_fibonacci_1a(int64_t n);
int64_t memo_fibonacci_1ar(int64_t n);
int64_t memo_fibonacci_1ar3calls(int64_t n);
int64_t memo_fibonacci_1ar4calls(int64_t n);

int64_t memo_fibonacci_1b(int64_t n);
int64_t memo_fibonacci_1c(int64_t n);
int64_t memo_fibonacci_1d(int64_t n);

int64_t memo_fibonacci_2a(int64_t n);
int64_t memo_fibonacci_2ar(int64_t n);
int64_t memo_fibonacci_2ar3calls(int64_t n);
int64_t memo_fibonacci_2ar4calls(int64_t n);

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

char (*check_preemptive_halt_fibonacci_)();
char check_preemptive_halt_fibonacci_activated();
char check_preemptive_halt_fibonacci_deactivated();

char fibonacci_execution_trace_fname[400];
FILE * fp;

int64_t get_problem_size_fibonacci(){
  return N;
}

void initialize_fibonacci(int argc, char **argv){
  N = -1;
  cache_misses = 0;
  char version[10];
  char found_version = 0;
  int64_t g;
  for(g = 1; g < argc; g++){
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
    if(strcmp(argv[g], fibonacci_execution_trace_fname_parameter) == 0){
      if(g+1 < argc){
        strcpy(fibonacci_execution_trace_fname,&argv[++g][0]);
      }
    }
  }
  memo_fibonacci_ = NULL;
  if(strcmp(version,"0a") == 0) memo_fibonacci_ = memo_fibonacci_0a;
  if(strcmp(version,"0b") == 0) memo_fibonacci_ = memo_fibonacci_0b;
  if(strcmp(version,"0c") == 0) memo_fibonacci_ = memo_fibonacci_0c;
  if(strcmp(version,"1a") == 0) memo_fibonacci_ = memo_fibonacci_1a;
  if(strcmp(version,"1ar") == 0) memo_fibonacci_ = memo_fibonacci_1ar;
  if(strcmp(version,"1ar3calls") == 0) memo_fibonacci_ = memo_fibonacci_1ar3calls;
  if(strcmp(version,"1ar4calls") == 0) memo_fibonacci_ = memo_fibonacci_1ar4calls;
  if(strcmp(version,"1b") == 0) memo_fibonacci_ = memo_fibonacci_1b;
  if(strcmp(version,"1c") == 0) memo_fibonacci_ = memo_fibonacci_1c;
  if(strcmp(version,"1d") == 0) memo_fibonacci_ = memo_fibonacci_1d;
  if(strcmp(version,"2a") == 0) memo_fibonacci_ = memo_fibonacci_2a;
  if(strcmp(version,"2ar") == 0) memo_fibonacci_ = memo_fibonacci_2ar;
  if(strcmp(version,"2ar3calls") == 0) memo_fibonacci_ = memo_fibonacci_2ar3calls;
  if(strcmp(version,"2ar4calls") == 0) memo_fibonacci_ = memo_fibonacci_2ar4calls;
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
  fp=fopen(fibonacci_execution_trace_fname,"a");fprintf(fp,"initialize_fibonacci, N = %ld\n", N);fclose(fp);
  fp=fopen(fibonacci_execution_trace_fname,"a");fprintf(fp,"initialize_fibonacci, version = %s\n", version);fclose(fp);
}

void reset_fibonacci(long int p){
  cache_misses = 0;
}

long int get_cache_misses_fibonacci(){
  return cache_misses;
}

void solve_fibonacci(){
  fp=fopen(fibonacci_execution_trace_fname,"a");fprintf(fp,"solve_fibonacci\n");fclose(fp);
  int64_t result = fibonacci(N);
  fp=fopen(fibonacci_execution_trace_fname,"a");fprintf(fp,"Done. fibonacci(%ld)=%ld\n", N, result);fclose(fp);
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

int64_t memo_fibonacci_0a(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_0a, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  int64_t f1=fibonacci(n-1);
  int64_t f2=fibonacci(n-2);
  return f1+f2;
}
int64_t memo_fibonacci_0b(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_0b, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  int64_t f2=fibonacci(n-2);
  int64_t f1=fibonacci(n-1);
  return f1+f2;
}
int64_t memo_fibonacci_0c(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_0c, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  int64_t f1,f2;
  if(n%2==1){f1=fibonacci(n-1);f2=fibonacci(n-2);return f1+f2;}
  else{f2=fibonacci(n-2);f1=fibonacci(n-1);return f1+f2;}
}

int64_t memo_fibonacci_1a(int64_t n){
  if(n<0){fopen(fibonacci_execution_trace_fname,"a");fprintf(fp,"Error: memo_fibonacci_1a, n=%ld\n",n);fclose(fp);exit(1);}
  if(n==0)return 0;
  if(n==1)return 1;
  if(n==2)return 1;
  int64_t result = -1;
  int64_t k=(int64_t)((double)n/2.0);
  if(n%2==0){
    int64_t f1=fibonacci(k+1);
    int64_t f2=fibonacci(k-1);
    result=(f1+f2)*(f1-f2);
  } else {
    int64_t f3=fibonacci(k+1);
    int64_t f4=fibonacci(k-1);
    int64_t f5=(int64_t)(pow(-1.0, (double)(k)));
    result=(f3+f4)*f3-f5;
  }
  return result;
}

int64_t memo_fibonacci_1ar(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1ar, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f1=fibonacci(k+1);
    int64_t f2=fibonacci(k-1);
    f1=fibonacci(k+1);
    f2=fibonacci(k-1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f3=fibonacci(k+1);
    int64_t f4=fibonacci(k-1);
    f3=fibonacci(k+1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1ar3calls(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1ar3calls, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f1=fibonacci(k+1);
    int64_t f2=fibonacci(k-1);
    f1=fibonacci(k+1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f3=fibonacci(k+1);
    int64_t f4=fibonacci(k-1);
    f3=fibonacci(k+1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1ar4calls(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1ar4calls, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    int64_t f1=fibonacci(k+1);
    int64_t f2=fibonacci(k-1);
    f1=fibonacci(k+1);
    f2=fibonacci(k-1);
    result = (f1 + f2) * (f1 - f2);
  } else {
    int64_t f3=fibonacci(k+1);
    int64_t f4=fibonacci(k-1);
    f3=fibonacci(k+1);
    f4=fibonacci(k-1);
    int64_t f5 = (int64_t)(pow(-1.0, (double)(k)));
    result = (f3 + f4) * f3 - f5;
  }
  return result;
}

int64_t memo_fibonacci_1b(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1b, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
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

int64_t memo_fibonacci_1c(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1c, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
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

int64_t memo_fibonacci_1d(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_1d, n=%ld\n",n);exit(1);}
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
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
  if(n<0){fprintf(stderr,"memo_fibonacci_2a, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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

int64_t memo_fibonacci_2ar(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2ar, n=%ld is negative. Abort.\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1=fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3=fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5=fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7=fibonacci(k);
      f8=fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2ar3calls(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2ar3calls, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1=fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3=fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5=fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7=fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2ar4calls(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2ar4calls, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f1 = fibonacci(k);
      int64_t f2 = fibonacci(k+1);
      f1=fibonacci(k);
      f2=fibonacci(k+1);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      f3=fibonacci(k);
      f4=fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      f5=fibonacci(k+1);
      f6=fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      f7=fibonacci(k);
      f8=fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}



int64_t memo_fibonacci_2b(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2b, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
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

int64_t memo_fibonacci_2c(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2c, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
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

int64_t memo_fibonacci_2d(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2d, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2e(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2e, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2f(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2f, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
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

int64_t memo_fibonacci_2g(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2g, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2h(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2h, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
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
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2i(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2i, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2j(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2j, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2k(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2k, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2l(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2l, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f7 = fibonacci(k);
      int64_t f8 = fibonacci(k-1);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2m(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2m, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f5 = fibonacci(k+1);
      int64_t f6 = fibonacci(k);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2n(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2n, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f3 = fibonacci(k);
      int64_t f4 = fibonacci(k-1);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2o(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2o, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
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
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

int64_t memo_fibonacci_2p(int64_t n){
  if(n<0){fprintf(stderr,"memo_fibonacci_2p, n=%ld\n",n);exit(1);}
  if(n == 0) return 0;
  if(n == 1) return 1;
  //if(n == 2) return 1;
  int64_t result = -1;
  int64_t k = (int64_t)((double)n/2.0);
  if(n % 2 == 0){
    if(k % 2 == 0){
      int64_t f2 = fibonacci(k+1);
      int64_t f1 = fibonacci(k);
      result = f1 * (2 * f2 - f1);
    } else {
      int64_t f4 = fibonacci(k-1);
      int64_t f3 = fibonacci(k);
      result = f3 * (f3 + 2 * f4);
    }
  } else {
    if(k % 2 == 0){
      int64_t f6 = fibonacci(k);
      int64_t f5 = fibonacci(k+1);
      result = f5 * (2 * f5 - f6) - (int64_t)(pow(-1.0, (double)(k)));
    } else {
      int64_t f8 = fibonacci(k-1);
      int64_t f7 = fibonacci(k);
      result = (f7 + f8) * (f7 + 2 * f8) - (int64_t)(pow(-1.0, (double)(k)));
    }
  }
  return result;
}

