#include<iostream>
#include<cstdio>
#define int long long
#define MN 50
using namespace std;
int n;
int p[MN+10];
int tmp[MN+10];
bool zero;
void insert(int x)
{
    for(int i=MN;i>=0;i--)
        if(x&(1ll<<i))
            if(!p[i])
            {
                p[i]=x;
                return;
            }
            else
                x^=p[i];
    zero=1;
}
int query_min()
{
    if(zero)
        return 0;
    int res=0;
    for(int i=0;i<=MN;i++)
        if(p[i])
            return p[i];
}
int query_max()
{
    int res=0;
    for(int i=MN;i>=0;i--)
        res=max(res,res^p[i]);
    return res;
}
void rebuild()
{
    int res=0,cnt=0;
    for(int i=0;i<=MN;i++)
    {
        for(int j=i-1;j>=0;j--)
            if(p[i]&(1ll<<j))
                p[i]^=p[j];
        if(p[i])
            tmp[cnt++]=p[i];
    }
}
int query_kth(int k)
{
    int res=0,cnt=0;
    k-=zero;
    if(!k)
        return 0;
    if(k>=(1ll<<cnt))
        return -1;
    for(int i=0;i<cnt;i++)
        if(k&(1ll<<i))
            res^=tmp[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    cout<<query_max()<<endl;
    return 0;
}