/*
 * @Author: JorD
 * @LastEditTime: 2023-01-25 22:38:48
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
    vector<int> odd, even;
    rep(i, 1, n){
        int x; cin >> x;
        if(x & 1) odd.push_back(i);
        else even.push_back(i);
    }
    if(siz(odd) >= 3){
        cout << "YES\n";
        cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << endl;
        return;
    }
    if(siz(odd) >= 1 && siz(even) >= 2){
        cout << "YES\n";
        cout << odd[0] << ' ' << even[0] << ' ' << even[1] << endl;
        return;
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}