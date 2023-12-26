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
const int N = 4e6 + 10;
const double Pi = acos(-1);
complex<double> f[N], g[N];
void change(complex<double> *a, int m){
    for(int i = 1, j = m / 2;i < m - 1;i ++){
        if(i < j) swap(a[i], a[j]);
        int k = m / 2;
        while(j >= k){
            j -= k;
            k >>= 1;
        }
        j += k;
    }
}
void fft(complex<double> *a, int m, int op){
    change(a, m);
    for(int mid = 1;mid < m;mid <<= 1){
        complex<double> Wn(cos(Pi / mid), op * sin(Pi / mid));
        for(int R = mid << 1, j = 0;j < m;j += R){
            complex<double> w(1, 0);
            for(int i = 0;i < mid;i ++, w *= Wn){
                complex<double> x = a[j + i] + w * a[j + i + mid], y = a[j + i] - w * a[j + i + mid];
                a[j + i] = x;
                a[j + i + mid] = y;
            }
        }
    }
}
void Solve(){
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    n --, m --;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    rep(i, 0, n) f[i].real((int)s[i] - 48);
    rep(i, 0, m) g[i].real((int)t[i] - 48);
    int tot = 1;
    while(tot <= n + m) tot <<= 1;
    fft(f, tot, 1); fft(g, tot, 1);
    rep(i, 0, tot) f[i] *= g[i];
    fft(f, tot, -1);
    int T = 0;
    vector<int> res;
    for(int i = 0;i <= n + m || T;i ++){
        T += f[i].real()/tot + 0.01;
        res.push_back(T%10);
        T /= 10; 
    }
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    while(res.size()){
        cout << res.back();
        res.pop_back();
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}