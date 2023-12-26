/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 16:14:29
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
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> L(n + 2);
    rep(i, 1, n){
        L[i] = L[i - 1] + (s[i] == 'u'); 
    }
    ll val1 = 0, val2 = 0, val3 = 0;
    string s1 = s, s2 = s, s3 = s;
    ll id = 0, mx = 0;
    rep(i, 1, n){
        if(s[i] == 'd'){
            if(1ll * L[i - 1] * (L[n] - L[i])> mx){
                id = i;
                mx = L[i - 1] * (L[n] - L[i]);
            }      
        }
    }
    auto get = [](string &s, int n){
        vector<int> R(n + 2);
        rep(i, 1, n){
            R[i] = R[i - 1] + (s[i] == 'u'); 
        }
        ll res = 0;
        rep(i, 1, n){
            if(s[i] == 'd'){
                res += R[i - 1] * (R[n] - R[i]);
            }
        }
        return res;
    };
    s1[id] = 'a';
    val1 = get(s1, n);
    rep(i, 1, n){
        if(s[i] == 'u'){
            s2[i] = 'a';
            val2 = get(s2, n);
            break;
        }
    }
    per(i, n, 1){
        if(s[i] == 'u'){
            s3[i] = 'a';
            val3 = get(s3, n);
            break;
        }
    }
    if(val1 <= val2 && val1 <= val3){
        rep(i, 1, n) cout << s1[i];
    }else if(val2 <= val3 && val2 <= val1){
        rep(i, 1, n) cout << s2[i];
    }else rep(i, 1, n) cout << s3[i];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}