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

class SubArr{
    public:

    SubArr(int size,int l,int r){
        this->size=size;
        this->left=l;
        this->right=r;
    }

    int size;
    int left;
    int right;
};

class MyComp{
    public:
    bool operator()(const SubArr& a,const SubArr& b){
        if(a.size!=b.size) return a.size<b.size;
        return a.left>b.left;
    }
};

void helper(int n)
{
    priority_queue<SubArr,vector<SubArr>,MyComp> pq;
    SubArr a(n,1,n);
    pq.push(a);
    vecll ans(n+1);
    int count=1;
    while(!pq.empty()){
        SubArr nn = pq.top();
        pq.pop();
        int mid;
        if(nn.size%2==0){
            mid = (nn.left+nn.right-1)/2;
        }
        else mid = (nn.left+nn.right)/2;
        ans[mid]=count++;
        int leftSize = (mid-1) - nn.left +1;
        int rightSize = nn.right - (mid+1) +1;
        if(leftSize>0){
            SubArr x(leftSize,nn.left,mid-1);
            pq.push(x);
        }
        if(rightSize>0){
            SubArr x(rightSize,mid+1,nn.right);
            pq.push(x);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
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
        helper(n);
    }
    return 0;
}