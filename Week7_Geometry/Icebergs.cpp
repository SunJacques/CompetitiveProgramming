#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int N;
    long long int totalArea = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        int P;
        long int x0, y0, x1, y1, p0, p1;
        long long int area = 0;
        cin >> P;

        cin >> x0 >> y0;
        
        p0 = x0;
        p1 = y0;
        for (int j = 0; j < P - 1; j++){
            cin >> x1 >> y1;
            area += (x0 - x1) * (y0 + y1);
            x0 = x1;
            y0 = y1;
        }
    
        area += (x0 - p0) * (y0 + p1);
        area = abs(area);

        totalArea += area;
    }


    printf("%lld", totalArea / 2);

    return 0;
}
