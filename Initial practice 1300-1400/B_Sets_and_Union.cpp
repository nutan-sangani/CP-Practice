#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vecll &og,int n,map<ll,vecll>& setWhichHave)
{
    ll maxCount=0;
    for(int i=1;i<=50;i++){
        vecll copy(og);
        vecll nodes = setWhichHave[i];
        for(int j=0;j<nodes.size();j++){
            // cout<<nodes[j]<<" "<<copy[nodes[j]]<<endl;
            // cout<<copy[nodes[j]]<<" ";
            copy[nodes[j]]=0;
        }
        ll result=copy[0];
        for(int j=1;j<n;j++){
            result = (result | copy[j]);
        }
        int count=0;
        for(int j=0;j<55;j++){
            ll z=1;
            if(z<<j & result){
                count++;
            }
        }
        if(count>maxCount && setWhichHave[i].size()>0){
            maxCount=count;
        }
    }
    cout<<maxCount<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll og(n);
        map<ll,vecll> setWhichHave;
        forLoop
        {
            ll count;
            cin>>count;
            ll a=0;
            for(int j=0;j<count;j++){
                ll b;
                cin>>b;
                setWhichHave[b].push_back(i);
                ll c=1;
                c=c<<b;
                a=(a | c);
            }
            // cout<<a<<" ";
            og[i]=a;
        }
        helper(og,n,setWhichHave);
    }
    return 0;
}