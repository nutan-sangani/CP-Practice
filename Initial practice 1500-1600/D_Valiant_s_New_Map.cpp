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
    bool operator()(pll a,pll b){
        return a.first > b.first;
    }
};

bool isValid(vector<vecll>& matrix,ll n,ll m,int mid){
    priority_queue<pll,vector<pll>,MyComp> pq;
    vector<vecll> rows(n,vecll (m,1));
    //rows = {{1,1,1},
    //        {1,1,1}}
    for(int i=0;i<n;i++){
        // if(i>n-(mid-1)) break;
        for(int j=0;j<m;j++){
            pq.push(mp(matrix[i][j],j));
            // if((j-mid+1)<0) continue;
            int start = j-mid+1;
            while(!pq.empty() && pq.top().second<start) pq.pop();
            if(start>=0)
                rows[i][j]=pq.top().first;
        }
        while(!pq.empty()) pq.pop();
    }
    vector<vecll> cols(n,vecll (m,1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pq.push(mp(rows[j][i],j));
            int start = j-mid+1;
            while(!pq.empty() && pq.top().second<start) pq.pop();
            if(start>=0)
                cols[j][i]=pq.top().first;
        }
        while(!pq.empty()) pq.pop();
    }
    ll maxi=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            maxi=max<ll>(maxi,cols[i][j]);
    if(maxi>=mid) return true;
    return false;
}
//1 to 2
//

void helper(vector<vecll>& matrix,ll n,ll m)
{
    int low = 1;
    int high = min<ll>(n,m);
    while(low<=high){
        int mid = (low+high)/2;
        if(isValid(matrix,n,m,mid)){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<high<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vecll> matrix(n,vecll (m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>matrix[i][j];
        helper(matrix,n,m);
    }
    return 0;
}