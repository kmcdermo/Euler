#include "common.hh"

void builddict(std::map<int,TString>& dict);
void buildword(const int i, TString & number, const std::map<int,TString>& dict);

static const int N = 1000;

int main() 
{
  std::map<int,TString> dict;
  builddict(dict);

  int sum = 0;
  for (int i = 1; i <= N; i++)
  {
    TString number = "";
    buildword(i,number,dict);
    sum += number.Length();
  }

  std::cout << sum << std::endl;
}

void buildword(const int i, TString & number, const std::map<int,TString>& dict)
{
  const int ones = i % 10;
  const int tens = (i / 10) % 10;
  const int hundreds = (i / 100) % 10;
  const int thousands = (i / 1000) % 10;

  if (ones != 0 && tens != 1)
  {
    number += dict.at(ones);
  }
  if (tens != 0)
  {
    if (tens != 1)
    {
      number += dict.at(tens*10);
    }
    else
    {
      number += dict.at(ones+tens*10);
    }
  }
  if (hundreds != 0)
  {
    number += dict.at(hundreds);
    number += dict.at(100);
    if (ones != 0 || tens != 0)
    {
      number += "and";
    }
  }
  if (thousands != 0)
  {
    number += dict.at(thousands);
    number += dict.at(1000);
  }
}

void builddict(std::map<int,TString>& dict)
{
  dict[1] = "one";
  dict[2] = "two";
  dict[3] = "three";
  dict[4] = "four";
  dict[5] = "five";
  dict[6] = "six";
  dict[7] = "seven";
  dict[8] = "eight";
  dict[9] = "nine";
  dict[10] = "ten";
  dict[11] = "eleven";
  dict[12] = "twelve";
  dict[13] = "thirteen";
  dict[14] = "fourteen";
  dict[15] = "fifteen";
  dict[16] = "sixteen";
  dict[17] = "seventeen";
  dict[18] = "eighteen";
  dict[19] = "nineteen";
  dict[20] = "twenty";
  dict[30] = "thirty";
  dict[40] = "forty";
  dict[50] = "fifty";
  dict[60] = "sixty";
  dict[70] = "seventy";
  dict[80] = "eighty";
  dict[90] = "nintey";
  dict[100] = "hundred";
  dict[1000] = "thousand";
}
