#include "Activity.h"
#include<string.h>

Activity::Activity(int type, char name[], char timeword[], Time time, char place[], int setClock) {

    this->type = type;
    strcpy(this->name, name);
    strcpy(this->timeword, timeword);
    this->time = time;
    strcpy(this->place, place);
    this->setClock = setClock;
}


int Activity::getType() {

    return type;
}

char* Activity::getName() {

    return name;
}

Time* Activity::getTime() {

    return &time;
}

Time Activity::getTime1() {

    return time;
}

char* Activity::getPlace() {

    return place;
}

int Activity::getSetClock() {

    return setClock;
}

char* Activity::getTimeword() {

    return timeword;
}