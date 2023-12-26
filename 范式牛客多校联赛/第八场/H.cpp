/*
 * @Author: JorD
 * @LastEditTime: 2023-08-11 15:06:03
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
const int N = 1e6 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
int a[N], id[N];
void Solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    vector<int> sta;
    map<int,vector<int>> son;
    ll res = 0;
    rep(i, 1, n){
        if(a[i] == 1){
            sta.push_back(i);
            son[1].push_back(i);
        }else{
            if(son.count(a[i] - 1)){
                int id = son[a[i] - 1].back();
                son[a[i]].push_back(id);
                son[a[i] - 1].pop_back();
                if(son[a[i] - 1].empty()) son.erase(a[i] - 1);
                while(sta.size() && sta.back() > id){
                    sta.pop_back();
                }
            }else{
                sta.clear();
                son.clear();
            } 
        }
        res += sta.size();
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}
