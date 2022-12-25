#include "common.hh"

struct BigExp
{
    BigExp(const int base, const int exp) :
        base(base), exp(exp) {};

    int base;
    int exp;
    double result;
};

int main()
{
    std::ifstream file("p099_base_exp.txt");
    std::vector<BigExp> base_exp_vec;

    std::string line;
    while(getline(file, line))
    {
        std::size_t i_comma = line.find(",");
        base_exp_vec.emplace_back(BigExp(std::stoi(line.substr(0,i_comma)),std::stoi(line.substr(i_comma+1,line.length()-i_comma-1))));
    }

    double biggest = 0.f;
    int idx = -1;
    for (int i = 0; i < base_exp_vec.size(); i++)
    {
        auto & base_exp = base_exp_vec[i];
        base_exp.result = base_exp.exp * std::log(base_exp.base);

        if (base_exp.result > biggest)
        {
            biggest = base_exp.result;
            idx = i;
        }
    }

    std::cout << idx+1 << std::endl;
    
}
