#define _GNU_SOURCE
#include <sys/syscall.h>
#include <bits/timex.h>
#include <unistd.h>
#include <unistdio.h>

// adjtimex tune kernel clock
int adjtimex(struct timex *buf){
    return syscall(SYS_adjtimex, buf);
}

int main(){
    struct timex buf = {
        // int  modes;    
        // long offset;   
        // long freq;     
        // long maxerror; 
        // long esterror; 
        // int  status;   
        // long constant; 
        // long precision;  
        // long tolerance;
        // struct timeval time;
        // long tick;
        // long ppsfreq;
        // long jitter;
        // int  shift;
        // long stabil;
        // long jitcnt;
        // long calcnt;
        // long errcnt;
        // long stbcnt;
        // int tai;
    };
    if (adjtimex(&buf) < 0){
        perror("adjtimex");
    }
    return 0;
}