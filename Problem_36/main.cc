#include "common.hh"

static const int N = 1000000;

void getBinBases(std::vector<int> & binbases)
{
  int n = 0;
  int tmp = 1;
  while (tmp < N)
  {
    binbases.push_back(tmp);
    tmp *= 2;
  }
}

void removeLeadingZeros(TString & b)
{
  int pos = 0;
  for (int i = 0; i < b.Length(); i++)
  {
    if (TString(b[i]).Atoi() != 0) {pos = i; break;} 
  }

  if (pos != 0) b.Remove(0,pos);
}

TString Dec2Bin(const std::vector<int> & binbases, int d)
{
  TString b = "";
  for (int i = 0; i < binbases.size(); i++)
  {
    if (d - binbases[i] < 0) b.Append("0");
    else 
    {
      b.Append("1");
      d -= binbases[i];
    }
  }

  removeLeadingZeros(b);

  return b;
}

bool checkPalindrome(const TString & number)
{
  const int length = number.Length();

  bool isPalindrome = true;
  for (int i = 0; i < length/2; i++)
  {
    int j = length-1-i;
    if (number[i]!=number[j]) {isPalindrome = false; break;}
  }
  return isPalindrome;
}

int main() 
{
  std::vector<int> binbases;
  getBinBases(binbases);
  std::reverse(binbases.begin(),binbases.end());

  int sum = 0;
  for (int i = 1; i <= N; i++)
  {
    const TString bin = Dec2Bin(binbases,i);
    const TString dec = Form("%i",i);

    if (checkPalindrome(bin) && checkPalindrome(dec)) sum += i;
  }

  std::cout << sum << std::endl;
}
