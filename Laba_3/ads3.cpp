#include <iostream>
#include <set>

int main() 
{
    long long x;
    std::cin >> x;

    std::set<long long> numbers;

    long long pow3 = 1;
    for (int k = 0; pow3 <= x; k++) 
    {
        long long pow5 = 1;
        for (int l = 0; pow3 * pow5 <= x; l++) 
        {
            long long pow7 = 1;
            for (int m = 0; pow3 * pow5 * pow7 <= x; m++) 
            {
                numbers.insert(pow3 * pow5 * pow7);
                if (pow7 > x / 7) break; 
                pow7 *= 7;
            }
            if (pow5 > x / 5) break;
            pow5 *= 5;
        }
        if (pow3 > x / 3) break;
        pow3 *= 3;
    }

    for (long long num : numbers) 
    {
        std::cout << num << " "; 
    }
}