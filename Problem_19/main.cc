#include "common.hh"

static const int endyear = 2000;

void makeCalendar(std::map<int,int> & calendar)
{
  calendar[1]  = 31; //January
  calendar[2]  = 28; //February
  calendar[3]  = 31; //March
  calendar[4]  = 30; //April
  calendar[5]  = 31; //May
  calendar[6]  = 30; //June
  calendar[7]  = 31; //July
  calendar[8]  = 31; //August
  calendar[9]  = 30; //September
  calendar[10] = 31; //October
  calendar[11] = 30; //November
  calendar[12] = 31; //December
}

bool getLeapYear(const int year)
{
  bool isLeapYear = false;
  if (year % 4 == 0)
  {
    if (year % 100 != 0)
    {
      isLeapYear = true;
    }
    else 
    {
      if (year % 400 == 0)
      {
	isLeapYear = true;
      }
    }
  }
  return isLeapYear;
}

int main() 
{
  std::map<int,int> calendar;
  makeCalendar(calendar);

  int day = 1;
  int nsundays = 0;
  for (int year = 1900; year <= endyear; year++)
  {
    const bool isLeapYear = getLeapYear(year);
    if (isLeapYear) calendar[2]++;

    for (int month = 1; month <= 12; month++)
    {
      if (day % 7 == 0) nsundays++;
      day += calendar[month];
    }

    if (isLeapYear) calendar[2]--;
  }

  std::cout << nsundays-2 << std::endl;
}
