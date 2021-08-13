#include <iostream>
#include <vector>
#include <algorithm>

/* Code Wars Kata: https://www.codewars.com/kata/558fc85d8fd1938afb000014/train/cpp
Create a function that returns the sum of the two lowest positive numbers given an 
array of minimum 4 positive integers. No floats or non-positive integers will be passed .*/

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    // { 5, 8, 12, 19, 22 } 
    int min = *min_element(numbers.begin(), numbers.end());
    numbers.erase(min_element(numbers.begin(), numbers.end()));
    min += *min_element(numbers.begin(), numbers.end());
    std::cout << min << std::endl;
    return min;
}

// Optimum solution would be : 
//long sumTwoSmallestNumbers(std::vector<int> numbers)
//{
//    std::sort(numbers.begin(), numbers.end());
//
//    return (long)numbers[0] + (long)numbers[1];
//}

int main() {
    sumTwoSmallestNumbers({ 5, 8, 12, 19, 22 });
}