#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>


#define WRITE_INTERVAL 500*1000     // 500ms

void * reader(void *fd);
void  writer(void *fd);

int main()
{
    pthread_t readerThread;
    char pipeName[] = "/tmp/trypipe";
    int ret_val = mkfifo(pipeName, 0666);
    
    if(ret_val == -1) && (errno == !=EEXIST)
    {
        perror("Error creating pipe");
    }
    
    // Open both endswithin the process in non blocking mode
    int readfd = open(pipeName, O_RDONLY|O_NONBLOCK);
    int writefd = open(pipeName, O_WRONLY|O_NONBLOCK);
    
    // implement a reader and writer for these fds
    pthread_create(&readerThread, NULL, &reader, (void*)(&readfd));
    
    //use main thread as writer
    
    writer((void*)(&writefd));
     
}

// callback function for void writer(void* fd)
{
}

void writer(void *fd)
{
    int writefd = (*(int*)fd);
    static int var = 0;
    
    while(1){
        // data to be written on pipe
        printf("\nWriter: %d", var);
        
        // write to pipe
        write(writefd, (int*)(&var), sizeof(var));
        
        var++;
        usleep(WRITE_INTERVAL);
        
    }
}

// callback for reader

void *reader(void *fd)
{
    
    int readfd = (*(int*)fd);
    fd_set readset;
    int data = 0, err = 0, size = 0;
    
    // init time struct
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
    
    // receiver loop
    while(1)
    {
        FD_ZERO(&readset);
        FD_SET(readfd, &readset);
        
        // check for readability
        err = select(readfd+1, &readset, NULL, NULL, &tv);
        if(err >0 && FD_ISSET(readfd, &readset)){
            FD_CLR(readfd, &readset);
            read(readfd, &data, sizeof(data));
            printf("\nReader %d", data);
        }
    }
}
