#include "common.hh"

static const int N = 1000;

int checkRepeat(const std::vector<int>& remainders, const int remainder)
{
  int length = 0;
  for (int i = 0; i < remainders.size(); i++)
  {
    if (remainder == remainders[i])
    {
      length = remainders.size()-i;
      break;
    }
  }

  return length;
}

int getRecurringCycle(const int dividend)
{
  bool isOver = false;
  int divisor = 1;
  std::vector<int> remainders; 
  int length = 0;
  while (!isOver)
  {
    const int quotient = divisor / dividend;
    const int remainder = divisor % dividend;
    if (quotient == 0)
    {
      length = checkRepeat(remainders,remainder);
      if (length > 0) isOver = true;
      if (!isOver)
      {
	remainders.push_back(remainder);
	divisor *= 10;
      }
    }
    else
    {
      if (remainder == 0)
      {
	isOver = true;
      }
      else
      {
	length = checkRepeat(remainders,remainder);
	if (length > 0) isOver = true;
	if (!isOver)
	{
	  remainders.push_back(remainder);
	  divisor = remainder * 10;
	}
      }
    }
  }
  return length;
}

int main() 
{
  int d = 0, length = 0;
  for (int i = 2; i < N; i++)
  {
    int tmp = getRecurringCycle(i);
    if (tmp > length) {length = tmp; d = i;}
  }
  std::cout << d << std::endl;
}
