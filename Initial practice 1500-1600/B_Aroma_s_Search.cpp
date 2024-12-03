#include <iostream>
#include<bits/stdc++.h>
#define ll long long
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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

ll getDistance(ll x1,ll y1,ll x2,ll y2){
    return abs(x2-x1)+abs(y2-y1);
}

int main()
{
    FASTIO
    
    ll x0,y0,ax,ay,bx,by;
    ll xs,ys,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    vecll xCoord;
    vecll yCoord;
    ll prev = x0;
    ll limit = 3e16;
    ll curr=x0;
    xCoord.pb(curr);
    while(curr<limit){
        curr = ax*(prev)*1LL+bx;
        prev = curr;
        xCoord.pb(curr);
    }
    prev=curr=y0;
    yCoord.pb(curr);
    while(curr<limit){
        curr = ay*prev*1LL+by;
        prev = curr;
        yCoord.pb(curr);
    }
    int maxIndex = min(xCoord.size(),yCoord.size());
    int maxCount=-1;
    for(int i=0;i<maxIndex;i++){
        ll sum=0;
        int count=0;
        sum = getDistance(xs,ys,xCoord[i],yCoord[i]);
        if(sum<=t)
            count+=1;
        int j = i;
        ll backCost=0;
        while(sum<=t && j>0){
            sum += getDistance(xCoord[j],yCoord[j],xCoord[j-1],yCoord[j-1]);
            backCost += getDistance(xCoord[j],yCoord[j],xCoord[j-1],yCoord[j-1]);
            j--;
            if(sum<=t)
                ++count;
            else break;
        }
        sum+=backCost;
        j=i;
        while(sum<=t && j+1<maxIndex){
            sum+= getDistance(xCoord[j],yCoord[j],xCoord[j+1],yCoord[j+1]);
            if(sum<=t)
                ++count;
            else break;
            j++;
        }
        maxCount = max(maxCount,count);
    }
    cout<<maxCount<<endl;
    return 0;
}