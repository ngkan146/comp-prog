#include <bits/stdc++.h>
using namespace std;
long long ss,n,m;
long long dp[(1<<19)][105];
bool used[15];
int a[25];
int main(){
    cin >> ss >> m;
    n = (long long) log10(ss) + 1;
    for(int i=n-1;i>=0;i--) a[i] = ss%10,ss/=10;
    dp[0][0] = 1;
    for(long long mask = 0;mask<(1<<n);mask++)  for(long long mod=0;mod<m;mod++){
        if (!dp[mask][mod]) continue;
        memset(used,0,sizeof(used));
        for(long long i=0;i<n;i++){
            if (!(mask & (1<<i)) && !used[a[i]]){
                used[a[i]] = 1;
                if (a[i] || mask) dp[(mask ^ (1<<i))][(10*mod+a[i])%m] += dp[mask][mod];
            }
        }
    }
    cout << dp[(1<<n)-1][0];
}
