#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int mi = *min_element(a.begin() + 1, a.end());
    for(int i = 1;i <= n;i ++){w
        if(a[i] == mi){
            auto b = a;
            sort(b.begin() + i, b.end());
            if(a == b){
                cout << i - 1 << endl;
                return;
            }else{
                cout << -1 << endl;
                return;
            }
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}