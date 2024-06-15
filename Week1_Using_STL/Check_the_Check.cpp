#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char menuItem[1001] = {0};
    int itemPrice, quantity, totalPrice;
    int tmpPrice = 0;

    while (scanf("%[^\n]", menuItem) == 1){
        if (strcmp(menuItem, "TOTAL") == 0){
            scanf("%d", &totalPrice);
            cout << ((tmpPrice >= totalPrice) ? "PAY" : "PROTEST") << endl;
        }
        else{
            scanf("%d %d \n", &itemPrice, &quantity);
            tmpPrice += itemPrice * quantity;
        }

    }
    
    return 0;
}
