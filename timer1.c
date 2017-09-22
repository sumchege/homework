#include <stdio.h>
#include <signal.h>
#include <time.h>

int count = 0;

void timer_intr(int sig, siginfo_t *info, void *cruft)
{
  // periodic processing and exit
  if(count >=100)
    count = 0;
  
  printf("[%d] count: %d\n", (int)time(0), count);
  count++;
  
}

void timerCreate(int num_secs, int num_nsecs)
{
  struct sigaction sa;
  struct sigevent evp;
  sigset_t allsigs;
  struct itimerspec ts;
  timer_t timer;
  
  // setup signal to respond to timer
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = timer_intr;
  
  if(sigaction(SIGRTMIN, &sa, NULL) < 0)
    perror("sigaction");
  
  evp.sigev_notify = SIGEV_SIGNAL;
  evp.sigev_signo = SIGRTMIN;
  
  // create a timer
  if(timer_create(CLOCK_MONOTONIC, &evp, &timer))
    perror("timer_create");
  
  // Arm timer
   ts.it_value.tv_sec = 1;
   ts.it_value.tv_nsec = 0;
   ts.it_interval.tv_sec = num_secs;
   ts.it_interval.tv_nsec = num_nsecs;
   
   if(timer_settime(timer, 0, &ts, NULL))
     perror("time_settime");
   
   // wait for signals
   sigemptyset(&allsigs);
   
   while(1){
     sigsuspend(&allsigs);
   }
   
   if(timer_delete(timer))
     perror("timer_delete");
   
}


int main()
{
  timerCreate(0, 200000000);
  return 0;
}