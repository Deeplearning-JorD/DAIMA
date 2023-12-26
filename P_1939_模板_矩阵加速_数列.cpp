/*
 * @Author: JorD
 * @LastEditTime: 2023-05-09 00:39:25
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
struct Matrix{
    ll M[3][3];
    Matrix(){memset(M, 0, sizeof M);}
    void set(){
        for(int i = 0;i < 3;i ++) M[i][i] = 1;
    }
    void reset(){
        memset(M, 0, sizeof M);
    }
    void init(){
        M[0][0] = 1;
        M[0][1] = 0;
        M[0][2] = 1;
        M[1][0] = 1;
        M[1][1] = 0;
        M[1][2] = 0;
        M[2][0] = 0;
        M[2][1] = 1;
        M[2][2] = 0;
    }
    void show(){
        for(int i = 0;i < 3;i ++){
            for(int j = 0;j < 3;j ++){
                cout << M[i][j] << ' ';
            }cout << endl;
        }
    } 
};
Matrix operator *(Matrix L, Matrix R){
    Matrix res;
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            for(int k = 0;k < 3;k ++){
                res.M[i][j]=(res.M[i][j]+L.M[i][k]*R.M[k][j]%mod)%mod;
            }
        }
    }
    return res;
}
Matrix operator +(Matrix L, Matrix R){
    Matrix res;
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            res.M[i][j] = (L.M[i][j] + R.M[i][j])%mod;
        }
    }
    return res;
}
void Solve(){
    int n;
    cin >> n;
    if(n <= 3){
        cout << 1 << endl;
        return;
    }
    Matrix a, res;
    a.init();
    res.M[0][0] = 1;
    res.M[1][0] = 1;
    res.M[2][0] = 1;
    n -= 3;
    while(n){
        if(n & 1) res = a * res;
        a = a * a;
        n >>= 1;
    }
    cout << res.M[0][0] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}