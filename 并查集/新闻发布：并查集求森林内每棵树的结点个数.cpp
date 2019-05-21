//�������������Ǹ���Ŀ......
//����������������ʽ��
//��scanf��printf�ſ��Թ�
#include<iostream>
#include<cstring>
using namespace std;

int father[500006];//�����һ�����
int  ans[500006];
//��Ŵ𰸣�Ҳ�����������Ϊ���ڵ㣬
//���Եõ����ܽ�����

int findroot(int x){
    while(father[x]!=x) x=father[x];
    return x;
}//���Ҹ��ڵ�

void unionroot(int x,int y){
    int fathx=findroot(x);
    int fathy=findroot(y);
    if(fathx!=fathy){
        father[fathx]=fathy;
        ans[fathy]+=ans[fathx];
    }//ע�����+=�������˽�ans����
    return ;
}//������������

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=500000;i++){
        father[i]=i;
        ans[i]=1;
    }//ע��ans�����ʼ��Ϊ1
    for(int i=1;i<=m;i++){
        int t;cin>>t;
        int peri;int temp;
        for(int j=1;j<=t;j++){
            cin>>temp;
            if(j>1) unionroot(peri,temp);
            peri=temp;
        }//�������ݴ���
    }
    for(int i=1;i<=n;i++){
        cout<<ans[findroot(i)]<<" ";
    }//�����������ܽ�����
    return 0;
}
