#pragma GCC optimize(2)
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
const int N = 1e7 + 10, P = 131;
using ull = unsigned long long;
ull h[N], p[N];
ull find(int l, int r){
    if(l == 0) return h[r];
    return h[r] - h[l - 1] * p[r - l + 1];
}
void Solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    for(int i = 0;i < s1.size();i ++){
        if(i == 0) h[i] = s1[i] - 'a';
        else h[i] = h[i - 1] * P + (s1[i] - 'a');
    }
    ull din = 0;
    for(int i = 0;i < s2.size();i ++){
        if(i == 0) din = s2[i] - 'a';
        else din = din * P + (s2[i] - 'a');
    }
    unordered_map<ull, ll> st;
    ull gu = p[n2];
    for(int i = 0;i < s1.size();i ++){
        ull now = (h[i] * gu + din) * p[n1 - i - 1] + find(i + 1, n1 - 1);
        st[now] ++; 
    }
    ull ls = din * p[n1] + h[n1 - 1];
    st[ls] ++;
    string s;
    cin >> s;
    int n = s.size();
    ll res = 0;
    for(int i = 0;i < n;i ++){
        if(i == 0) h[i] = s[i] - 'a';
        else h[i] = h[i - 1] * P + (s[i] - 'a');
    }
    for(int i = 0;i < n;i ++){
        if(i + n1 + n2 - 1 == n) break;
        res += st[find(i, i + n1 + n2 - 1)];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    p[0] = 1;
    for(int i = 1;i <= 1e7;i ++) p[i] = p[i - 1] * P;
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}