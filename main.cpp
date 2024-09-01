#include <iostream>
#include "aligned_vector.hpp"

int getTrailingBits(void* ptr)
{
    unsigned long long p = reinterpret_cast<unsigned long long>(ptr);
    int bits = 0;
    while ((p & 1) == 0)
    {
        p >>= 1;
        bits++;
    }
    return bits;
}

int main(int argc, char** argv)
{
    std::cout << "Hello, world!" << std::endl;
    int min1 = 1000;
    int min2 = 1000;
    for (int i = 0; i < 100; ++i)
    {
        std::vector<double> v1(10);
        std::aligned_vector<double> v2(10);
        min1 = std::min(min1, getTrailingBits(v1.data()));
        min2 = std::min(min2, getTrailingBits(v2.data()));
    }

    std::cout << "min1 = " << min1 << " " << (1<<min1) << std::endl;
    std::cout << "min2 = " << min2 << " " << (1<<min2) << std::endl;


}