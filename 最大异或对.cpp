/*
 * @Author: JorD
 * @LastEditTime: 2023-01-25 22:01:10
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
const int N = 1e5 * 30 + 10;
int tr[N][2];
int idx;
void add(int x){
    int p = 0;
    for(int i = 30;i >= 0;i --){
        int c = x >> i & 1;
        if(!tr[p][c]) tr[p][c] = ++ idx; 
        p = tr[p][c];
    }
}
int find(int x){
    int res = 0, p = 0;
    for(int i = 30;i >= 0;i --){
        int c = x >> i & 1;
        if(tr[p][!c]){
            res += 1 << i;
            p = tr[p][!c];
        }else p = tr[p][c];
    }
    return res;
}
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        add(a[i]);
    }
    int res = 0;
    rep(i, 1, n) res = max(res, find(a[i]));
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}