/*
 * @Author: JorD
 * @LastEditTime: 2023-01-05 23:08:31
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
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    set<int> s1, s2;
    rep(i, 1, n){
        s1.insert(i);
        s2.insert(i);
    }
    int idx1 = 1, idx2 = 1;
    vector<int> res1(n + 1), res2(n + 1);
    rep(i, 1, n){
        if(s1.count(a[i])){
            res1[i] = a[i];
            s1.erase(s1.find(a[i]));
        }else{
            if(s2.count(a[i])){
                res2[i] = a[i];
                s2.erase(s2.find(a[i]));
            }else{
                cout << "NO\n";
                return;
            }
        }
    }
    rep(i, 1, n){
        if(res1[i]) continue;
        if(s1.empty() || *s1.begin() > a[i]){
            cout << "NO\n";
            return;
        }
        auto p = s1.upper_bound(a[i]);
        if(p == s1.begin()){
            cout << "NO\n";
            return;
        }
        p = prev(p);
        res1[i] = *p;
        s1.erase(p);
    }
    rep(i, 1, n){
        if(res2[i]) continue;
        if(s2.empty() || *s2.begin() > a[i]){
            cout << "NO\n";
            return;
        }
        auto p = s2.upper_bound(a[i]);
        if(p == s2.begin()){
            cout << "NO\n";
            return;
        }
        p = prev(p);
        res2[i] = *p;
        s2.erase(p);
    }
    rep(i, 1, n){
        if(max(res1[i], res2[i]) == a[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i, 1, n) cout << res1[i] << " \n"[i == n];
    rep(i, 1, n) cout << res2[i] << " \n"[i == n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}