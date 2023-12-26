/*
 * @Author: JorD
 * @LastEditTime: 2022-08-12 14:33:37
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    string s;
    cin>> s;
    s='d'+s+'d';
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='?'){
            for(char c='a';c<='c';c++){
                if(s[i+1]==c||s[i-1]==c) continue;
                s[i]=c;
            }
        }
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]||s[i]=='?'){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<s.size()-1;i++) cout<<s[i];
    cout<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}