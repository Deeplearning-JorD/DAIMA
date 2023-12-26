/*
 * @Author: JorD
 * @LastEditTime: 2023-07-09 20:15:06
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
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
    vector<int> cnt(10);
    rep(i, 1, n){
        int x; cin >> x;
        cnt[x] ++;
    }
    vector<int> v;
    int mb = 0;
    rep(T, 1, 2){
        vector<int> ls(10);
        cout << "- 0" << endl;
        vector<int> a(n + 1);
        rep(i, 1, n){
            int x; cin >> x;
            ls[x] ++;
            a[i] = x;
        }
        if(ls == cnt) continue;
        rep(i, 1, 9)if(ls[i] > cnt[i]){
            mb = i;
            break;
        }
        rep(i, 1, n)if(a[i] != mb){
            v.push_back(i);
        }
        break;
    }
    n -= siz(v);
    cout << "- " << siz(v);
    for(auto x:v){
        cout << " " << x;
    }cout << endl;
    int res = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(x != mb){
            res = i;
        }
    }
    if(res == 0){
        cout << "- 0" << endl;
        rep(i, 1, n){
            int x; cin >> x;
            if(x != mb){
                res = i;
            }
        }
    }
    cout << "! " << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}