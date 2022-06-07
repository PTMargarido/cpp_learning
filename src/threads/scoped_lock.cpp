#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

using namespace std;

int apples = 500000;
mutex eat_apple_mutex;
condition_variable cv;

void eat_apple(int nId)
{
    int apples_eaten = 0;

    while (apples > 0)
    {
        unique_lock<mutex> lock (eat_apple_mutex);

        while ((nId != (apples % 4)) && apples > 0)
            cv.wait(lock);

        if (apples > 0)
        {
            apples_eaten++;
            apples--;
        }

        lock.unlock();
        cv.notify_all();
    }

    printf("Thread %d and ate %d\n", nId, apples_eaten);
}

int main()
{
    std::thread fizz(eat_apple, 0);
    std::thread ashe(eat_apple, 1);
    std::thread sion(eat_apple, 2);
    std::thread ahri(eat_apple, 3);
    fizz.join();
    ashe.join();
    sion.join();
    ahri.join();
    return 0;
}
