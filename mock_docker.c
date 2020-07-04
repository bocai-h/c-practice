#define _GNU_SOURCE 
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)

static char container_stack[STACK_SIZE];
char * const container_args[] = {
    "/bin/bash",
    NULL
};

int container_main(void* args){
    printf("Container - inside the container!\n");
    execv(container_args[0], container_args);
    printf("Somethings wrong!\n");
    return 1;
}

int main(){
    printf("Parent - start a container!\n");
    int container_id = clone(container_main, container_stack + STACK_SIZE, CLONE_NEWNS | SIGCHID, NULL);
    wait_pid(container_id, NULL, 0);
    printf("Parent - container stop!\n");
    return 0;
}

