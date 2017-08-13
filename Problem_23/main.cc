#include "common.hh"

const static long N = 28123;

template <typename T>
void getDivisorSums(std::map<T,T> & divsum)
{
  for (T i = 1; i <= N; i++)
  {
    vp<T> factormap;
    getPrimeFactors(i,factormap);
    
    std::vector<T> divisors;
    getDivisorsFromPrimeFactors(factormap,divisors,T(1),T(0));
    pruneDivisors(divisors);

    divsum[i] = sumDivisors(divisors);
  }
}

int main() 
{
  std::map<long,long> divsum;
  getDivisorSums(divsum);
 
  std::vector<long> abundants;
  for (auto&& pair : divsum)
  {
    if (pair.first < pair.second) abundants.push_back(pair.first);
  }
  const long length = abundants.size();
    
  long sum = 0;
  for (long i = 1; i <= N; i++)
  {
    bool isGood = false;
    for (long j = 0; j < length; j++)
    {
      if (abundants[j] > i) break;
      for (long k = 0; k < length; k++)
      {
	if (abundants[j] + abundants[k] == i) {isGood = true; break;}
      }
      if (isGood) break;
    }
    if (!isGood) sum += i;
  }
  std::cout << sum << std::endl;
}
