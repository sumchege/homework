#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main()
{
struct timespec clock_resolution;
int stat;
stat = clock_getres(CLOCK_REALTIME, &clock_resolution);
printf("Clock Resolution: %d seconds, %ld nanoseconds.\n", clock_resolution.tv_sec, clock_resolution.tv_nsec);
return 0;
}
