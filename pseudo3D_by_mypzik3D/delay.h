// стыр.. позаимствовал у nakidai
#pragma once
#include <time.h>

static long long int getMS()
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void sleepMS(int fps)
{
    long long int end = getMS() + (1000/fps);
    while (getMS() < end);
}
