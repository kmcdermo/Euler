///////////////////////////////////////////////////////////////////////////////
// File     : common.hh                                                      //
//                                                                           //
// Overview : Common header file for Project Euler main.cc files.            //
//                                                                           //
// Author   : Kevin McDermott                                                //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <utility>
#include <string>

namespace StrMath
{
    void carry_val(const unsigned long long i, unsigned long long& val, unsigned long long& carry)
    {
        if (carry > 0) val += carry;
        if (val >= 10 && i != 0) {carry = val / 10; val %= 10;}
        else carry = 0;
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
        const unsigned long long num_1_L = num_1.length();
        const unsigned long long num_2_L = num_2.length();
        const unsigned long long diff_L = num_1_L-num_2_L;
        
        // L = length, D = digit
        std::string output = "";
        unsigned long long carry = 0;
        for (unsigned long long i = num_1_L-1; i != -1; i--)
        {
            unsigned long long val = 0;
            const unsigned long long num_1_D = std::stoull(std::string(1, num_1[i]));
            if (i >= diff_L)
            {
                const unsigned long long num_2_D = std::stoull(std::string(1, num_2[i-diff_L]));
                val = num_1_D + num_2_D;
                carry_val(i, val, carry);
                output.insert(0, std::to_string(val));
            } 
            else
            {
                val = num_1_D;
                carry_val(i, val, carry);
                output.insert(0, std::to_string(val));
            }
        }
        
        return output;
    }

    std::string multiply_strings_as_numbers(std::string num_1, std::string num_2)
    {
        // Orient algorithm to longer number
        if (num_1.length() < num_2.length())
        {
            const std::string tmp = num_1;
            num_1 = num_2;
            num_2 = tmp;
        }
        
        std::vector<std::string> outputs;
        for (unsigned long long i = num_2.length()-1; i != -1; i--)
        {
            unsigned long long carry = 0;
            std::string output = "";
            const unsigned long long num_2_D = std::stoull(std::string(1, num_2[i]));

            for (unsigned long long j = num_1.length()-1; j != -1; j--)
            {
                const unsigned long long num_1_D = std::stoull(std::string(1, num_1[j]));
                unsigned long long val = num_1_D * num_2_D;
                carry_val(j, val, carry);
                output.insert(0, std::to_string(val));
            }

            for (unsigned long long j = num_2.length()-1; j > i; j--)
            {
                output += "0";
            }

            outputs.push_back(output);
        }

        std::string sum = "0";
        for (auto&& output : outputs)
        {
            sum = StrMath::add_strings_as_numbers(sum, output);
        }
        
        return sum;
    }
};
