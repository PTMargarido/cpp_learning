#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


struct Person
{
    string strProfession;
    vector<string> vecFriends;

    Person() = default;
    Person(const string&& strProfession, const vector<string>&& vecFriends)
            : strProfession(move(strProfession)),
              vecFriends(move(vecFriends))
    {

    };

};

using PersonHashTable = unordered_map<string, Person>;

vector<string> breadth_first_search(PersonHashTable mapPersons, string strEntryPoint, string strProfession)
{
    queue<vector<string>> queuePersons;
    vector<string> vecSearchedPersons;

    auto initialPerson = mapPersons[strEntryPoint];

    if(initialPerson.strProfession == strProfession)
        return {strEntryPoint};

    queuePersons.push({strEntryPoint});

    while(!queuePersons.empty())
    {
        auto nextPath = queuePersons.front();
        queuePersons.pop();

        auto strNextName = nextPath.back();

        if (find(vecSearchedPersons.cbegin(), vecSearchedPersons.cend(), strNextName) != vecSearchedPersons.cend())
            continue;

        if(mapPersons[strNextName].strProfession == strProfession)
            return nextPath;
        else
        {
            for (auto strFriend: mapPersons[strNextName].vecFriends)
            {
                auto itPath = nextPath;
                itPath.emplace_back(strFriend);
                queuePersons.push(itPath);
            }
        }

        vecSearchedPersons.emplace_back(strNextName);
    }
};

int main()
{
    
    PersonHashTable  mapPersons;
    mapPersons["Pedro"] = Person({"SWE", {"Sara", "Azevedo", "Tomas", "Luis", "Ines"}});
    mapPersons["Sara"] = Person({"Cabin Crew", {"Jackie", "Joana"}});
    mapPersons["Tomas"] = Person({"Doctor", {"Guilherme"}});
    mapPersons["Azevedo"] = Person({"SWE", {"Ines", "Pedro"}});
    mapPersons["Luis"] = Person({"Student", {}});
    mapPersons["Ines"] = Person({"Student", {}});
    mapPersons["Jackie"] = Person({"Pharma", {}});
    mapPersons["Joana"] = Person({"Accountant", {"Ze"}});
    mapPersons["Ze"] = Person({"Fisherman", {}});
    mapPersons["Guilherme"] = Person({"Doctor", {}});

    auto vecSolution = breadth_first_search(mapPersons, "Pedro", "SWE");

    for (auto entry: vecSolution)
        std::cout << entry << "\n";

}
