#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int apples = 50000;

void eat_apple(mutex& firstMutex, mutex& secondMutex)
{
    int apples_eaten = 0;

    while (apples > 0)
    {
        scoped_lock lock(firstMutex, secondMutex);
        if (apples > 0)
        {
            apples_eaten++;
            apples--;
        }
    }

    printf("Thread %d and ate %d\n", std::this_thread::get_id(), apples_eaten);
}

int main()
{
    mutex firstMutex;
    mutex secondMutex;
    std::thread fizz(eat_apple, ref(firstMutex), ref(secondMutex));
    std::thread ashe(eat_apple, ref(secondMutex), ref(firstMutex));
    fizz.join();
    ashe.join();
    return 0;
}
