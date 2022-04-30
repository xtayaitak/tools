#include "systemtool.h"
#include <time.h>
namespace tools{
    uint64_t GetTickCount()
    {
        struct timespec ts = {0};
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    }
}