#include "common.hh"

bool checkPalindrom(const int product);

int main() 
{
  int palindrom = 0;
  int k = 99;
  for (int i = 999; i > 99; i--)
  {
    for (int j = i; j > k; j--)
    {
      const int product = i*j;
      const bool isPalindrom = checkPalindrom(product);
      
      if (isPalindrom)
      {
	if (product > palindrom) palindrom = product;
	if (j>k) k = j;
      }
    }
  }

  std::cout << palindrom << std::endl;
}

bool checkPalindrom(const int product)
{
  TString tproduct = Form("%i",product);
  const int length = tproduct.Length();

  bool isPalindrom = true;
  for (int i = 0; i < length/2; i++)
  {
    int j = length-1-i;
    if (tproduct[i]!=tproduct[j]) {isPalindrom=false; break;}
  }
  return isPalindrom;
}
