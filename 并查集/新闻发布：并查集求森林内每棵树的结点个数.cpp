//这个代码过不了那个题目......
//必须更改输入输出方式，
//用scanf和printf才可以过
#include<iostream>
#include<cstring>
using namespace std;

int father[500006];//存放上一个结点
int  ans[500006];
//存放答案，也就是以这个点为根节点，
//可以得到的总结点个数

int findroot(int x){
    while(father[x]!=x) x=father[x];
    return x;
}//查找根节点

void unionroot(int x,int y){
    int fathx=findroot(x);
    int fathy=findroot(y);
    if(fathx!=fathy){
        father[fathx]=fathy;
        ans[fathy]+=ans[fathx];
    }//注意这个+=，深入了解ans数组
    return ;
}//连接两个集合

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=500000;i++){
        father[i]=i;
        ans[i]=1;
    }//注意ans数组初始化为1
    for(int i=1;i<=m;i++){
        int t;cin>>t;
        int peri;int temp;
        for(int j=1;j<=t;j++){
            cin>>temp;
            if(j>1) unionroot(peri,temp);
            peri=temp;
        }//输入数据处理
    }
    for(int i=1;i<=n;i++){
        cout<<ans[findroot(i)]<<" ";
    }//输出这棵树的总结点个数
    return 0;
}
