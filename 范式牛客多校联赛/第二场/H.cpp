#pragma GCC optimize(2)
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
void Solve(){
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = ' ' + s;
    vector<ll> pre(n + 1);
    vector<int> st(n + 1);
    rep(i, 1, n){
        if(s[i] == 'A'){
            st[i] = st[i - 1] ^ 1;
            pre[i] = pre[i - 1];
        }else{  
            st[i] = st[i - 1];
            if(st[i]) pre[i] = pre[i - 1] - 1;
            else pre[i] = pre[i - 1] + 1;
        }
    }
    ll res = 0;
    while(m --){
        ll l, r; 
        string mask; 
        cin >> l >> r >> mask;
        ll L, R;
        L = min((res ^ l) % n + 1, (res ^ r) % n + 1);
        R = max((res ^ l) % n + 1, (res ^ r) % n + 1);
        l = L, r = R;
        reverse(mask.begin(), mask.end());
        int idx = 0;
        res = 0;
        for(auto x : mask){
            res |= (ll)(x == '1') << idx;
            idx ++;
        }
        ll mod = 1ll << idx;
        if(st[l - 1]){
            res = (res + (pre[l - 1] - pre[r])%mod+mod) % mod;
        }else res = (res + (pre[r] - pre[l - 1])%mod+mod) % mod;
        if(st[r] != st[l - 1]) res ^= mod - 1;
        for(int i = idx - 1;i >= 0;i --){
            cout << (res >> i & 1);
        }cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}