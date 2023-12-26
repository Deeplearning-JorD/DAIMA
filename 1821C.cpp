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
    set<char> q;
    for(auto x:s){
        q.insert(x);
    }
    auto get = [](string s, char c){
        int ans = 0;
        while(1){
            int last = - 2;
            string now = "";
            for(int i = 0;i < s.size();i ++){
                if(s[i] != c && i - last >= 2){
                    last = i;
                    continue;
                }
                now += s[i];
            }
            if(last == -2) break;
            ans ++;
            s = now;
        }
        return ans;
    };
    int res = siz(s) - 1;
    for(auto x:q){
        res = min(res, get(s, x));
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}