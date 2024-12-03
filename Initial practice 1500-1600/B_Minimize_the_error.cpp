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

void helper(vecll&a,vecll&b,int k1,int k2,int n)
{
    ll sum=0;
    int total=k1+k2;
    priority_queue<ll> pq;
    forLoop
    {
        sum+=abs(a[i]-b[i]);
        pq.push(abs(a[i]-b[i]));
    }
    while(total>0){
        int a = pq.top();
        if(a==0){
            a+=1;
        }
        else a-=1;
        pq.pop();
        pq.push(a);
        total--;
    }
    sum=0;
    while(!pq.empty()){
        sum+=(pow((pq.top()),2));
        pq.pop();
    }
    cout<<sum<<endl;
    return;
    
}

int main()
{
    FASTIO
    
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vecll a(n);
    vecll b(n);
    forLoop
        cin>>a[i];
    forLoop
        cin>>b[i];
    helper(a,b,k1,k2,n);
    return 0;
}