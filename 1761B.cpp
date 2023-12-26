/*
 * @Author: JorD
 * @LastEditTime: 2022-11-20 23:15:05
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
    vector<int> a(n + 1), cnt(n + 1);
    vector<pair<int,int>> jump(n + 1);
    rep(i, 1, n){
        int l = i - 1, r = i + 1;
        cin >> a[i];
        cnt[a[i]] ++;
        if(l == 0) l = n;
        if(r == n + 1) r = 1;
        jump[i] = {l, r};
    }
    int idx = 1, last = n;
    vector<bool> st(n + 1);
    int res = 0;
    while(last > 0){
        bool flag = false;
        int id = idx, t = last;
        vector<int> v;
        for(int j = 1;j <= t;j ++){
            auto [l, r] = jump[id];
            if(a[l] != a[r]||l == r){
                flag = true;
                v.push_back(id);
            }
            id = jump[id].second;
        }
        int mx = 0, idd = id;
        for(auto x:v){
            if(cnt[a[x]] > mx){
                mx = cnt[a[x]];
                idd = x;
            }
        }
        if(flag){
            id = idd;
            cnt[a[id]] --;
            auto [l, r] = jump[id];
            flag = true;
            res ++;
            last --;
            int &R = jump[l].second;
            int &L = jump[r].first;
            L = l;
            R = r;
            idx = r;
        }
        if(flag) continue; 
        id = idx;
        auto [l, r] = jump[id];
        res ++;
        cnt[a[r]] --;
        cnt[a[id]] --;
        jump[l].second = jump[r].second;
        last -= 2;
        idx = l;
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