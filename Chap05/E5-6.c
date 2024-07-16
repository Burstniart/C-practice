#include <stdio.h>

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main(int argc,char **argv) {

  int pmonth, pday;
  month_day(2024,197, &pmonth, &pday);
  printf("day of year today is %d\n", day_of_year(2024,07,15));
  printf("month day today is %d - %d\n", pmonth, pday);
  
  return 0;
}

int day_of_year(int year, int month, int day) /*set day of year from month & day */
{
  int i, leap;
  int *pointday = &day_tab[0][0];
  
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (leap)  pointday += 13;

  for (i = 1, pointday += 1; i < month; i++)
    day += *(pointday++);
  return (day);
}

void month_day(int year, int yearday, int *pmonth, int *pday) /*set month, day, day of year */
{
  int i, leap;
  int *pointday = &day_tab[0][0];
  
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (leap)  pointday += 13;

  for (i = 1; yearday > *(pointday++); i++)
    yearday -= *(pointday);
  *pmonth = i;
  *pday = yearday;
}
