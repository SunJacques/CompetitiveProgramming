#include <iostream>

using namespace std;

int main(){
    long double e;
    long double total = 0;

    while (scanf("%Lf", &e) == 1){
        total += e;
    }
    
    printf("%.2Lf",total);

    return 0;
}