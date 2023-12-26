/*
 * @Author: JorD
 * @LastEditTime: 2023-03-20 01:02:03
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
const int N = 2e5 + 10;
ll a[N];
void Solve(){   
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll sum = 1;
    if(a[1] > 1){
        cout << "NO\n";
        return;
    }
    for(int i = 2;i <= n;i ++){
        if(sum < a[i]){
            cout << "NO\n";
            return;
        }
        sum += a[i];
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}