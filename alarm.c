#include <stdio.h>
#include <unistd.h>

int main()
{
  alarm(10);
  for(;;)
  {
    printf("H\n");
    usleep(100000);
  }
  return 0;
}