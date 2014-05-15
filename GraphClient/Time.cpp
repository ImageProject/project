#include "Time.h"
/*
 Преобразование структуры времени в строку
 Интерпритирует содержание структуры как календарного времени
 И преобразует в строку для дальнейшего просмотра
 
 */

char* asctime(const struct tm *timeptr)
{
    static const char wday_name[][4] = { // дни недели
		"Sun", "Mon", "Tue",
		"Wed", "Thu", "Fri",
		"Sat"
	};
	static const char mon_name[][4] = { // месяца года
		"Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
	};
    static char result[26]; //подсчет результата
    sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
            wday_name[timeptr->tm_wday],
            mon_name[timeptr->tm_mon],
            timeptr->tm_mday, timeptr->tm_hour,
            timeptr->tm_min, timeptr->tm_sec,
            1900 + timeptr->tm_year);
    return result;
}
