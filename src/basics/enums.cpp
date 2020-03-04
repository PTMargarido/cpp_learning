#include <cstdint>

enum class Status: std::int32_t
{
    OK = 0,
    NOK = -1,
    ERROR = 1,
};

int main()
{
    Status tryOut;

    tryOut = Status::OK;
}
