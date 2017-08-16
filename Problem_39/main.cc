#include "common.hh"

static const int N = 1000;                                                      
                                                                                
int main()                                                                      
{                                                                               
  int n = 0;                                                                    
  int i = 0;                                                                    
  for (int p = 1; p <= N; p++)                                                  
  {                                                                             
    int tmp = 0;                                                                
    for (int a = 1; a <= p; a++)                                                
    {                                                                           
      for (int b = a+1; b <= p-a; b++)                                          
      {                                                                         
	const int c2 = a*a+b*b;                                                 
	const int c = std::sqrt(c2);                                            
	if (c2 != c*c) continue;                                                
	if (p == (a+b+c)) {tmp++;}// std::cout << a << " " <<  b << std::endl;} 
      }                                                                         
    }                                                                           
    if (tmp > n) {n = tmp; i = p;}                                              
  }                                                                             
  std::cout << i << " -- " << n << std::endl;                                   
}       
