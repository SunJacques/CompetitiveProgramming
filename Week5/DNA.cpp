#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef unsigned long long ull;

int main(){
    int N;
    string line;
    vector<int> sequence;
    
    getline(cin, line);

    stringstream ss(line);

    cin >> N;
    ull number;
    while (ss >> number){
        sequence.push_back(number);
    }

    
    return 0;
}

int cut(vector<int> sequence){
    vector< vector<int> > possibleCut;
    ull cost;
    if (sequence.size() == 1){
        return 0;
    }
    else{
        for (ull n : sequence){
            cost += n;
        }
        for (int i = 0; i < sequence.size(); i++){
            possibleCut.push_back(vector<int>(sequence.begin() + i, sequence.end()));
        }
    }

    return cost;
}