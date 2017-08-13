#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <utility>

#include "TMath.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"

template <typename T>
using vp = std::vector<std::pair<T,T> >;

template <typename T>
void getPrimeFactors(const T number, std::vector<T> & factors)
{
  T factor = 0;
  for (T i = 2; i < number; i++)
  {
    if (number%i==0) {factor = i; break;}
  }
  
  if (factor != 0)
  {
    const T dividend = number/factor;
    factors.push_back(factor);
    if (dividend != 1) getPrimeFactors(dividend,factors);
  }
  else factors.push_back(number);
}

template <typename T>
void getPrimeFactors(const T number, vp<T> & factormap)
{
  std::vector<T> factors;
  getPrimeFactors(number,factors);
   
  T current = 0; T count = 0;
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

template <typename T>
T power(const T base, const T expo)
{
  T x = 1;
  for (T i = 0; i < expo; i++)
  {
    x *= base;
  }
  return x;
}

template <typename T>
void getDivisorsFromPrimeFactors(const vp<T> & factormap, std::vector<T> & divisors, T n, T i)
{
  for (T j = i; j < factormap.size(); j++) 
  {
    for (T k = 1; k <= factormap[j].second; k++) 
    {
      T x = n * power(factormap[j].first,k);
      divisors.push_back(x);
      getDivisorsFromPrimeFactors(factormap,divisors,x,j+1);
    }
  }
}

template <typename T>
void pruneDivisors(std::vector<T> & divisors)
{
  divisors.push_back(1);
  std::sort(divisors.begin(),divisors.end());
  divisors.erase(divisors.end()-1); // remove last element as we want proper divisors
}

template <typename T>
T sumDivisors(const std::vector<T> & divisors)
{
  T sum = 0;
  for (auto divisor : divisors) sum += divisor;
  return sum;
}
