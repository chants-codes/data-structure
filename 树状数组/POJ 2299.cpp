#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500005;
int c[maxn],n;//����״����,n��ʾ����
int aa[maxn];//����ɢ���������

struct node{
    int val,order;
};
node in[maxn];//��ԭʼ����

int lowbit(int x){
    return x&(-x);
}//&λ���㣬-x�ǰ�xȡ��Ȼ���һ

void update(int x,int val){//�����޸�
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=val;
    }
}

int getsumm(int x){//��ͣ�����[1,x]�ĺ�
    int temp=0;
    for(int i=x;i;i-=lowbit(i)){
        temp+=c[i];
    }
    return temp;
}

bool cmp(node a,node b){
    return a.val>b.val;
}
//�������
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
            ans+=getsumm(aa[i])-1;//�䱾��������һ��
        }
        cout<<ans<<endl;
    }
    return 0;
}