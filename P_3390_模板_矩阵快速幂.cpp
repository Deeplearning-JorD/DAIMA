/*
 * @Author: JorD
 * @LastEditTime: 2023-05-09 00:02:19
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int mod = 1e9 + 7;
ll n, k;
struct Matrix{
    ll M[110][110];
    Matrix(){memset(M, 0, sizeof M);}
    void set(){
        for(int i = 0;i < n;i ++) M[i][i] = 1;
    }
    void reset(){
        memset(M, 0, sizeof M);
    }
    void show(){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++){
                cout << M[i][j] << ' ';
            }cout << endl;
        }
    } 
};
Matrix operator *(Matrix L, Matrix R){
    Matrix res;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++){
            for(int k = 0;k < n;k ++){
                res.M[i][j]=(res.M[i][j]+L.M[i][k]*R.M[k][j]%mod)%mod;
            }
        }
    }
    return res;
}
void Solve(){
    cin >> n >> k;
    Matrix a;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++)
            cin >> a.M[i][j];
    }
    Matrix res;
    res.set();
    while(k){
        if(k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    res.show();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}