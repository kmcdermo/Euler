#include "common.hh"

static const int N = 100;

void factorial(TString & input, int n)
{
  TString output = "";
  int carry = 0;
  for (int i = input.Length()-1; i > -1; i--)
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
  input = output;

  n--;
  if (n > 1) factorial(input, n);
}

int main() 
{
  TString result = "1";

  factorial(result,N);

  long sum = 0;
  for (int i = 0; i < result.Length(); i++)
  {
    sum += TString(result[i]).Atoll();
  }
  std::cout << result.Data() << std::endl;
  std::cout << "Sum: " << sum << std::endl;
}
