#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1005],ans;
int main(){
    cin>>n>>m>>k;for(int i=1;i<=m+1;i++)cin>>a[i];for(int i=1;i<=m;i++)ans+=__builtin_popcount(a[m+1]^a[i]) <= k?1:0;cout<<ans;
}