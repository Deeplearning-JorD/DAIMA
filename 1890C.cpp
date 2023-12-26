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
void Solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    int p = 0, l = 0, r = n - 1;
    int i1 = 0, i2 = 0;
    deque<char> z, y;
    vector<int> res;
    while(i1 < n - 1 + 2 * p - i2 && p <= 300){
        char L, R;
        if(z.size()){
            L = z.back();
        }else{
            if(l < r) L = s[l];
            else L = *y.begin();
        }
        if(y.size()){
            R = y.back();
        }else{
            if(l < r) R = s[r];
            else R = *z.begin();
        }
        if(L == R){
            if(L == '0'){
                res.push_back(n + 2 * p - i2);
                y.push_back('0');
                if(z.size()) z.pop_back();
                else{
                    if(l < r) l ++;
                    else y.pop_front();
                }
            }else{
                res.push_back(i1);
                z.push_back('1');
                if(y.size()) y.pop_back();
                else{
                    if(l < r) r --;
                    else z.pop_front();
                }
            }
            p ++;
        }else{
            if(z.size()) z.pop_back();
            else{
                if(l < r) l ++;
                else y.pop_front();
            }
            if(y.size()) y.pop_back();
            else{
                if(l < r) r --;
                else z.pop_front();
            }
        }
        i1 ++, i2 ++;
    }   
    if(p > 300){
        cout << -1 << endl;
        return;
    }
    cout << res.size() << endl;
    for(auto x:res) cout << x << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}