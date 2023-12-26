/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 16:01:17
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    if(vector<int> (n, m) == a){
        cout << 0 << endl;
        return;
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum == m * n){
        cout << 1 << endl;
        return;
    }
    for(auto x:a){
        if(x == m){
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}