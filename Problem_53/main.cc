#include "common.hh"

static constexpr int n_max = 100;
static constexpr int limit = 1000000;

void get_factors(const int n, std::vector<int> & factors)
{
    auto factor = 0;
    for (auto i = 2; i < n; i++)
    {
        if (n % i == 0) {factor = i; break;}
    }
    
    if (factor != 0)
    {
        const auto dividend = n / factor;
        factors.push_back(factor);
        if (dividend != 1) get_factors(dividend,factors);
    }
    
    else factors.push_back(n);
}

void generate_factors(std::map<int, std::vector<int>>& factor_map)
{
    for (auto i = 2; i <= n_max; i++)
    {
        std::vector<int> factors;
        get_factors(i, factors);
        factor_map[i] = factors;
    }
}

void get_multiples(const int beg, const int end, const std::map<int, std::vector<int>> & factor_map, std::map<int, int> & multiples)
{
    std::vector<int> factors;
    for (auto i = beg; i > end; i--)
    {
        factors.insert(std::end(factors), std::begin(factor_map.at(i)), std::end(factor_map.at(i)));
    }
    std::sort(factors.begin(), factors.end());
    
    // Convert factors into multiple map
    for (auto && factor : factors)
    {
        multiples[factor]++;
    }
}

void erase_zeros(std::map<int, int> & multiples)
{
    auto itr = multiples.begin();
    while (itr != multiples.end())
    {
        if (itr->second == 0)
        {
            multiples.erase(itr++);
        }
        else
        {
            ++itr;
        }
    }
}


int main() 
{
    // generate all prime factors for each number
    std::map<int, std::vector<int>> factor_map;
    generate_factors(factor_map);
    
    // main counter
    auto counter = 0;
    
    // Loop over numerator options
    for (auto n = 1; n <= n_max; n++)
    {
        // Loop over denominator options
        for (auto r = 1; r < n; r++)
        {
            // n-r
            const auto n_minus_r = n-r;

            // set big cancel
            const auto big_cancel = (n_minus_r > r) ? std::make_pair(n_minus_r, r) : std::make_pair(r, n_minus_r);

            // Store the multiples for the numerator not cancelled
            std::map<int, int> numer_multiples;
            get_multiples(n, big_cancel.first, factor_map, numer_multiples);
            
            // Store the multiples for the denominator not cancelled
            std::map<int, int> denom_multiples;
            get_multiples(big_cancel.second, 1, factor_map, denom_multiples);

            // Reduce numerator (denom will always cancel)
            for (auto & numer_pair : numer_multiples)
            {
                const auto multiple = numer_pair.first;
                if (denom_multiples.count(multiple))
                {
                   numer_pair.second-= denom_multiples.at(multiple);
                }
            }

            // Erase zeros
            erase_zeros(numer_multiples);

            // Multiply out the remainder
            auto product = 1;
            for (auto & numer_pair : numer_multiples)
            {
                product *= std::pow(numer_pair.first, numer_pair.second);
                if (product > limit)
                {
                    counter++;
                    break;
                }
            }
        }
    }

    std::cout << counter << std::endl;
}
