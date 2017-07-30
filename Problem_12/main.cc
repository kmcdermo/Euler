#include "common.hh"

static const int N = 500;

void loopdiv(const long number, std::vector<long> & factors)
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
    if (dividend != 1) loopdiv(dividend,factors);
  }
  else factors.push_back(number);
}

long countdivisors(std::vector<long>& factors)
{
  int current = 0;
  int count = 0;
  int product = 1;
  for (auto factor : factors)
  {
    if (factor != current) 
    {
      product *= (count+1);
      current = factor;
      count = 0;
    }
    if (factor == current) count++;
  }
  product *= (count+1);
  return product;
}

int main() 
{
  long index = 0;
  long trinum = 0;
  int div = 0;
  while (div <= N)
  {
    index++;
    trinum += index;
    
    std::vector<long> factors;
    loopdiv(trinum,factors);
    div = countdivisors(factors);
  }

  std::cout << "index: " << index << " trinum: " << trinum << "  div: " << div << std::endl;
}
