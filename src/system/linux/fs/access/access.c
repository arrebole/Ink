#include <unistd.h>

void sampleAccess(const char* pathname) {

    if (access(pathname, R_OK) < 0) {
        write(STDERR_FILENO, "read access fail\n", 18);
    }

    if (access(pathname, W_OK) < 0) {
        write(STDERR_FILENO, "write access fail\n", 19);
    }

    if (access(pathname, X_OK) < 0) {
        write(STDERR_FILENO, "exec access fail\n", 18);
    }
}