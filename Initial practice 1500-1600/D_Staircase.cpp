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

struct Seq{
    public:
        int left;
        int right;
        ll sum;
        int size;
        Seq(int l,int r,ll sum){
            this->size=r-l+1;
            this->left=l;
            this->right=r;
            this->sum=sum;
        }
};

ll doer(Seq& s,vecll& nums){
    ll mini = LLONG_MAX;
    int i=s.left;
    while(i<=s.right){
        ll temp = s.sum - nums[i];
        temp*=2LL;
        temp+=nums[i];
        mini = min<ll>(mini,temp);
        i+=2;
    }
    return mini;
}

void helper(vecll& nums,int n)
{
    int i=0;
    vector<Seq> a;
    while(i<n){
        if(nums[i]==0) i++;
        else{
            ll temp=0;
            int l=i;
            while(i<n && nums[i]!=0){
                temp+=nums[i];
                ++i;
            }
            Seq nn(l,i-1,temp);
            a.pb(nn);
        }
    }
    ll ans=0;
    for(Seq x : a){
        if(x.size==1) ans+=x.sum;
        else if(x.size%2==0) ans+=(2LL*x.sum);
        else ans+=doer(x,nums);
    }
    cout<<ans<<endl;
    return;
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
        vecll nums(n);
        forn(0,n) cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}