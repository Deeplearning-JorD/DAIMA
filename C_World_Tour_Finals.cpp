/*
 * @Author: JorD
 * @LastEditTime: 2023-10-07 20:17:01
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
void Solve(){
    int n, m; cin >> n >> m;
    vector<int> w(m + 1), sum(n + 1); 
    rep(I, 1, m) cin >> w[I];
    vector<vector<int>> son(n + 1);
    multiset<int> q;
    rep(i ,1, n){
        string s; cin >> s;
        sum[i] = i;
        for(int j = 0;j < m;j ++){
            if(s[j] == 'o'){
                sum[i] += w[j + 1];
            }else son[i].push_back(w[j + 1]);
        }
        sort(son[i].begin(), son[i].end(), greater<>());
        q.insert(sum[i]);
    }
    rep(i, 1, n){
        q.erase(q.find(sum[i]));
        int mx = *q.rbegin();
        int now = sum[i], res = 0;
        for(auto x:son[i]){
            if(now <= mx){
                now += x;
                res ++;
            }
        }
        cout << res << endl;
        q.insert(sum[i]);
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