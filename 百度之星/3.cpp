/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 18:38:10
 * how to Get
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define pii pair<int,int>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1), v(n + 1), id(n + 1);
    map<int,int> q,st,qq;
    int he = 0;
    for(int i = 1;i <= n;i ++){
        int x, y; cin >> x >> y;
        st[x] += y;
        if(st[x] == 0) st.erase(x);
        s[i] = x; v[i] = y;
        he += y;
    }
    ll sum = 0, c = 0, last = 0;
    vector<ll> a, b, t;
    for(auto [x, y]:st){
        sum += (x - last) * c;
        c += y;
        t.push_back(x);
        a.push_back(sum);
        b.push_back(c);
        last = x;
    }
    int n1 = a.size();
    auto calc = [&](int i, ll mi){
        int l = 0, r = n1 - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(t[mid] <= mi) l = mid;
            else r = mid - 1;
        }
        ll tot = a[r] + 1ll * (mi - t[r]) * b[r];
        if(mi > s[i]) tot -= 1ll * (mi - s[i]) * v[i];
        return tot;
    };
    ll res = -1;
    for(int i = 1;i <= n;i ++){
        if(he - v[i] == 0){
            cout << -1;
            return 0;
        }
        ll l = 0, r = 1e10;
        while(l < r){
            ll mid = l + r >> 1;
            if(m <= calc(i, mid)) r = mid;
            else l = mid + 1;
        }
        res = max(res, r);
    }
    cout << res;
    return 0;
}