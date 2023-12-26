/*
 * @Author: JorD
 * @Date: 2023-11-29 23:51:15
 * @LastEditTime: 2023-11-30 13:19:58
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
int get(int x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt ++;
    }
    return cnt;
}
void Solve(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << n / 2 << ' ' << n / 2 << endl;
        return;
    }else if(n <= 10){
        cout << n / 2 << ' ' << n / 2 + 1 << endl;
        return;
    }else{
        ll p = 1, l = n / 2 + 1, r = n / 2;
        int z = 0, y = 0;
        vector<int> a(11), b(11);
        int j = 0;
        while(l){
            a[j ++] = l % 10;
            z += l % 10;
            l /= 10; 
        }
        j = 0;
        while(r){
            b[j ++] = r % 10;
            y += r % 10;
            r /= 10; 
        }
        int need = 1;
        for(int i = 0;i <= 10;i ++, p *= 10){
            if(a[i] == b[i] + 1) break;
            int x = b[i];
            a[i] = x / 2;
            b[i] = x / 2;
            if(x & 1){
                if(need){
                    b[i] ++;
                    need --;
                }else{
                    a[i] ++;
                    need ++;
                }
            }
        }       
        while(a.back() == 0 && a.size() > 1) a.pop_back();
        while(b.back() == 0 && b.size() > 1) b.pop_back();
        reverse(a.begin(), a.end());reverse(b.begin(), b.end());
        for(auto x:a) cout << x;
        cout << ' ';
        for(auto x:b) cout << x;
        cout << endl;
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