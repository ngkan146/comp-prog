#include <bits/stdc++.h>
using namespace std;
int n,m,x,sum;
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin>>x,sum+=x;
    cout << (abs(sum)+m-1)/m;
}
