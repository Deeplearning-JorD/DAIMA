/*
 * @Author: JorD
 * @LastEditTime: 2022-12-01 20:42:01
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
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n){
        string s;
        cin >> s;
        if(s.back() == '1'||s.back() == '2') a[i] = 0;
        else a[i] = 1;
    }
    rep(i, 1, n){
        string s;
        cin >> s;
        if(s.back() == '1'||s.back() == '2') b[i] = 0;
        else b[i] = 1;
    }
    if(a[n] == 0||b[n] == 1){
        cout << "NO\n";
        return;
    }
    rep(i, 1, n){
        if(a[i] + b[i] != 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}