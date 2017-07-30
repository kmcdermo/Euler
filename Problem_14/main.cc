#include "common.hh"

typedef std::map<long,std::pair<long,long> > tmap;

static const long N = 1e6;

void summaps(tmap& tallymap, long highnum, long& sum)
{
  if (highnum != 1) 
  {
    sum += tallymap[highnum].first;
    highnum = tallymap[highnum].second;
    summaps(tallymap,highnum,sum);
  }
}

int main() 
{
  long highest = 0;
  long starting = 0;

  tmap tallymap;
  tallymap[2] = std::make_pair(1,1);

  for (long i = 3; i < N; i++)
  {
    long num = i;
    long tally = 0;

    long highnum = 0;
    long hightally = 0;
    while (num != 1)
    {
      // check num in map
      if (tallymap.count(num) == 1) {break;}

      tally++;
      hightally++;

      if (num%2==0) num /= 2;
      else num = 3*num + 1;

      // shortcut?
      if (num >= highnum) {highnum = num; hightally = 0;}
    }
    if (tallymap.count(highnum) == 0) tallymap[highnum] = std::make_pair(hightally,num);

    tally -= hightally;
    summaps(tallymap,highnum,tally);

    if (tally > highest) {highest = tally; starting = i;}

    //    std::cout << i << " " << tally << std::endl;
  }

  std::cout << std::endl;
  std::cout << starting << " " << highest << std::endl;
}
