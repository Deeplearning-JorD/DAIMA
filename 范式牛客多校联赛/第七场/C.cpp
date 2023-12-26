/*
 * @Author: JorD
 * @LastEditTime: 2023-08-09 01:12:03
 * 你妈的，29写成30了
 */
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
    ll n, k;
    cin >> n >> k;
    vector<ll> b(n), st(n + 1);
    rep(i, 1, n - 1) cin >> b[i];
    vector<int> use(31); 
    ll tot = 1;
    vector<int> mask;
    for(int i = 29;i >= 0;i --){
        vector<int> ls;
        for(int o = 0;o <= 1;o ++){
            int now = o;
            bool ff = true;
            int idx = 0;
            for(int j = 1;j < n;j ++){
                if(st[j]){
                    now ^= b[j] >> i & 1;
                    continue;
                }
                if(b[j] >> i & 1){
                    if(now == 0){
                        now = 1;
                        idx ++;
                        ls.push_back(j);
                    }else{
                        ff = false;
                        break;    
                    }
                }
            }
            if(!ff){
                while(idx --) ls.pop_back();
                continue;
            }
            use[i] += 1 << o;
        }
        if(use[i] == 0){
            cout << -1 << endl;
            return;
        }
        for(auto x:ls) st[x] = 1;
        if(use[i] == 3){
            tot *= 2;
            mask.push_back(i);
        }
    }
    if(tot < k){
        cout << -1 << endl;
        return;
    }
    int m = siz(mask) - 1;
    vector<int> ans(31, -1);
    k --;
    ll res = 0;
    for(auto x:mask){
        if(k >= (1 << m)){
            ans[x] = 1;
            k -= 1 << m;
        }
        m --;
    }
    for(int i = 29;i >= 0;i --)if(ans[i] == -1){
        if(use[i] == 2) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i = 29;i >= 0;i --)if(ans[i])res |= 1ll << i;
    cout << res << ' ';
    rep(i, 1, n - 1){
        res ^= b[i];
        cout << res << ' ';
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}