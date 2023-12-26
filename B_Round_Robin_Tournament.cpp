/*
 * @Author: JorD
 * @LastEditTime: 2023-10-07 20:08:11
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
    int n; cin >> n;
    vector<int> id(n + 1), a(n + 1);
    rep(i, 1, n){
        string s; cin >> s;
        id[i] = i;
        for(auto x:s) a[i] += x == 'o';
    }
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        if(a[i] == a[j]) return i < j;
        return a[i] > a[j];
    });
    rep(i, 1, n) cout << id[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}