/*
 * @Author: JorD
 * @LastEditTime: 2023-08-17 16:11:53
 * how to Get
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
const int N = 5e5 + 10;
void Solve(){
    int n, c; cin >> n >> c;
    vector<vector<int>> s(c + 1);
    map<int, vector<int>> son;
    map<int,int> st; 
    rep(i, 1, n){
        int x; cin >> x;
        int m; cin >> m;
        son[x].resize(m);
        for(auto &j : son[x]){
            cin >> j;
            s[j].push_back(x);
        }
        st[x] = 0;
    }
    ll suml = 0, sumr = 0, cntl = 0, cntr = 0;
    unordered_map<int,ll> l, r;
    rep(i, 1, c){
        sort(s[i].begin(),s[i].end());
        s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
        int last = -1;
        for(auto x:s[i]){
            if(last != -1){
                int mid = last + x + 1 >> 1;
                st[mid] ++;
                l[mid] += last;
                r[mid] += x;
            }
            last = x;
        }
        sumr += s[i][0];
        cntr ++;
    }
    ll res = sumr;
    for(auto &[i, j] : st){
        if(j){
            cntl -= j, cntr += j;
            suml -= l[i], sumr += r[i];
        }
        if(son.count(i)){
            ll len = son[i].size();
            cntl += len; cntr -= len;
            suml += len * i; sumr -= len * i;
        }    
        res = min(res, 1ll * cntl * i - suml + sumr - 1ll * cntr * i);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}