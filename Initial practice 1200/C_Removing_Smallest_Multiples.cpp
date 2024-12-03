#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void helper(string s,int n)
{
    bool ip[n+1];
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ip[i+1]=false;
        }
        else ip[i+1]=true;
    }

    int cost[n+1];

    for(int i=0;i<=n;i++){
        cost[i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(ip[j]) break;
            cost[j]=min(cost[j],i);
        }
    }

    long long ans=0;

    for(int i=0;i<=n;i++){
        if(!ip[i])
            ans+=(cost[i]*1LL);
    }

    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        helper(s,n);
    }
    return 0;
} //3:45