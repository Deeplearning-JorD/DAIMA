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
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> f(n + 1);
    rep(i, 1, n) f[i] = i;
    function<int(int)> find = [&](int x){
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    };
    int l = 1, r = n;
    while(l < r){
        f[find(l)] = find(r);
        l ++, r --;
    }
    rep(i, 1, n - k){
        f[find(i)] = find(i + k);
    }
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        son[find(i)].push_back(i);
    }
    int res = 0;
    rep(i, 1, n){
        vector<int> cnt(26);
        for(auto x:son[i]){
            cnt[s[x] - 'a'] ++;
        }
        int now = 1e9;
        int sum = accumulate(cnt.begin(), cnt.end(), 0);
        rep(i, 0, 25) now = min(now, sum - cnt[i]);
        res += now;
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