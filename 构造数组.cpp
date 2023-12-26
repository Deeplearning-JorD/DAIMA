/*
 * @Author: JorD
 * @LastEditTime: 2022-11-05 20:00:37
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "  " + s;
    vector<int> d(n + 2);
    rep(i, 2, n){
        if(s[i] == '<'){
            d[i] = 1; 
        }else if(s[i] == '>'){
            d[i] = -1;
        }else d[i] = 0;
    }
    vector<int> js(n + 1);
    
    rep(i, 1, n){
        int now = 0;
        int j = i;
        while(j <= n&&!d[j]) j ++, now ++;
        js[i - 1] = now;
        
        i = j;

    }
    vector<int> pre(n + 1);
    int mi = 1e9;
    for(int i = 2;i <= n;i ++){
        pre[i] = d[i] + pre[i - 1];
        mi = min(pre[i], mi);
    }
    if(mi < 0){
        d[1] -= mi - 1;
    }else d[1] = 1;
    vector<int> res;
    res.push_back(d[1]);
    for(int i = 2;i <= n;i ++){
        d[1] += d[i];
        res.push_back(d[1]);
    }
    
    rep(i, 1, n - 1){
        auto now = res;
        bool st = true;
        int u = 1;
        if(d[i + 1] > 0){
            if(u <= res[i - 1]) st = false;
        }
        if(i + 2 <= n && d[i + 2] < 0){
            if(u <= res[i + 1]) st = false;
        }
        if(st) res[i] = 1;
    }
    rep(i, 0, n - 1){
        for(int j = 1;j <= js[i];j ++) cout << res[i] << ' ';
        if(!js[i])cout << res[i] << ' ';
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}