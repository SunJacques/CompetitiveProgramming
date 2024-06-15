#include <string>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    map <string, long int> counter;
    string animal;
    int N;

    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        cin >> animal;
        ++counter[animal];
    }

    string mostAnimal = "NONE";

    for (const auto &pair : counter)
    {
        if (pair.second > N/2)
        {
            mostAnimal = pair.first;
        }
    }

    cout << mostAnimal;

    return 0;
}

