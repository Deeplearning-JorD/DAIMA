/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 17:20:15
 * how to Get
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e6 + 10, mod = 1e9 + 7, P = 131;
using ull = unsigned long long;
ull h[N], p[N];
ull find(int l, int r){
    return h[r] - h[l] * p[r - l];
}
ll pre[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    if(k == 0){
        cout << s;
        return 0;
    }
    s = ' ' + s;
    p[0] = 1;
    for(int i = 1;i <= n;i ++){
        h[i] = h[i - 1] * P + s[i] - '0';
        p[i] = p[i - 1] * P;
        pre[i] = pre[i - 1] + s[i] - '0';
    }
    int j = 1;
    for(int i = 2;i <= k + 1;i ++){
        if(s[i] != s[j]){
            if(s[i] > s[j]) j = i;
            continue;
        }
        int l = 0, r = n - k - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(find(j, j + mid) == find(i, i + mid)) l = mid;
            else r = mid - 1;
        }
        if(i + l + 1 > n) continue;
        if(s[i + l + 1] > s[j + l + 1]) j = i;
    }
    vector<int> ls;
    for(int i = j;i < j + n - k;i ++){
        ls.push_back((int)(s[i] - '0'));
    }
    ls[n - k - 1] += pre[j - 1] - pre[0] + pre[n] - pre[j + n - k - 1];
    int t = 0;
    reverse(ls.begin(), ls.end());
    for(auto &x:ls){
        x += t;
        t = x / 10;
        x %= 10;
    }   
    reverse(ls.begin(), ls.end());  
    if(t) cout << t;
    for(auto x:ls) cout << x;
    return 0;
}