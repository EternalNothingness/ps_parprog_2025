#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

// calculates maximal length (including zero termination) of a long converted to str
size_t ltostr_len(long n) {
    return  1 + ((n/10)!=0 ? ltostr_len(n/10) : 1);
}

// converts long to str
char* ltostr(long n) {
    char* str=malloc(ltostr_len(n) + (n<0 ? 1:0)); // do not forget the sign
    sprintf(str, "%ld", n);
    return str;
}
int main(int argc, char** argv) {
    if(argc<3) {
        fprintf(stderr, "Usage: ./execall PROC FILE ...\n");
        return EXIT_FAILURE;
    }
    
    char* end;
    long nproc=strtol(*(argv+1), &end, 10);
    if(!*(argv+1) || *end) { perror("strtol"); }

    for (long i = 1; i <=nproc; ++i) { // test all programs with 1 up to nproc cpu's
        char* nproc_str=ltostr(i);
        setenv("OMP_NUM_THREADS", nproc_str, 1);
        //printf("OMP_NUM_THREADS=%s\n", getenv("OMP_NUM_THREADS"));
        //fflush(stdout);
        free(nproc_str); // setenv creates a copy of the original string
        for(long j=2; j<argc; ++j) { // execute all programs
            pid_t pid=fork();
            if(pid<0) {
                perror("fork");
                return EXIT_FAILURE;
            } else if(pid==0) { // child process
                printf("OMP_NUM_THREADS: %s, executing: %s, ", getenv("OMP_NUM_THREADS"), *(argv+j));
                fflush(stdout);
                execl(*(argv+j),*(argv+j),NULL);
                perror("execl");
                return EXIT_FAILURE;
            } else { // parent process
                wait(NULL);
            }
        }
    }
}