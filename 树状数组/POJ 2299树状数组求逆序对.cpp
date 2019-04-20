#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500005;
int c[maxn],n;//存树状数组,n表示点数
int aa[maxn];//存离散化后的数组

struct node{
    int val,order;
};
node in[maxn];//存原始数据

int lowbit(int x){
    return x&(-x);
}//&位运算，-x是把x取反然后加一

void update(int x,int val){//单点修改
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=val;
    }
}

int getsumm(int x){//求和，区间[1,x]的和
    int temp=0;
    for(int i=x;i;i-=lowbit(i)){
        temp+=c[i];
    }
    return temp;
}

bool cmp(node a,node b){
    return a.val>b.val;
}
//求逆序对
int main(){
    while(scanf("%d",&n)==1&&n){
        for(int i=1;i<=n;i++){
            scanf("%d",&in[i].val);
            in[i].order=i;
        }
        sort(in+1,in+n+1,cmp);
        for(int i=1;i<=n;i++)
            aa[in[i].order]=i;
        memset(c,0,sizeof(c));
        long long ans=0;
        for(int i=1;i<=n;i++){
            update(aa[i],1);
            ans+=getsumm(aa[i])-1;//其本身被多算了一次
        }
        cout<<ans<<endl;
    }
    return 0;
}
