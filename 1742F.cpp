#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    ll lena = 1, lenb = 1;
    vector<ll> a(26), b(26);
    a[0] = b[0] = 1;
    rep(i, 1, n){
        ll op, k;
        string s;
        cin >> op >> k >> s;
        if(op == 1){
            lena += k * siz(s);
            for(auto x:s){
                a[x - 'a'] += k;
            }
        }else{
            lenb += k * siz(s);
            for(auto x:s){
                b[x - 'a'] += k;
            }
        }
        ll suma = 0, sumb = 0;
        for(int j = 1;j < 26;j ++){
            sumb += b[j];
            suma += a[j];
        }
        if(sumb){
            cout << "YES\n";
            continue;
        }
        if(suma){
            cout << "NO\n";
            continue;
        }
        if(lena - suma < lenb - sumb){
            cout << "YES\n";
        }else cout << "NO\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}