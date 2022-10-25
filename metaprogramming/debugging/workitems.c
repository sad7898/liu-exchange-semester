#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//The mutex object referenced by mutex shall be locked by calling pthread_mutex_lock(). 
//If the mutex is already locked, the calling thread shall block until the mutex becomes available. 

//The thread can ask the mutex to have the right to execute itself, only the one with its can do that
// https://stackoverflow.com/questions/34524/what-is-a-mutex      => explanation

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;; 


typedef struct workitem {
  void (*fn)(double *);
  int current;
  int len;
  double *data;
  int started;
} workitem;

static void* launchThread(void *in)
{
  int n;
  workitem *data = (workitem*) in;
  volatile int started = 0;
  while (!(started = data->started));
  while (1) {

    pthread_mutex_lock(&lock); //lock, only one thread is executed at this time
    n = data->current++;
    pthread_mutex_unlock(&lock); //free the mutex to give it to another thread

    if (n >= data->len) break;
    data->fn(&data->data[n]);

  }
  return NULL;
}

void launchParallel(int numThreads, double *values, int len, void (*fn)(double *))
{
  workitem *data = calloc(1, sizeof(workitem));
  pthread_t th[numThreads];

  memset(th, 0, numThreads*sizeof(pthread_t));

  data->fn = fn;
  data->current = 0;
  data->len = len;
  data->data = values;
  data->started = 0;

  for (int i=0; i<numThreads; i++) {
    assert(0 == pthread_create(&th[i], NULL, launchThread, data));
  }
  data->started = 1;
  for (int i=0; i<numThreads; i++) {
    assert(th[i] && 0==pthread_join(th[i], NULL));
  }
  assert(data->current >= len);
  free(data);
}

void mul2(double *d)
{
  *d = *d * 2;
}

int main(int argc, char **argv)
{
  double vals[100];
  for (int i=0; i<100; i++) {
    vals[i] = i*1.5;
  }
  launchParallel(4 /* Increase this if no error occurs */, vals, 100, mul2);
  for (int i=0; i<100; i++) {
    if (vals[i] != 1.5*2*i) {
      fprintf(stderr, "Expected vals[%d] to have value %.1f, got value %.1f\n", i, (double)1.5*2*i, (double)vals[i]);
    }
  }
  return 0;
}
