/*
 * @Author: JorD
 * @LastEditTime: 2022-09-29 14:55:02
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int mod = 998244353;
void Solve(){
    int n, s;
    cin >> n >> s;
    vector<int> num(n + 1), st(n + 1);
    rep(i, 1, n) cin >> num[i];
    vector<int> sum, mid;
    int idx = 0;
    ll res = 1;
    rep(i, 1, n){
        int x;
        cin >> x;
        if(x == -1){
            sum.push_back(num[i]);
            idx ++;
        }else{
            st[x] = 1;
            if(num[i] - x > s) res = 0;
        }
    }
    rep(i, 1, n) if(!st[i]) mid.push_back(i);
    sort(mid.begin(), mid.end());
    sort(sum.begin(), sum.end());
    ll cnt = 0;
    per(i, idx - 1, 0){
        while(mid.size()&&sum[i] - mid.back() <= s) mid.pop_back(), cnt  ++;
        res = res * cnt % mod;
        cnt --;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}