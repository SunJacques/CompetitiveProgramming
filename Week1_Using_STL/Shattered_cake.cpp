#include <iostream>
using namespace std;

int main(){
    unsigned int totalWidth, numberCake, pieceWidth, pieceLength, area;
    area = 0;
    cin >> totalWidth;
    cin >> numberCake;

    for (unsigned int i = 0 ; i < numberCake; i++){
        cin >> pieceWidth >> pieceLength;
        area += pieceLength * pieceWidth;
    }

    cout << area / totalWidth << endl;

    return 0;
}

