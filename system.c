
#include <sys/wait.h>

#include "system.h"
#include "spawn.h"

int systemvpe (char* const argv[], char* const envp[])
{
    int ret;
    waitpid(spawnvpe(argv, envp), &ret);
    return ret;
}
