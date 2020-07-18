#include <iostream>
#include <memory>
#include <string>


using namespace std;
class ListNode
{
    public:
    explicit ListNode(string&& strName): 
        m_pNext(nullptr),
        m_pPrevious(nullptr),
        m_pLastNode(this),
        strName(strName)
    {
    }

    ~ListNode()
    {
        cout << "Destructor invoked \n";
    }


    void insertAtEnd(string&& str)
    {
        auto listNode = new ListNode(std::move(str));
        cout << "Constructing ListNode with address "<< listNode << endl;

        auto previousNode = m_pLastNode;

        m_pLastNode->m_pNext = listNode;
        m_pLastNode = listNode;
        m_pLastNode->m_pPrevious = previousNode;
    }


    string pop()
    {
        auto pHold = m_pLastNode;
        string str = m_pLastNode->strName;
        m_pLastNode->strName = "";

        m_pLastNode = m_pLastNode->m_pPrevious;
        m_pLastNode->m_pNext = nullptr;

        delete pHold;
        return str;
    }

    void dropList()
    {
        while(m_pLastNode != this)
        {
            auto pHold = m_pLastNode;
            cout << "Deleting ListNode with address " << pHold << endl;
            m_pLastNode = m_pLastNode->m_pPrevious;
            m_pLastNode->m_pNext = nullptr;
            delete pHold;
        }
    }

    ListNode* m_pNext;
    ListNode* m_pPrevious;
    ListNode* m_pLastNode;
    string strName;
};

void printNames(ListNode* head)
{
    ListNode* it = head;
    while(it != nullptr)
    {
        cout << it->strName << endl;
        it = it->m_pNext;
    }
}


int main()
{
   ListNode* linkedList = new ListNode("Entry1");
   linkedList->insertAtEnd("Entry1");
   linkedList->insertAtEnd("Entry2");
   linkedList->insertAtEnd("Entry3");

   printNames(linkedList);

   linkedList->dropList();


   printNames(linkedList);

}
