#include <iostream>
#include "filetool.h"
#include <filesystem>

int main()
{
    timespec t = {0};
    clock_gettime(CLOCK_MONOTONIC, &t);
    std::cout << t.tv_nsec <<  std::endl;

    return 0;
}