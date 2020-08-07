#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

using namespace std;

auto quicksort(vector<int>& vec)
{
    // Divide and Conquer - base part
    if (vec.size() < 2)
        return vec;

    // Divide and Conquer - recursive part
    vector<int> lessThanPivot;
    vector<int> moreThanPivot;

    int pivot = vec[0];

    copy_if(vec.begin(), vec.end(), back_inserter(lessThanPivot), [&](const int element){
        return element < pivot;
    });

    copy_if(vec.begin(), vec.end(), back_inserter(moreThanPivot), [&](const int element){
        return element > pivot;
    });

    vector<int> vecResult;
    auto vecLessThan = quicksort(lessThanPivot);
    auto vecMoreThan = quicksort(moreThanPivot);

    copy(vecLessThan.begin(), vecLessThan.end(), back_inserter(vecResult));
    vecResult.emplace_back(vec[0]);
    copy(vecMoreThan.begin(), vecMoreThan.end(), back_inserter(vecResult));

    return vecResult;
}

int main()
{
    vector<int> vec;
    vector<int> vecResult;
    vec.resize(100);

    iota(vec.begin(), vec.end(), 100);

    random_shuffle(vec.begin(), vec.end());

    vecResult = move(quicksort(vec));

    for (auto c: vecResult)
        cout << c << endl;
}
