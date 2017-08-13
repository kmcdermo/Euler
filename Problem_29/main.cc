#include "common.hh"

static const int a = 2;
static const int b = 100;

inline bool sortByLengthAndNumber(const TString & i, const TString & j)
{
  if (i.Length() == j.Length()) return i < j;
  else return i.Length() < j.Length();
}

TString Multiply(const TString & input, const int n)
{
  TString output = "";
  int carry  = 0;
  for (int i = input.Length()-1; i >= 0; i--)
  {
    int tmp = TString(input[i]).Atoi();
    tmp *= n; 
    if (carry != 0) tmp += carry;
    if (i != 0)
    {
      carry = 0;
      while (tmp >= 10)
      {
	tmp -= 10;
	carry++;
      }
    }
    output.Prepend(Form("%i",tmp));
  }
  return output;
}

TString power(const int base, const int expo)
{
  TString power = "1";
  for (int i = 1; i <= expo; i++)
  {
    power = Multiply(power,base);
  }
  return power;
}

int main() 
{
  std::vector<TString> all;
  for (int i = a; i <= b; i++)
  {
    for (int j = a; j <= b; j++)
    {
      all.push_back(power(i,j));
    }
  }
  std::sort(all.begin(),all.end(),sortByLengthAndNumber);

  std::vector<TString> seq;
  seq.push_back(all[0]);
  for (int i = 1; i < all.size(); i++)
  {
    if (all[i] != all[i-1]) seq.push_back(all[i]);
  }
  
  std::cout << seq.size() << std::endl;
}
