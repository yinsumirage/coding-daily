#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
const int N = 1e6 + 5;

signed main() {
    ull t,n;
    cin>>t;
    while(t--){
        cin>>n;
        stack<ull>sk;
        while(n--){
            string c;
            cin>>c;
            if(c=="push"){
                ull x;
                cin>>x;
                sk.push(x);
            }
            else if(c=="pop"){
                if(sk.empty())cout<<"Empty\n";
                else sk.pop();
            }
            else if(c=="query"){
                if(sk.empty())cout<<"Anguei!\n";
                else cout<<sk.top()<<'\n';
            }
            else cout<<sk.size()<<'\n';
        }
    }
    system("pause");
}