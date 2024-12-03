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

ll getCount(vecll& unique,omll& count){
    int n = unique.size();
    ll counti=0;
    forLoop
    {
        if(count[unique[i]]>1)
            counti += count[unique[i]]*(count[unique[i]]-1);
    }
    return counti;
}

void helper(vecll &x,vecll &y,ll n)
{
    ll count=0;
    omll diff1;
    omll diff2;
    vecll uniqueDiff1;
    vecll uniqueX;
    vecll uniqueY;
    vecll uniqueDiff2;
    omll xCount;
    omll yCount;

    for(int i=0;i<n;i++){
        if(xCount[x[i]]==0){
            uniqueX.pb(x[i]);
        }
        xCount[x[i]]++;
        if(yCount[y[i]]==0){
            uniqueY.pb(y[i]);
        }
        yCount[y[i]]++;
    }
    forLoop
    {
        ll difference = y[i]-x[i];
        if(diff1[difference]==0){
            uniqueDiff1.pb(difference);
        }
        diff1[difference]++;
        difference=y[i]+x[i];
        if(diff2[difference]==0){
            uniqueDiff2.pb(difference);
        }
        diff2[difference]++;
    }
    count+=getCount(uniqueX,xCount);
    count+=getCount(uniqueY,yCount);
    count+=getCount(uniqueDiff1,diff1);
    count+=getCount(uniqueDiff2,diff2);
    cout<<count<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<ll> x;
        vector<ll> y;
        ll n;
        cin>>n;
        forLoop
        {
            ll a,b;
            cin>>a>>b;
            x.pb(a);
            y.pb(b);
        }
        helper(x,y,n);
    }
    return 0;
}