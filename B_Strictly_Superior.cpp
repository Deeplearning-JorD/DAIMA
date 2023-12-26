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
struct node{
    int p, n;
};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> st(n + 1, vector<int> (m + 1));
    vector<node> a(n + 1);
    rep(i, 1, n){
        int p, k; cin >> p >> k;
        a[i].p = p;
        a[i].n = k;
        rep(j, 1, k){
            int x; cin >> x;
            st[i][x] = 1;
        }
    }
    rep(i, 1, n){
        rep(j, 1, n)if(i != j && a[i].p >= a[j].p){
            int l = 0, r = 0;
            rep(k, 0, m){
                if(!st[i][k] && st[j][k]){
                    r = 1;
                }
                if(st[i][k] && !st[j][k]){
                    l = 1;
                }
            } 
            if(l == 1) continue;
            if(a[i].p > a[j].p || r){
                cout << "Yes";
                return;
            }
            continue;
        }
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}