/*
 * @Author: JorD
 * @LastEditTime: 2023-08-27 06:31:35
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(k % 2 == 0){
        sort(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    vector<char> l, r;
    for(int i = 0;i < n;i ++){
        if(i & 1) l.push_back(s[i]);
        else r.push_back(s[i]);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int cl = 0, cr = 0;
    for(int i = 0;i < n;i ++){
        if(i & 1) cout << l[cl ++];
        else cout << r[cr ++];
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