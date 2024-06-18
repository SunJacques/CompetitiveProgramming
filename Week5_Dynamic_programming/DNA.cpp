#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef unsigned long long ull;

int main(){
    int N;
    // string line;
    cin >> N;
    long long int INF = 99999999999;
    vector<long long int> L(N);
    vector<long long int> prefix_sum(N+1,0);
    vector<vector<long long int> > dp(N,vector<long long int>(N,0));
    
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
            dp[i][j] = INF;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + prefix_sum[j+1] - prefix_sum[i]);
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[0][N - 1] << endl;
    return 0;
}
