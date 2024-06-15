#include <string>
#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<string> monumentList;
    string line;
    string monument;

    while (getline(cin, line)) {
        // Extract monument from each line
        monument = line.substr(11); // Skip the date part
        monumentList.insert(monument);
    }

    // Output the number of unique monuments
    cout << monumentList.size() << endl;

    return 0;
}