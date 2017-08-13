#include "common.hh"

static const long N = 2309171; // 9! * 7, at which point the numbers will always be bigger than sum of factorial digits

long factorial(const long n)
{
  long factorial = 1;
  for (long i = 1; i <= n; i++)
  {
    factorial *= i;
  }
  return factorial;
}

void getFactorialMap(std::map<long,long> & fMap)
{
  fMap[0] = 1;
  for (long i = 1; i < 10; i++)
  {
    fMap[i] = factorial(i);
  }
}

int main() 
{
  std::map<long,long> fMap;
  getFactorialMap(fMap);
  
  long grandsum = 0;
  for (long i = 3; i < N; i++)
  {
    TString t = Form("%li",i);
    long sum = 0;
    for (int j = 0; j < t.Length(); j++)
    {
      sum += fMap[TString(t[j]).Atoll()];
    }
    if (sum == i) grandsum += i;
  }

  std::cout << grandsum << std::endl;
}
