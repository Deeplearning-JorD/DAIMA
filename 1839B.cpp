/*
 * @Author: JorD
 * @LastEditTime: 2023-06-04 12:38:57
 */
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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    queue<int> q;
    ll tot = 0, res = 0, c = 0, k = 0;
    for(int i = 0;i < n;i ++){
        auto [x, y] = a[i];
        if(x <= k) continue;
        q.push(i);
        res += y;
        tot ++;
        int now = tot - c;
        while(q.size()){
            auto t = q.front();
            if(a[t].first <= now){
                k = a[t].first;
                c ++;
                q.pop();
            }else break;
        }
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