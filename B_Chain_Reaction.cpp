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
    vector<int> dp(n + 1, 1e9);
    //dp[i]表示从右到左被摧毁的防御塔的最少数量
    vector<pair<int,int>> a(n + 1);
    rep(i, 1, n){
        int x, y; cin >> x >> y;
        a[i] = {x, y};    
    }
    sort(a.begin() + 1, a.end(), [](pair<int,int> x, pair<int,int> y){
        return x.first < y.first;        
    });
    for(int i = 1;i <= n;i ++){
        dp[i] = n - i;
    }
    for(int i = n;i >= 1;i --){
        int l = 0, r = i - 1;
        int c = a[i].first - a[i].second;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid].first < c) l = mid;
            else r = mid - 1;
        }  
        dp[l] = min(dp[l], dp[i] + i - l - 1);
    }
    int res = n;
    for(int i = 1;i <= n;i ++){
        res = min(res, dp[i] + i - 1);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}