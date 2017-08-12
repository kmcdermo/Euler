#include "common.hh"

typedef std::vector<std::pair<long,int> > vpli;
static const long N = 10000;

void getPrimeFactors(const long number, std::vector<long> & factors)
{
  long factor = 0;
  for (long i = 2; i < number; i++)
  {
    if (number%i==0) {factor = i; break;}
  }
  
  if (factor != 0)
  {
    const long dividend = number/factor;
    factors.push_back(factor);
    if (dividend != 1) getPrimeFactors(dividend,factors);
  }
  else factors.push_back(number);
}

void getPrimeFactors(const long number, vpli & factormap)
{
  std::vector<long> factors;
  getPrimeFactors(number,factors);
   
  long current = 0; int count = 0;
  for (auto factor : factors) 
  {
    if (factor == current) count++;
    else 
    {
      if (current != -1)
      {
	factormap.push_back(std::make_pair(current,count));
      }
      current = factor;
      count = 1;
    }
  }
  factormap.push_back(std::make_pair(current,count));
}

long power(const long base, const long expo)
{
  long x = 1;
  for (long i = 0; i < expo; i++)
  {
    x *= base;
  }
  return x;
}

void getDivisorsFromPrimeFactors(const vpli & factormap, std::vector<long> & divisors, long n, long i)
{
  for (long j = i; j < factormap.size(); j++) 
  {
    for (long k = 1; k <= factormap[j].second; k++) 
    {
      long x = n * power(factormap[j].first,k);
      divisors.push_back(x);
      getDivisorsFromPrimeFactors(factormap,divisors,x,j+1);
    }
  }
}

long sumDivisors(const std::vector<long> & divisors)
{
  long sum = 0;
  for (auto divisor : divisors) sum += divisor;
  return sum;
}

long sumAmicableNumbers(const std::map<long,long> & summap)
{
  long grandsum = 0;

  for (auto&& pair : summap)
  { 
    const long inum = pair.first;
    const long isum = pair.second;

    if (summap.count(isum) && isum != inum)
    {
      if (summap.at(isum) == inum) {grandsum += inum;}
    }
  }

  return grandsum;
}

int main() 
{
  std::map<long,long> summap;
  for (long i = 1; i <= N; i++)
  {
    vpli factormap;
    getPrimeFactors(i,factormap);

    std::vector<long> divisors;
    getDivisorsFromPrimeFactors(factormap,divisors,1,0);
    divisors.push_back(1);
    
    std::sort(divisors.begin(),divisors.end());
    divisors.erase(divisors.end()-1); // remove last element as we want proper divisors

    const long sum = sumDivisors(divisors);
    summap[i] = sum;
  }

  const long grandsum = sumAmicableNumbers(summap);

  std::cout << grandsum << std::endl;
}
