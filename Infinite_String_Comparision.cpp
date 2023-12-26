/*
 * @Author: JorD
 * @LastEditTime: 2023-04-29 12:57:40
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
string a, b;
void Solve(){
    int n = a.size(), m = b.size();
    n *= 2; m *= 2;
    vector<int> ne(n + 1), ne1(m + 1);
    a = ' ' + a + a;
    b = ' ' + b + b;
    for(int i = 2,j = 0;i <= n;i ++){
        while(j && a[i] != a[j + 1]) j = ne[j];
        if(a[i] == a[j + 1]) j ++;
        ne[i] = j;
    }
    int x = n - ne[n];
    for(int i = 2,j = 0;i <= m;i ++){
        while(j && b[i] != b[j + 1]) j = ne1[j];
        if(b[i] == b[j + 1]) j ++;
        ne1[i] = j;
    }
    int y = m - ne1[m];
    for(int i = 1;i <= max(2 * x, 2 * y);i ++){
        int l = i, r = i;
        l %= x;
        r %= y;
        if(l == 0) l = x;
        if(r == 0) r = y;
        if(a[l] == b[r]) continue;
        if(a[l] > b[r]){
            cout << ">\n";
            return;
        }
        cout << "<\n";
        return;
    }
    cout << "=\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    while(cin >> a >> b)
    Solve();
    return 0;
}