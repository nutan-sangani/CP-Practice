#include <iostream>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void helper()
{
    
}

int main()
{
    int n,q;
    cin>>n;
    cin>>q;
    // cout<<n;
    unordered_map<int,int> map;
    ll sum=0;
    int time[n+1];
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        sum+=(ll)val;
        map[i+1]=val;
        time[i+1]=0;
    }
    int i=0;
    int lastTime=-1;
    int prev=-1;
    while(i<q){
        int t;
        cin>>t;
        if(t==1){
            ll j,x;
            cin>>j>>x;
            if(time[j]<=lastTime){
                map[j]=x;
                sum-=(ll)prev*1LL;
                sum+=(ll)x*1LL;
                time[j]=i;
            }
            else{
                sum-=(ll)map[j]*1LL;
                sum+=(ll)x*1LL;
                time[j]=i;
                map[j]=x;
            }
            cout<<sum<<endl;
        }
        else{
            ll x;
            cin>>x;
            lastTime=i;
            prev=x;
            sum=(ll)(x*n*1LL);
            cout<<sum<<endl;
        }
        i++;
    }
    return 0;
}