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
    int n, k;
    cin >> n >> k;
    int s = n * (n + 1) / 2 - k;
    int sum = 0, js = 0;
    for(int i = 0;i <= n;i ++){
        sum += i;
        if(s >= sum) js = i;
        else{
            sum -= i;
            break;
        }
    }
    s -= sum;
    vector<int> res(n + 1);
    for(int i = n, j = 1;i >= 1;j ++, i --){
        if(j <= js) res[i] = -2;
        else res[i] = 1000;
    }
    res[n - js] = ((n - s + 1) - (n - js) - 1) * 2 + 1;
    rep(i, 1, n) cout << res[i] << ' ';
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