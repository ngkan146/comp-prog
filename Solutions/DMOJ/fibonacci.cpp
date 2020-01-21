#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull mod = (ull) 1e9+7;
struct matrix{
    ull m,n;
    vector < vector<ull> > ele;
    void init(ull x,ull y){
        m = x, n = y;
        ele.assign(m+1,vector<ull>());
        for(int i=1;i<=m;i++)   ele[i].assign(n+1,0);
        return;
    }
    void operator = (matrix y){
        ele = y.ele;
        m = y.m;
        n = y.n;
    }
    matrix operator * (matrix y){
        ull p = y.n;
        matrix res;
        res.init(m,p);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=p;k++)
                    res.ele[i][k] = (res.ele[i][k] + ele[i][j] * y.ele[j][k] % mod) % mod;
        return res;
    }
    void mullog(ull p){
        p-=2;
        p = max(p,0ull);
        matrix tmp, res;
        res.m = tmp.m = m;
        res.n = tmp.n = n;
        res.ele = tmp.ele = ele;
        for(ull i=0;i<64;i++){
            if (((1ull<<i) & p)) res = res * tmp;
            tmp = tmp * tmp;
        }
        ele = res.ele;
    }
};
ull n;
matrix fib,base;
int main(){
    cin >> n;
    fib.init(1ull,2ull);
    fib.ele[1][1] = 0; fib.ele[1][2] = 1;
    base.init(2ull,2ull);
    base.ele[1][1] = 0; base.ele[1][2] = 1;
    base.ele[2][1] = 1; base.ele[2][2] = 1;
    base.mullog(n);
    fib = fib * base;
    cout << fib.ele[1][2];
}