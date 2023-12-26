/*
 * @Author: JorD
 * @Date: 2023-10-26 13:45:11
 * @LastEditTime: 2023-10-26 16:11:40
 * how to Get
 */
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
const int N = 6e6 + 10;
const double Pi = acos(-1);
complex<double> f[N], g[N];
// 递归FFT
// void fft(complex<double> *a, int m, int op){
//     if(m == 1) return;
//     complex<double> a1[m >> 1], a2[m >> 1];
//     rep(i, 0, m / 2 - 1){
//         a1[i] = a[2 * i];
//         a2[i] = a[2 * i + 1];
//     }
//     fft(a1, m / 2, op); fft(a2, m / 2, op);
//     complex<double> Wn(cos(2.0 * Pi / m), op * sin(2.0 * Pi / m)), w(1, 0);
//     for(int i = 0;i < m / 2;i ++){
//         a[i] = a1[i] + w * a2[i];
//         a[i + m / 2] = a1[i] - w * a2[i];
//         w *= Wn;
//     }
// }
void change(complex<double> *a, int len){
    for(int i = 1, j = len / 2;i < len - 1;i ++){
        if(i < j) swap(a[i], a[j]);
        int b = len / 2;
        while(j >= b){
            j -= b;
            b >>= 1;
        }
        j += b;
    }
}
void fft(complex<double> *a, int m, int op){
    change(a, m);
    for(int mid = 1;mid < m;mid <<= 1){ // 子区间长度
        complex<double> Wn(cos(Pi / mid), op * sin(Pi / mid));
        for(int L = mid << 1, j = 0;j < m;j += L){
            complex<double> w(1, 0);
            for(int k = 0;k < mid;k ++, w *= Wn){
                complex<double> x = a[j + k] + w * a[j + k + mid], y = a[j + k] - w * a[j + k + mid];
                a[j + k] = x;
                a[j + k + mid] = y;
            }
        }
    }
}
int ci(){int x; cin >> x;return x;}
void Solve(){
    int n, m; cin >> n >> m;
    rep(i, 0, n) f[i].real(ci());
    rep(i, 0, m) g[i].real(ci());
    int tot = 1;
    while(tot <= n + m) tot <<= 1;
    // change(f, tot); change(g, tot);
    fft(f, tot, 1); fft(g, tot, 1);
    rep(i, 0, tot) f[i] *= g[i];
    // change(f, tot);
    fft(f, tot, -1);
    rep(i, 0, n + m) cout << (int)round((f[i].real()/tot)) << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}