/*
 * @Author: JorD
 * @LastEditTime: 2022-09-10 19:59:04
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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(m + 1);
    vector<int> w;
    rep(i, 0, n - 1){
        cin >> w[i];
    }
    auto js = [&](string s) -> int{
        int idx = 0;
        int val = 0;
        for(auto x:s){
            if(x == '1') val += 1 << idx;
            idx ++;
        }
        return val;
    };
    map<int,int> q;
    rep(i, 1, m){
        string s;
        cin >> s;
        q[js(s)] ++;
    }
    vector<pair<int,int>> quer;
    rep(i, 0, 1 << n){
        int sum = 0;
        rep(j, 0, n - 1){
            if((1 << j) & i) sum += w[j];
        }
        quer.push_back({sum, i});
    }
    sort(quer.begin(), quer.end());
    vector<vector<int>> last(101);
    int nn = siz(quer), l = 0;
    rep(i, 0, 100){
        if(i) last[i] = last[i - 1];
        rep(j, l, nn){
            if(quer[j].first > i) break;
            last[i].push_back(quer[j].second);
        }
    }
    while(t --){
        string s;
        int k;
        cin >> s >> k;
        int now = js(s);
        int res = 0;
        for(auto x:last[k]){
            if(q[x^now]) res += q[x^now];
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    // while(t--)
    Solve();
    return 0;
}