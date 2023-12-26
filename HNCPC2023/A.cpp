/*
 * @Author: JorD
 * @LastEditTime: 2023-05-09 19:12:48
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
    if(s.size() == 1){
        cout << "NaN\n";
        return;
    }
    map<int,int> q;
    for(int i = 0;i < s.size();i ++){
        if(!q[s[i]]){
            q[s[i]] = 1;
            if(!i) continue; 
            string b = s.substr(i);
            auto c = b;
            reverse(all(c));
            if(c == b){
                cout << "HE\n";
                return;
            }
        }else{
            string b = s.substr(i);
            auto c = b;
            reverse(all(c));
            if(c == b){
                cout << "HE\n";
                return;
            }else{
                cout << "NaN\n";
                return;
            }
        }
    }
    cout << "HE\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}