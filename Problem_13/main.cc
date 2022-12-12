#include "common.hh"

void read_in(std::string inputname, std::vector<std::string>& numbers);
std::string add_strings_as_numbers(std::string num_1, std::string num_2);
void check_carry(int& tmp, const int i, bool& is_carry);

const int N = 10;

int main() 
{
    std::string inputname = "input.txt";
    std::vector<std::string> numbers;
    read_in(inputname, numbers);

    std::string sum = "0";
    for (auto&& number : numbers)
    {
        sum = add_strings_as_numbers(sum, number);
    }
    
    std::cout << sum.c_str() << std::endl;
}

std::string add_strings_as_numbers(std::string num_1, std::string num_2)
{
    // Orient algorithm to longer number
    if (num_1.length() < num_2.length())
    {
        const std::string tmp = num_1;
        num_1 = num_2;
        num_2 = tmp;
    }

    // Store lengths (L) of each number 
    const int num_1_L = num_1.length();
    const int num_2_L = num_2.length();
    const int diff_L = num_1_L-num_2_L;

    // L = length, D = digit
    std::string output = "";
    bool is_carry = false;
    for (int i = num_1_L-1; i >= 0; i--)
    {
        int tmp = 0;
        const int num_1_D = std::stoi(std::string(1, num_1[i]));
        if (i >= diff_L)
        { 
            const int num_2_D = std::stoi(std::string(1, num_2[i-diff_L]));
            tmp = num_1_D + num_2_D;
            check_carry(tmp, i, is_carry);
            output.insert(0, std::to_string(tmp));
        } 
        else
        {
            tmp = num_1_D;
            check_carry(tmp, i, is_carry);
            output.insert(0, std::to_string(tmp));
        }
    }

    return output;
}

void check_carry(int& tmp, const int i, bool& is_carry)
{
    if (is_carry) tmp += 1;
    if (tmp >= 10 && i != 0) {is_carry = true; tmp -= 10;}
    else is_carry = false;
}

void read_in(std::string inputname, std::vector<std::string>& numbers)
{
    std::ifstream inputfile(inputname.c_str(),std::ios_base::in);
    
    std::string number;
    while (inputfile >> number)
    {
        numbers.push_back(number);
    }
}
