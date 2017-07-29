#include "common.hh"

int main() 
{
  int product = 0;
  for (int a = 1; a < 1000; a++)
  {
    for (int b = a+1; b < 1000; b++)
    {
      const int c2 = a*a+b*b;
      const int c = std::sqrt(c2);
      if (c*c == c2) // integer math check
      {
	//	std::cout << a << " " << b << " " << c << std::endl;
	if (a+b+c==1000) {product = a*b*c; std::cout << a << " " <<b << " " <<  c << std::endl; break;}
      }
    }
  }
  std::cout << product << std::endl;
}
