#include<iostream>

using namespace std;

int main(){
    int x,y, N;
    cin >> N;
    int counter = 0 , maxCounter = 0;
    for (int i =0; i < N; i ++){
        cin >> x >> y;
        if (x >= 31 && y >= 21){
            counter += 1;
        }
        else{
            if (counter > maxCounter){
                maxCounter = counter;
            }
            counter = 0;
        }
    }

    if (counter > maxCounter){
                maxCounter = counter;
    }
    
    cout << maxCounter << endl;

    return 0;
}