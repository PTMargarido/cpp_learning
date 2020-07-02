#include <memory>
#include <iostream>

std::weak_ptr<int> pWeak;

void observe()
{
    std::cout << pWeak.use_count() << "\n";
    if(auto spt = pWeak.lock())
        std::cout << *spt << " Has Expired " << pWeak.expired() << "\n";
    else
        std::cout << " Has Expired " << pWeak.expired() << "\n";
} 


int main( )
{
    auto pUnique = std::make_shared<int>(); 
    {
        auto pShared = std::make_shared<int>(42);
        pWeak = pShared;
        pUnique = pShared;
        observe();
    }

    std::cout << "----\n";
    observe();

}
