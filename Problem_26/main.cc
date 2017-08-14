#include "common.hh"

static const int N = 1000;

int checkRepeat(const TString & decimal, bool& isRepeat)
{
  //  std::cout << "START: " << decimal.Data() << std::endl;

  int length = 0;
  for (int i = 0; i < decimal.Length(); i++)
  {
    if (i > 1) break;
    for (int j = 1; j <= (decimal.Length()-i)/2 ; j++)
    {
      TString lhs(decimal(i,j));
      TString rhs(decimal(i+j,j));

      //  std::cout << "i: " << i << " j: " << j << " lhs: " << lhs.Data() << " rhs: " << rhs.Data() << std::endl; 

      if (lhs == rhs) {isRepeat = true; length = j; break;}
    }
    if (isRepeat) break;
  }


  return length;
}

int getRecurringCycle(const int dividend)
{
  bool isOver = false;
  int divisor = 1;
  TString decimal = "";
  int length = decimal.Length();
  while (!isOver)
  {
    const int quotient = divisor / dividend;
    //    std::cout << divisor << " / " << dividend << " = " << quotient << std::endl;
    if (quotient == 0)
    {
      divisor *= 10;
      if (decimal.Length() != 0) decimal.Append(Form("%i",0));
      length = checkRepeat(remainders,divisor,isOver);
    }
    else
    {
      const int remainder = divisor % dividend;
      //std::cout << divisor << " % " << dividend << " = " << remainder << std::endl;
      if (remainder == 0)
      {
	isOver = true;
      }
      else
      {
	divisor = remainder * 10;
	decimal.Append(Form("%i",quotient));
	length = checkRepeat(decimal,isOver);
      }
    }
    //    std::cout << decimal.Data() << std::endl << std::endl;
  }

  //  std::cout << dividend << " " << decimal.Data() << std::endl;
  return length;
}

int main() 
{
  int d = 0, length = 0;
  for (int i = 2; i < N; i++)
  {
    //    std::cout << "I: "<< i << std::endl;
    int tmp = getRecurringCycle(i);
    //    std::cout << "length for " << i << " : " << tmp << std::endl << std::endl; 
    if (tmp > length) {length = tmp; d = i;}
  }
  std::cout << d << std::endl;
}
