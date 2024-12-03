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

ll avg = -1;

bool is2KaPower(ll a){
    if(a==0) return false;
    int ceilingVal = ceil(log2(a));
    int floorVal = log2(a);
    return floorVal == ceilingVal;
}

void helper(vecll& nums,int n)
{
    umll outGoing;
    umll inComing;
    set<ll> unique;
    forn(0,n){
        if(nums[i]>avg){
            int extra = nums[i] - avg;
            //so if extra is 2 ka power or extra+2_ka_power is 2 ka power, than we can make edges;
            //so all 35 tak 2 ke powers check kr.
            ll willGive = -1;
            ll willReceive = -1;
            for(int j=0;j<=35;j++){
                ll power = pow(2,j);
                if(power == extra){
                    if(nums[i]<2*extra){
                        continue;
                    }
                    willReceive = extra;
                    willGive = 2*extra;
                }
                else if(is2KaPower(power+extra)){
                    if(nums[i]<(power+extra)) continue;
                    willReceive = power;
                    willGive = extra+power;
                }
            }
            if(willGive==-1 || willReceive==-1){
                cout<<"No"<<endl;
                return;
            }
            unique.insert(willGive);
            unique.insert(willReceive);
            outGoing[willGive]++;
            inComing[willReceive]++;
        }
        else if(nums[i]<avg){
            int diff = avg - nums[i];
            ll willGive = -1;
            ll willReceive = -1;
            for(int j=0;j<=35;j++){
                ll power = pow(2,j);
                if(power == diff){
                    willReceive = 2*diff;
                    willGive = diff;
                }
                else if(is2KaPower(power+diff)){
                    willReceive = diff+power;
                    willGive = power;
                }
            }
            if(willGive==-1 || willReceive==-1){
                cout<<"No"<<endl;
                return;
            }
            unique.insert(willGive);
            unique.insert(willReceive);
            outGoing[willGive]++;
            inComing[willReceive]++;
        }
    }
    for(ll x : unique){
        if(outGoing[x]==inComing[x]){
            outGoing[x]=0;
            inComing[x]=0;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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
        ll sum = 0;
        forn(0,n){
            cin>>nums[i];
            sum+=nums[i];
        }
        if(sum%n!=0){
            cout<<"No"<<endl;
            continue;
        }
        avg = sum/n;
        helper(nums,n);
    }
    return 0;
}