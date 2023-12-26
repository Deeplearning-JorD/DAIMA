/*
 * @Author: JorD
 * @LastEditTime: 2022-10-26 15:57:09
 */
#include<iostream>
using namespace std;
int main(){
    int n,m,p=0;
    cin >> n;
   
    while (n--){
        cin >> m;
        p = 0;
        for (int i=1;i<=m/i;i++){
            
            if (m%i==0){   
                p+=i+m/i;
            }
        }
        p-=m;
        if (m == 1) p-= 1;
        if (p==m)  cout << m <<" is perfect"<<endl;
        else cout << m <<" is not perfect"<<endl;
        
    }
    return 0;
}
