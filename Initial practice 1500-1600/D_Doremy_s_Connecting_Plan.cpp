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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){
        return a.first<b.first;
    }
};

void helper(vecll& nums,ll n,ll c)
{
    priority_queue<pll,vector<pll>,MyComp> pq;
    vecll prefixSum(n,0);
    ll sum=0;
    forn(0,n){
        sum+=nums[i];
        prefixSum[i]=sum;
    }
    pq.push(mp(nums[n-1]-(n*c),n-1));
    sum=0;
    int index = -1;
    for(int i=n-2;i>=0;--i){
        ll aj = nums[pq.top().second];
        ll j = pq.top().second;
        ll ai = nums[i];
        ll rhs = (i+1)*(j+1)*c;
        ll lhs = ai+aj;
        if(lhs>=rhs){
            sum=prefixSum[i]+aj;
            pq.pop();
            index = i+1;
            break;
        }
        pq.push(mp(nums[i]-(i+1)*c,i));
    }
    if(index==-1){
        cout<<"No"<<endl;
        return;
    }
    while(!pq.empty()){
        int j = pq.top().second;
        ll rhs = (j+1)*c;
        ll lhs = sum + nums[j];
        if(lhs>=rhs){
            sum+=nums[j];
            pq.pop();
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        vecll nums(n);
        forn(0,n)   cin>>nums[i];
        helper(nums,n,c);
    }
    return 0;
}