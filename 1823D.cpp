/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 02:23:09
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
    cin >> m >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    bool st = false;
    rep(i, 1, n){
        cin >> b[i];
        if(b[i] - b[i - 1] > a[i] - a[i - 1]) st = true; 
    }
    if(st){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << "xyz";
    char c = 'a';
    string res = " xyz";
    int s = -1;
    string mb = "xyz";
    int last = 3, id = 3;
    rep(i, 1, n){
        int now = b[i];
        int kun = s + 1;
        while(id < a[i] - (now - last)){
            id ++;
            cout << mb[kun % 3];
            res += mb[kun % 3];
            s = res[id] - 'x';
            kun ++;
        }
        for(int j = last + 1;j <= now;j ++, id ++){
            cout << c;
            res += c;
        }
        c ++;
        last = now;
    }
    int kun = s + 1;
    while(id < m){
        id ++;
        cout << "xyz"[kun % 3];
        res += "xyz"[kun % 3];
        kun ++;
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}