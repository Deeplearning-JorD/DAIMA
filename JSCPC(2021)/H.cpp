/*
 * @Author: JorD
 * @LastEditTime: 2022-12-02 18:19:50
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
typedef unsigned long long ULL;
const int N = 1e5 + 10;
const ULL P = 131;
ULL h[N],p[N],hh[N];
ULL find(int l, int r){
    if(l > r) return 0;
    return h[r]-h[l-1]*p[r-l+1];
}
ULL find1(int l, int r){
    return hh[l] - hh[r + 1] * p[r - l + 1];
}
void Solve(){
    string s;
    cin >> s;
    int n = siz(s);
    string ss = s;
    sort(ss.begin(), ss.end());
    if(s == ss){
        cout << s << endl;
        return;
    }
    int be = 1;
    char c = s[1];
    s = ' ' + s;
    ss = ' ' + ss;
    rep(i, 1, n){
        if(s[i] != ss[i]){
            be = i;
            c = ss[i];
            break;
        }
    }
    rep(i, 1, n){
        h[i] = h[i - 1] * P + s[i] - 'a';
    }
    hh[n + 1] = 0;
    per(i, n, 1){
        hh[i] = hh[i + 1] * P + s[i] - 'a';
    }
    int last = -1;
    auto fff = [&](string s, int l, int r){
        string res = "";
        rep(i, l, r) res += s[i];
        return res;
    };
    rep(i, be, n){
        if(s[i] == c){
            if(last != -1){
                int l = 0, r = n - be + 1;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    ULL L = find1(max(be, i - mid), i);
                    ULL R = find1(max(be, last - mid), last);
                    if(i - mid < be && i != n){
                        L *= p[be - (i - mid)];
                        L += find(i + 1, i + be - (i - mid));
                    }
                    if(last - mid < be&&last != n){
                        R *= p[be - (last - mid)];
                        R += find(last + 1, last + be - (last - mid));
                    }
                    if(L != R) r = mid - 1;
                    else l = mid;
                }
                char L, R;
                if(last - l - 1 < be) L = s[last + be - (last - l - 1)];
                else L = s[last - l - 1];
                if(i - l - 1 < be) R = s[i + be - (i - l - 1)];
                else R = s[i - l - 1];
                if(L > R) last = i;
            }else last = i;
        }
    }
    rep(i, 1, be - 1) cout << s[i];
    per(i, last, be) cout << s[i];
    rep(i, last + 1, n) cout << s[i];
    cout << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    p[0] = 1;
    rep(i, 1, N - 5) p[i]=p[i-1]*P;
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}