/*
 * @Author: JorD
 * @LastEditTime: 2023-07-28 12:53:55
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
    vector<int> a(n + 1);
    map<int,int>st;
    rep(i, 1, n){
        cin >> a[i];
        st[a[i]] = i;
    }
    sort(a.begin() + 1, a.end());
    int l = 1, r = n;
    while(l < r){
        int L = l, R = r;
        int now = a[l] + a[r] >> 1;
        while(L < R){
            int mid = L + R + 1 >> 1;
            if(a[mid] <= now) L = mid;
            else R = mid - 1;
        }
        if(L - l + 1 >= r - L){
            r --;
        }else l ++;
    }
    cout << st[a[l]] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}