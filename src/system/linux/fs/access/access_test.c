#include <assert.h>

extern void sampleAccess(const char* pathname);

int main(int argc, char* argv[]) {
    assert(argc == 2);
    sampleAccess(argv[1]);
    return 0;
}