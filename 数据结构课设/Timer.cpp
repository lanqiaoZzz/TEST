#include "Timer.h"
#include "TimeTable.h"
int Timer::curWeek = 1;
int Timer::curDay = 1;
int Timer::curTime = 0;
int Timer::isWorking = 0;
int Timer::interval = 10000;    //以计算机的10s作为模拟系统的1h

void Timer::start(TimeTable* table) {

    if (isWorking) return;

    isWorking = 1;

    thread th(forward, table);
    th.detach();
}

void Timer::stop() {

    if (!isWorking) return;

    isWorking = 0;
}

void Timer::forward(TimeTable* table) {

    while (isWorking) {

        this_thread::sleep_for(chrono::milliseconds(interval));
        curTime++;

        if (curTime == 24) {

            curTime = 0;
            curDay++;

            if (curDay == 8) {

                curDay = 0;
                curWeek++;

                if (curWeek == 20) {

                    stop();
                }
            }
        }

        remind_course(table);
    }    
}

void Timer::remind_course(TimeTable* table)
{   
    if (curTime == 21)
    {   
        int pweek, pday;

        if (curDay == 7)
        {
            pweek = curWeek + 1;
            pday = 1;
        }
        else
        {
            pweek = curWeek;
            pday = curDay;
        }

        //将课表中的课程按时间排序
        table->sortByCourseTime();

        cout << "***即将提醒明天要上的课***" << endl;
        cout << "------------------------------------------" << endl;  

        cout << "课程名称\t上课时间\t\t上课地点\t纸质资料\t\t当前进度\t课程群\t\t考试地点 \t考试时间" << endl;
        char courseInfo[150];

        Course* myCourse = table->getmycourse();
        int flag = 0;
        for (int i = 0; i < table->getCoursenum(); i++)
        {   
            Time t = myCourse[i].get_course_time();

            if (t.is_on_this_day(pweek, pday))
            {
                courseInfo[0] = 0;
                myCourse[i].get_info(courseInfo);
                cout << courseInfo << endl;

                flag = 1;
            }
  
        }

        if (!flag)
        {
            cout << "明天没有要上的课" << endl;
        }

        cout << "------------------------------------------" << endl;
        cout << "***提醒结束***" << endl;
    }
}
