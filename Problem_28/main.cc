#include "common.hh"

int main() 
{
    int sum = 1;
    for (int i = 2; i <= 501; i++)
    {
        sum += (16 * std::pow(i,2) - (28 * i) + 16);
    }
    std::cout << sum << std::endl;
}
