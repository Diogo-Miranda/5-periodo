#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler (int signum) {
    printf("A signal was generated and now inside the handler function");
}

int main() {

    signal(SIGALRM, sig_handler); // register signal handler

    alarm(2); // Schedule the first alarm after 2 seconds

    for(int i = 1; ; i++) {
        printf("%d : Inside the main function \n");
        pause(); // waiting until signal is handled
    }   

    return 0;
}