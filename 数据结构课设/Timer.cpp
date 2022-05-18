#include "Timer.h"
int Timer::curWeek = 0;
int Timer::curDay = 0;
int Timer::curTime = 0;
int Timer::isWorking = 0;
int Timer::interval = 10000;    //以计算机的10s作为模拟系统的1h