#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int leap(int year)
{
    if ((year % 400) == 0)
        return 1;
    else if ((year % 100) == 0)
        return 0;
    else if ((year % 4) == 0)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv)
{
    int i, count;
    int year, mon, day, wday;
    int friday = 0, total = 0;
    struct tm *tm;
    time_t t = time(NULL);
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (argc != 2) {
        printf("Usage: %s count\n", argv[0]);
        exit(1);
    }

    count = atoi(argv[1]);
    tm = localtime(&t);
    year = tm->tm_year + 1900;
    mon = tm->tm_mon;
    day = tm->tm_mday;
    wday = tm->tm_wday;

    printf("Today: %d/%d/%d - %d, count: %d\n", year, mon+1, day, wday, count);

    for (i = 0; i < count; ++i) {
//        printf("Today: %d/%d/%d - %d, count: %d\n", year, mon+1, day, wday, count);
        if (day == 13 && wday == 5) {
            printf("13th Friday: %d/%02d/%02d, %d\n", year, mon+1, day, wday);
            ++friday;
        }
        ++day,++wday;
        if (wday == 8)
            wday = 1;
        if (mon == 11 && day == 32) {
            ++year;
            mon = 0;
            day = 1;
            days[1] = (leap(year) == 1 ? 29 : 28);
        }
        if (day > days[mon]) {
            day = 1;
            ++mon;
        }
        ++total;
    }


    printf("Yes: %d, No: %d, Ratio: %f%%\n", friday, (total - friday), (double)(friday/1.0/total*100.0));
    return 0;
}

