#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
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
int n;
void Solve(){
    vector<vector<int>> son(10);
    for(int i = 1;i <= n;i ++){
        int x; cin >> x;
        son[x % 9].push_back(x);
    }
    ll res = 0;
    for(int i = 1;i < 9;i ++){
        ll sum = accumulate(son[i].begin(), son[i].end(), 0ll);
        ll len = son[i].size();
        ll cnt = len * (len - 1) * 9 / 2 + len * i;
        sum -= cnt;
        res += sum;
    }
    ll sum = accumulate(son[0].begin(), son[0].end(), 0ll);
    ll len = son[0].size();
    ll cnt = len * (len - 1) * 9 / 2 + len * 9;
    sum -= cnt;
    res += sum;
    if(res & 1) cout << "A\n";
    else cout << "B\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    while(cin >> n)
    Solve();
    return 0;
}