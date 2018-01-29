#include "apue.h"

void make_tmp(char *template);

int main(void){
    char good_template[] = "/tmp/dirXXXXXX";
    char *bad_template = "/tmp/dirXXXXXX";

    printf("trying to create first temp file...\n");
    make_tmp(good_template);
    printf("trying to create second temp file...\n");
    make_tmp(bad_template);

    exit(0);
}

void make_tmp(char *template){
    int fd;
    struct stat statbuf;

    if ((fd = mkstemp(template)) < 0){
        err_sys("mkstemp error");
    }
    printf("temp name = %s\n", template);
    close(fd);

    if (stat(template, &statbuf) < 0){
        if (errno == ENOENT){
            printf("file doesn't exist\n");
        }
        else{
            err_sys("stat error");
        }
    }
    else{
        printf("file exist\n");
        unlink(template);
    }
}