#define _GNU_SOURCE
#include <sys/syscall.h>
#include <bits/types/clockid_t.h>
#include <bits/time.h>
#include <stdio.h>
#include <unistd.h>

// clock_adjtime tune kernel clock
int clock_adjtime(clockid_t clk_id, struct timex *buf){
    return syscall(SYS_clock_adjtime, clk_id, buf);
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
    if (clock_adjtime(CLOCK_REALTIME, &buf) < 0){
        perror("clock_adjtime");
    }
    return 0;
}