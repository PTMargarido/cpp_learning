#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <numeric>
#include <algorithm>
#include <tuple>

using namespace std;

auto smallMinElement(vector<int> vec)
{
    int count = 0;
    int smallestValue = vec[0];
    int smallestIndex = 0;
    for(auto c: vec)
    {
        if (c < smallestValue)
        {
            smallestValue = c;
            smallestIndex = count;
        }
        count++;
    }
    return tuple<int, int>(smallestIndex, smallestValue);
}

auto selection_sort(vector<int>& vec)
{
    vector<int> vecResult;

    auto vecSize = vec.size();
    vecResult.reserve(vecSize);

    for (int i = 0; i < vecSize; ++i)
    {
        auto [index, value] = smallMinElement(vec);
        vecResult.emplace_back(value);
        vec.erase(vec.begin() + index);
    }

    vec = vecResult;
    return vec;
}

int main()
{
    vector<int> vec;
    vec.resize(100);

    iota(vec.begin(), vec.end(), -100);
    
    random_shuffle(vec.begin(), vec.end());

    selection_sort(vec);
    
    for (auto c: vec)
        cout << c << endl;
}
