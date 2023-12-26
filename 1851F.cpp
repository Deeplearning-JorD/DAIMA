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
    int n, k; cin >> n >> k;
    vector<vector<bool>> son(k, vector<bool> (n + 1));
    vector<vector<bool>> zson(k, vector<bool> (n + 1));
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, k - 1){
        rep(j, 1, n){
            if(a[j] >> i & 1) zson[i][j] = 1;
            else son[i][j] = 1;
        }
    }
    ll mx = 0, resl = 1, resr = 2;
    vector<int> ls;
    rep(i, 1, n) ls.push_back(i);
    function<void(int,ll)> dfs = [&](int dep, ll sum){
        // cout << dep << ' ' << sum << endl;
        if(sum > mx){
            int cnt = 0;
            for(auto x:ls){
                cnt ++;
                if(cnt == 1) resl = x;
                else{
                    resr = x;
                    break;
                }
            }
            mx = sum;
        }
        if(dep < 0) return;
        vector<int> l, r;
        for(auto x : ls){
            if(son[dep][x]) l.push_back(x);
            if(zson[dep][x]) r.push_back(x);
        }
        bool st = false;
        if(l.size() >= 2){
            st = true;
            swap(l, ls);
            dfs(dep - 1, sum | (1 << dep));
            swap(l, ls);
        }
        if(r.size() >= 2){
            st = true;
            swap(r, ls);
            dfs(dep - 1, sum | (1 << dep));
            swap(r, ls);
        }
        if(st) return;
        dfs(dep - 1, sum);
    };
    dfs(k - 1, 0);
    int res = 0;
    for(int i = 0;i < k;i ++){
        int L = a[resl] >> i & 1;
        int R = a[resr] >> i & 1;
        if(L == R){
            if(!L) res |= 1 << i;
        }
    }
    // cout << mx << endl;
    cout << resl << ' ' << resr << ' ' << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}