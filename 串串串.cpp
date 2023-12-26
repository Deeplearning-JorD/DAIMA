/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 12:04:31
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
typedef long long ull;
const int N = 2e5 + 10, P = 131, PP = 1331;
const ll MOD = 1e9 + 7;
ll hh[N], pp[N];
ull h[N], p[N];
ull find(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}
ll find1(int l, int r){
    return (hh[r] - hh[l - 1] * pp[r - l + 1] % MOD + MOD) % MOD;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = 'z' + s;
    p[0] = 1;
    pp[0] = 1;
    rep(i, 1, n){
        h[i] = h[i - 1] * P + s[i] - 'a';
        hh[i] = (hh[i - 1] * PP % MOD + s[i] - 'a' + 1) % MOD;
        pp[i] = pp[i - 1] * PP % MOD;
        p[i] = p[i - 1] * P;
    }
    vector<vector<int>> pre(26, vector<int> (n + 1));
    rep(c, 0, 25){
        for(int i = 1;i <= n;i ++){
            pre[c][i] = pre[c][i - 1];
            if(s[i] - 'a' == c) pre[c][i] ++;
        }
    }
    while(m --){
        int op, l, r, L, R;
        cin >> op >> l >> r >> L >> R;
        if(op == 1){
            cout << ((find(l, r) == find(L, R))&&(find1(l, r) == find1(L, R))) << endl;
        }else{
            bool st = true;
            rep(i, 0, 25){
                if(pre[i][r] - pre[i][l - 1] != pre[i][R] - pre[i][L - 1])
                    st = false;
            }
            cout << st << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}