#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void handler(){
  printf("Oh yeah!\n");
}

int main()
{
   sigset_t sigset;
   struct sigevent evp;
   timer_t timer;
   struct itimerspec ts;
   
   // initialize the signal set and SIGRTMIN as signal we're are interested in
   sigemptyset(&sigset);
   sigaddset(&sigset, SIGRTMIN);
   
   // Block the signal we're interested in, this allows us to receive signal information as and when when ready to process  it, as opposed to using 
   // sigaction which can only process one signal at a time(if a timer fires while processing another signal handler, typically its is missed)
   
   sigprocmask(SIG_BLOCK, &sigset, NULL);
   
   // construct a sigevent structure
   evp.sigev_notify = SIGEV_SIGNAL;
   evp.sigev_signo = SIGRTMIN;
   evp.sigev_value.sival_int = 20;
   
   // create a new timer
   if(timer_create(CLOCK_MONOTONIC, &evp, &timer))
     perror("timer_create");
   
   // arm timer
   ts.it_value.tv_sec = 1;
   ts.it_value.tv_nsec = 0;
   ts.it_interval.tv_sec = 1;
   ts.it_interval.tv_nsec = 10000000;
   
   if(timer_settime(timer, 0, &ts, NULL))
     perror("time_settime");
   
   // loop untill killed
   while(1)
   {
     siginfo_t info;
     sigemptyset(&sigset);
     sigaddset(&sigset, SIGRTMIN);
     
     // can use a sigtimedwait here to specify a maximum wait time
     // for interesting events. for instance this woiuld allow to perform idle operations where system is not busy
     
     while(sigwaitinfo(&sigset, &info) > 0)
     {
       printf("[%d] caught signal %d\n", (int)time(0), info.si_value.sival_int);
     }
     
   }
   if(timer_delete(timer))
   {
     perror("timer_delete");
   }
   
   return 0;
}
