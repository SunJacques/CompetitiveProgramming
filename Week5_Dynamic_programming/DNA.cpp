#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef unsigned long long ull;

int main(){
    int N;
    // string line;
    cin >> N;
    vector<unsigned long long> L(N);
    vector<unsigned long long> prefix_sum(N+1,0);
    vector<vector<unsigned long long> > dp(N,vector<unsigned long long>(N,0));
    
    // getline(cin, line);

    // stringstream ss(line);

    
    // ull number;
    // while (ss >> number){
    //     sequence.push_back(number);
    // }

    for (int i = 0; i < N; i++){
        cin >> L[i];
        prefix_sum[i + 1] = prefix_sum[i] + L[i]; 
    }

    for (int length = 2; length <= N; length++){
        for (int i = 0; i <= N - length; i++){
            int j = i + length - 1;
            dp[i][j] = ULLONG_MAX;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + prefix_sum[j+1] - prefix_sum[i]);
            }
        }
    }

    printf("%llu \n", dp[0][N - 1]);
    return 0;
}
