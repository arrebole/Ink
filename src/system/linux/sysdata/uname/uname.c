#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

# define _UTSNAME_SYSNAME_LENGTH 65
# define _UTSNAME_NODENAME_LENGTH 65
# define _UTSNAME_RELEASE_LENGTH 65
# define _UTSNAME_RELEASE_LENGTH 65
# define _UTSNAME_MACHINE_LENGTH 65
# define _UTSNAME_DOMAIN_LENGTH 65

struct utsname {
  char sysname[_UTSNAME_SYSNAME_LENGTH];
  char nodename[_UTSNAME_NODENAME_LENGTH];
  char release[_UTSNAME_RELEASE_LENGTH];
  char version[_UTSNAME_RELEASE_LENGTH];
  char machine[_UTSNAME_MACHINE_LENGTH];
  char domainname[_UTSNAME_DOMAIN_LENGTH];
};

int uname(struct utsname *buf) { 
    return syscall(SYS_uname, buf); 
}

int main(int argc, const char *argv[]) {

    struct utsname result;
    if (uname(&result) < 0) {
        perror("uname");
        return 0;
    }

    printf("sysname: %s\n", result.sysname);
    printf("nodename: %s\n", result.nodename);
    printf("release: %s\n", result.release);
    printf("version: %s\n", result.version);
    printf("machine: %s\n", result.machine);
    printf("domainname: %s\n", result.domainname);

    return 0;
}