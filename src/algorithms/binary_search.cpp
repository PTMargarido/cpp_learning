#include <iostream>
#include <chrono>
#include <random>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <vector>


auto binary_search(const std::vector<int>& vec, int numberToFind)
{
    int iterations = 0;
    int startPos = 0;
    int highPos = vec.size() - 1;

    while (startPos <= highPos)
    {
        iterations++;
        int midPos = (startPos + highPos) / 2;

        if (vec[midPos] == numberToFind)
        {
            return std::tuple<int, int, bool>(midPos, iterations, true);
        }
        else if (vec[midPos] > numberToFind)
            highPos = midPos - 1;
        else
            startPos = midPos + 1;
    }

    return std::tuple<int, int, bool>(0, iterations, false);
}


int main ()
{
    long int vecSize = 1000000000;
    std::cout << "Creating vector " << vecSize << " entries \n";
    std::vector<int> vec;
    vec.resize(vecSize);

    std::cout << "Generating data to the vector \n";
    std::iota(vec.begin(), vec.end(), 0);
    
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, vecSize); 
    std::cout << "Generating position to look \n";

    int pos = dist(rng);

    std::cout << "Looking for " << pos << "\n";

    auto start = std::chrono::steady_clock::now();
  auto [position, iterations, found] = binary_search(vec, pos);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    if (found)
        std::cout << "Found element at pos " << position << " after " << iterations << " iterations in " << elapsed_seconds.count() << std::endl;
    else
        std::cout << "Did not find element in "  << iterations << " iterations" << std::endl;
}
