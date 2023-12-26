/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 14:54:56
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
int getlen(ll x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt ++;
    }
    return cnt;
}
void Solve(){
    ll w;
    string l, r;
    vector<bool> vis(10);
    cin >> l >> r >> w;
    int js = 0;
    rep(i, 1, 9){
        if((i ^ w) < 10){
            js ++;
            vis[i] = true;
        }
    }
    if(siz(r) < 2){
        cout << 0 << endl;
        return;
    }else if(siz(l) < 2){
        l = "10";
    }
    ll res = 0;
    ll need = siz(r) - siz(l) - 1;
    need = max(0ll, need);
    need *= js;
    res += need;
    ll now = l[0] - '0';
    string ls = "", last;
    ls += (char)(now + '0');
    for(int i = 1;i < siz(l);i ++){
        now ^= w;
        if(now >= 10){
            ls = ""; break;
        }
        ls += to_string(now);
    }
    last = ls;
    if(ls >= l) res ++;
    if(siz(l) == siz(r)){
        if(l[0] != r[0]){
            for(auto z = l[0] + 1;z < r[0];z ++) 
                if(vis[z - '0']) res ++;
        }
    }else{
        for(auto z = l[0] + 1;z <= '9';z ++) 
            if(vis[z - '0']) res ++;
    }
    ls = ""; 
    now = r[0] - '0';
    ls += (char)(now + '0');
    for(int i = 1;i < siz(r);i ++){
        now ^= w;
        if(now >= 10){
            ls = ""; break;
        }
        ls += to_string(now);
    }
    if(ls <= r&&last != ls&&ls != "") res ++;
    if(siz(l) != siz(r)){
        for(auto z = '1';z < r[0];z ++) 
            if(vis[z - '0']) res ++;
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