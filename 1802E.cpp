/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 00:42:02
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
void Solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    a[0].push_back(0);
    for(int i = 1;i <= n;i ++){
        int k; cin >> k;
        int last = 0;
        for(int j = 0;j < k;j ++){
            int x; cin >> x;
            if(x > last){
                last = x;
                a[i].push_back(x);
            }
        }
    }
    sort(a.begin() + 1, a.end(), [](vector<int> &x, vector<int> &y){
        return x.back() < y.back();
    });
    int res = 0;
    map<int,int> dp;
    dp[0] = 0;
    for(int i = 1;i <= n;i ++){
        int len = a[i].size(), idx = 0, last = a[i].back();
        for(auto now:a[i]){
            int l = 0, r = i - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(a[mid].back() < now) l = mid;
                else r = mid - 1;
            }
            dp[last] = max(dp[last], dp[a[l].back()] + len - idx);
            idx ++;
        }
    }
    cout << dp[a[n].back()] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}