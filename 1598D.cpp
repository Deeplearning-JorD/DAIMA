/*
 * @Author: JorD
 * @LastEditTime: 2022-11-24 17:04:47
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
void Solve(){
    ll n;
    cin >> n;
    vector<pair<int,int>> jiji(n + 1);
    vector<int> numL(n + 1), numR(n + 1);
    for(int i = 1;i <= n;i ++){
        int a, b;
        cin >> a >> b;
        jiji[i] = {a, b};
        numL[a] ++;
        numR[b] ++;
    }
    ll res = n * (n - 1) * (n - 2) / 6;
    for(int i = 1;i <= n;i ++){
        int l = jiji[i].first, r = jiji[i].second;
        int L = numL[l] - 1, R = numR[r] - 1;
        res -= 1ll * L * R;
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