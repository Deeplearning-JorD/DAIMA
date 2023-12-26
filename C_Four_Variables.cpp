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
ll f[N];
int judge(int x){
    int js = 0;
    for(int i = 1;i <= x / i;i ++){
        if(x % i == 0){
            js ++;
            if(i != x / i) js ++;
        }
    }
    return js;
}
void Solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) f[i] = judge(i);
    ll res = 0;
    for(int i = 1;i <= n / 2;i ++){
        res += f[i] * f[n - i];
        if(i != n - i) res += f[i] * f[n - i]; 
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