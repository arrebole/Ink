#define _GNU_SOURCE
#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

struct linux_dirent {
    unsigned long d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[];
};

// getdents get directory entries
int getdents(unsigned int fd, struct linux_dirent *dirp, unsigned int count) {
    return syscall(SYS_getdents, fd, dirp, count);
}

int main(int argc, char const *argv[]) {
    int dirfd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
    if (dirfd < 0) {
        perror("open");
        return -1;
    }

    // nread 是目录的数量 dirbuf 储存连续的目录结构体类似于数组，但是结构体的内存长度不统计一(文件夹名长度)需要通过偏移量查询。
    char dirbuf[1024];
    int nread = getdents(dirfd, (struct linux_dirent *) dirbuf, 1024);
    if (nread < 0) {
        perror("getdents");
        return -1;
    }

    printf("--- inode --- d_reclen --- d_name ---\n");
    for (int i = 0; i < nread; ) {
        struct linux_dirent *dirp = (struct linux_dirent *) (dirbuf + i);
        printf("%8ld    %4d    %s\n", dirp->d_ino, dirp->d_reclen, dirp->d_name);
        // 下一个目录结构体的偏移量
        i += dirp->d_reclen;
    }

    return 0;
}