#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void exampleUmask() {
    // 屏蔽新创建的文件，掩码777
    mode_t mode = umask(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    // 新创建的文件，inode权限位被被屏蔽为 000
    int fd =  creat("./example", O_RDWR);
}