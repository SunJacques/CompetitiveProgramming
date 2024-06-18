#include<iostream>

using namespace std;


int main(){
    int D, H, M;

    cin >> D >> H >> M;
    long int time = D*24*60 + H*60 + M - 11 * (24*60 + 60 + 1);
    cout << (time < 0 ? -1 : time) <<endl;

    return 0;
}