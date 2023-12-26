/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 03:14:57
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
    int n;
    cin >> n;
    set<int> s;
    vector<int> a(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        s.insert(x);
        a[i] = x;
    }
    sort(all1(a));
    int res = 0;
    for(auto x:s){
        for(int i = x;i <= 2 * a[n];i += x){
            int l = 1, r = n;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(a[mid] < i) l = mid;
                else r = mid - 1;
            }
            if(a[l] > x)
            res = max(res, a[l] % x);
        }
    }
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