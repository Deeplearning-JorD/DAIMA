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
    int k, c, n; cin >> k >> c >> n;
    int res = 0;
    for(int i = 1;i <= c / i;i ++){
        if(c % i) continue;
        if((c - i) % k == 0){
            if(__gcd((c - i) / k, i) >= n && c != i){
                res ++;
            }
        }if(i == c / i) continue;
        i = c / i;
        if((c - i) % k == 0){
            if(__gcd((c - i) / k, i) >= n && c != i){
                res ++;
            }
        }
        i = c / i;
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