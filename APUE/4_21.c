#include "apue.h"
#include <fcntl.h>

int main(int argc, char* argv[]){
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++){
        if (stat(argv[1], &statbuf) < 0){
            err_ret("%s : stat error", argv[1]);
            continue;
        }

        if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0){
            err_ret("%s : open error", argv[1]);
            continue;
        }

        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;

        if (funtime(fd, times) < 0){
            err_ret("%s : funtime error", argv[1]);
        }

        exit(0);
    }
}