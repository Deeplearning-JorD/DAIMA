/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 02:16:26
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void out(int x){
    while(x){
        cout << (x & 1);
        x >>= 1;
    }
    cout << endl;
}
void Solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<vector<ll>> f(n + 1, vector<ll> (9, 0));
    // f[i][j]表示到第i个人时候药水状态为j时的能量值
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    f[0][0] = m;
    f[0][1] = 3 * m;
    f[0][7] = 12 * m;
    f[0][2] = f[0][4] = 2 * m;
    f[0][3] = f[0][5] = 6 * m;
    f[0][6] = 4 * m;
    int res = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < 8;j ++){
            if(f[i - 1][j] <= a[i]) continue;
            f[i][j] = f[i - 1][j] + (a[i] >> 1);
            res = i;
        }
        for(int j = 7;j >=0;j --){
            for(int jj = 0;jj < 8;jj ++){
                if((j|jj)>jj) continue;
                int js1 = 0, js2 = 0;
                for(int k = 0;k <= 2;k ++){
                    if(((1 << k)&jj)&&(!((1<<k)&j))){
                        if(k == 0) js2 ++;
                        else js1 ++;
                    }
                }
                if(js1) js1 = js1 * 2;
                else js1 = 1;
                if(js2) js2 = js2 * 3;
                else js2 = 1;
                f[i][jj] = max(f[i][jj], f[i][j] * js1 * js2);
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}