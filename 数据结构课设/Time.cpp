#include"Time.h"
Time::Time() {
	for (int i = 0; i <= 19; i++) {
		this->week[i] = 0;
	}
	for (int i = 0; i <= 7; i++) {
		this->day[i] = 0;
	}
	this->startTime = startTime;
	this->endTime = endTime;
}

Time::Time(int *week, int *day, int startTime, int endTime) {
	for (int i = 1; i <= 18; i++) {
		this->week[i] = week[i];
	}
	for (int i = 1; i <= 7; i++) {
		this->day[i] = day[i];
	}
	this->startTime = startTime;
	this->endTime = endTime;
}

void Time::SetTime(int a, int b, int c, int d, int e, int mod) {
	//五个数字，分别表示 a-b周[周c d-e节]

	//mod=0表示课程时间
	//mod=1表示考试时间
	for (int i = a; i <= b; i++) {
		this->week[i] = 1;
	}

	this->day[c] = 1;

	if (mod == 0) {
		this->startTime = d + 7;
		this->endTime = e + 7;

		if (d > 5) {
			this->startTime++;
			this->endTime++;
		}
	}
	else
	{
		this->startTime = d;
		this->endTime = e;
	}
}

int Time::conflict_detection(Time time) {
	for (int i = 1; i <= 16; i++)
	{
		if (this->week[i] == 1 && time.week[i] == 1)
		{
			for (int j = 1; j <= 7; j++)
			{
				if (this->day[j] == 1 && time.day[j] == 1) {
					for (float h = 0.5; h <= 24; h++)
					{
						if ((h >= this->startTime&&h <= this->endTime) && (h >= time.startTime&&h <= time.endTime)) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int Time::is_clear(Time time) {
	for (int i = 0; i < 20; i++)
	{
		if (this->week[i] == 1 && time.week[i] == 1) {
			for (int j = 1; j <= 7; j++)
			{
				if (this->day[j] == 1 && time.day[j] == 1)
				{
					for (int h = 1; h < 24; h = h++)
					{
						if (this->startTime == h)
							return 1;
						if (time.startTime == h) {
							return 0;
						}
					}
				}
				else {
					if (this->day[j] == 1 && time.day[j] != 1)
						return 1;
					if (this->day[j] != 1 && time.day[j] == 1)
						return 0;
				}
			}
		}
		else
		{
			if (this->week[i] == 1 && time.week[i] != 1)
				return 1;
			if (this->week[i] != 1 && time.week[i] == 1)
				return 0;
		}
	}
}

int Time::compareTo(Time time) {
	for (int j = 1; j <= 7; j++)
	{
		if (this->day[j] == 1 && time.day[j] == 1)
		{
			for (int h = 1; h < 24; h = h ++)
			{
				if(this->startTime==h)
					return 1;
				if (time.startTime == h) {
					return 0;
				}
			}
		}
		else {
			if (this->day[j] == 1 && time.day[j] != 1)
				return 1;
			if (this->day[j] != 1 && time.day[j] == 1)
				return 0;
		}
	}
}

int Time::is_on_this_day(int pweek, int pday)
{
	if (this->week[pweek] && this->day[pday])
		return 1;
	else return 0;
}
