#include <stdio.h>

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int , int , int );
void month_day(int , int , int *, int *);

int main(int argc, int *argv[]){

  int year, yearday, m, d;
  year = 2024;
  yearday = 61;

  month_day(year, yearday, &m, &d);

  printf("%d - %d\n",m,d);
  
  return 0;
}


int day_of_year(int year, int month, int day)  /*set day of year from month & day */
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += day_tab[leap][i];
  return (day);
}

void month_day(int year, int yearday, int *pmonth, int *pday) /* set month, day */
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  printf("%d\n",leap);
  for (i = 1; yearday > day_tab[leap][i]; i++)
    yearday -= day_tab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
