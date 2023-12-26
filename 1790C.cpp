/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 00:47:26
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
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    vector<string> s(n + 1);
    rep(i, 1, n){
        set<int> s;
        rep(j, 1, n) s.insert(j);
        rep(j, 2, n){
            int x; cin >> x;
            s.erase(x);
            a[i][j] = x;
        }
        a[i][1] = *s.begin();
    }
    vector<int> f(n + 2);
    int idx = 1, id;
    int ji = 2;
    int l = 1, r = 2;
    bool ff = false;
    for(int i = 2;i <= n;i ++){
        if(i == l) continue;
        int cnt = 0;
        for(int j = 2;j <= n;j ++){
            if(a[i][j] != a[l][j]) cnt ++;
        }
        if(cnt == 1){
            r = i;
            ff = true;
            break;
        }
    }
    if(!ff){
    l = 2;
    for(int i = 1;i <= n;i ++){
        if(i == l) continue;
        int cnt = 0;
        for(int j = 2;j <= n;j ++){
            if(a[i][j] != a[l][j]) cnt ++;
        }
        if(cnt == 1){
            r = i;
            ff = true;
            break;
        }
    }}
    for(int i = 2;i <= n;i ++){
        if(a[l][i] == a[r][i]){
            f[idx ++] = a[l][i];
        }else{
            id = idx;
            // cout << idx << ' ' << i << ' ' << a[1][i] << ' ' << a[2][i] << "?" << endl;
            f[idx ++] = a[l][i];
            f[idx ++] = a[r][i];
        }
        // cout << idx << endl;
    }
    
    // rep(i, 1, n) cout << f[i] << ' ';
    bool st = true;
    rep(i, 1, n){
        idx = 1;
        vector<int> ls(n + 2);
        int cnt = 2;
        rep(j, 1, n){
            if(a[i][1] == f[j]) continue;
            ls[cnt ++] = f[j];
        }
        rep(j, 2, n){
            // cout << ls[j] << ' ';
            if(a[i][j] != ls[j]) st = false;
        }
    }
    // DBG(st);
    if(!st){
    //  rep(i, 1, n) cout << f[i/
    // cout << id << 
        swap(f[id], f[id + 1]);
    }
    rep(i, 1, n) cout << f[i] << ' ';
    cout << "\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}