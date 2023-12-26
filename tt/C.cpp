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
int w[5][5];
void Solve(){
    int n, na, nb;
    cin >> n >> na >> nb;
    int resa = 0, resb = 0;
    vector<int> a(na), b(nb);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    for(int i = 0;i < n;i ++){
        resa += w[a[i%na]][b[i%nb]];
        resb += w[b[i%nb]][a[i%na]];
    }
    cout << resa << ' ' << resb << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    w[0][2] = 1;
    w[0][3] = 1;
    w[1][3] = 1;
    w[2][4] = 1;
    w[3][4] = 1;
    w[1][0] = 1;
    w[2][1] = 1;
    w[3][2] = 1;
    w[4][0] = 1;
    w[4][1] = 1;
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}