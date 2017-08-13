#include "common.hh"

static const int N = 1000000;

void makeSieve(std::vector<bool> & primes)
{
  primes[0] = primes[1] = false;
  const int sqrtN = std::sqrt(N);
  for (int p = 2; p <= sqrtN; p++)
  {
    if (primes[p])
    {
      for (int i = p*p; i <= N; i += p)
      {
	primes[i] = false;
      }
    }
  }
}

bool isCircular(const int prime, const std::vector<bool>& primes)
{
  bool isCircular = true;

  const TString tprime = Form("%i",prime);
  const int length = tprime.Length();

  std::vector<TString> cprimes(length,tprime);
  for (int i = 1; i < length; i++) // don't circularize the first one!
  {
    const int tmp = TString(cprimes[i-1][0]).Atoi();
    cprimes[i].Remove(0,1);
    cprimes[i].Append(Form("%i",tmp));
    if (!primes[cprimes[i].Atoi()]) {isCircular = false; break;}
    if (i < length-1) cprimes[i+1] = cprimes[i];
  }
  return isCircular;
}

int main() 
{
  std::vector<bool> primes(N, true);
  makeSieve(primes);

  int n = 0;
  for (int i = 0; i < primes.size(); i++)
  {
    if (primes[i]) 
    {
      if (isCircular(i,primes)) {n++;}
    }
  }
  std::cout << n << std::endl;
}
