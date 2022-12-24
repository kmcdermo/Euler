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
    void carry_val(const int i, int& val, int& carry)
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
        const int num_1_L = num_1.length();
        const int num_2_L = num_2.length();
        const int diff_L = num_1_L-num_2_L;
        
        // L = length, D = digit
        std::string output = "";
        int carry = 0;
        for (int i = num_1_L-1; i >= 0; i--)
        {
            int val = 0;
            const int num_1_D = std::stoi(std::string(1, num_1[i]));
            if (i >= diff_L)
            { 
                const int num_2_D = std::stoi(std::string(1, num_2[i-diff_L]));
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

    std::string mulitply_strings_as_numbers(std::string num_1, std::string num_2)
    {
        // Orient algorithm to longer number
        if (num_1.length() < num_2.length())
        {
            const std::string tmp = num_1;
            num_1 = num_2;
            num_2 = tmp;
        }
        
        std::vector<std::string> outputs;
        for (int i = num_2.length()-1; i >= 0; i--)
        {
            int carry = 0;
            std::string output = "";
            const int num_2_D = std::stoi(std::string(1, num_2[i]));

            for (int j = num_1.length()-1; j >= 0; j--)
            {
                const int num_1_D = std::stoi(std::string(1, num_1[j]));
                int val = num_1_D * num_2_D;
                carry_val(j, val, carry);
                output.insert(0, std::to_string(val));
            }

            for (int j = num_2.length()-1; j > i; j--)
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
