#pragma once
#include<iostream>
using namespace std;

#include "Time.h"

class Activity {

public:
    //构造函数
    Activity(){
    };

    Activity(int type, char name[], char timeword[], Time time, char place[], int setClock);
    

    //打印活动信息
    void print_activity_info();

    int getType();

    char* getName();

    Time* getTime();

    Time getTime1();

    char* getPlace();

    int getSetClock();

    char* getTimeword();

private:

    int type;        //0表示个人活动 1表示集体活动
    char name[10];    //活动名称
    Time time;       //活动时间
    char place[10];    //活动地点    
    int setClock;    //0不设定 1设定      
    char timeword[15];//文字描述的时间
};