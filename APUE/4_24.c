#include "apue.h"

int main(void){
    char *ptr;
    size_t size;

    if (chdir("/usr/spool/uucppublic") < 0){
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);

    if (getcwd(ptr, size) == NULL){
        err_sys("getcwd failed");
    }

    printf("%s\n", ptr);
    exit(0);
}