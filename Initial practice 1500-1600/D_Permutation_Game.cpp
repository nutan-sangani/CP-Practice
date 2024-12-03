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

void helper(vecll& a,vecll& p,ll n,ll k,ll b,ll s)
{
    ll maxB,maxS;
    maxB=maxS=-1;
    umll map;
    vecll bMoves;
    vecll sMoves;
    int i=b;
    int j=0;
    while(j<=(n+2)){
        bMoves.pb(i);
        int nextIndex = p[i];
        if(map[nextIndex]!=0 || nextIndex==i){
            break;
        }
        map[i]=1;
        i=nextIndex;
        j++;
    }
    i=s;
    j=0;
    map.clear();
    while(j<=(n+2)){
        sMoves.pb(i);
        int nextIndex = p[i];
        if(map[nextIndex]!=0 || nextIndex==i){
            break;
        }
        map[i]=1;
        i=nextIndex;
        j++;
    }
    i=0;
    ll runningSum=0;
    while(i<k && i<bMoves.size()){
        ll multiple = k-i;
        ll temp = multiple*a[bMoves[i]]*1LL+runningSum;
        runningSum+=a[bMoves[i]];
        if(maxB<temp)
            maxB=temp;
        i++;
    }
    i=0;
    runningSum=0;
    while(i<k && i<sMoves.size()){
        ll multiple = k-i;
        ll temp = multiple*a[sMoves[i]]*1LL + runningSum;
        runningSum+=a[sMoves[i]];
        if(maxS<temp){
            maxS=temp;
        }
        i++;
    }
    if(maxB>maxS){
        cout<<"Bodya"<<endl;
        return;
    }
    else if(maxB<maxS){
        cout<<"Sasha"<<endl;
        return;
    }
    else cout<<"Draw"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,b,s;
        cin>>n>>k>>b>>s;
        vecll p(n);
        vecll a(n);
        forLoop
        {
            ll z;
            cin>>z;
            p[i]=z-1;
        }
        forLoop
            cin>>a[i];
        helper(a,p,n,k,b-1,s-1);
    }
    return 0;
}