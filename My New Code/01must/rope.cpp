#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;

rope<int> r;
 //r.push_back(x);      在r的末尾添加元素x
//r.insert(pos,x);      在r的pos个位置添加元素x
//r.erase(pos,x);       在r的pos个位置删除x个元素
//r.at(x)或r[x];        访问r的第x个元素
//r.length()或r.size(); 获取r的大小
//r.copy(pos,len,x);    从pos开始到pos+len为止用x代替
//r.replace(pos,x)      从pos开始替换成x
//r.substr(pos,x)       提取从pos开始x个元素
void get(int &a){
    a=0;
    char b=getchar();
    while(b>'9'||b<'0')b=getchar();
    while(b<='9'&&b>='0'){
        a=10*a+b-'0';
        b=getchar();
    }
    return;
}

int main(){
    int M,N,d,op,k,x;
    get(M);get(N);
    while(M--){
        get(d);
        r.push_back(d);
    }
    while(N--){
        get(op);get(k);
        if(op==1){
            get(x);
            r.insert(k-1,x);
        }
        else if(op==2){
            r.erase(k-1,1);
        }
        else if(op==3){
            printf("%d\n",r[k-1]);
        }
    }
    return 0;
}

