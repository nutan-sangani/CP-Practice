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

int query(int a,int b)
{
    int x;
    cout<<"? "<<a<<" "<<b<<endl;
    cout<<endl;
    cout.flush();
    cin>>x;
    cout.flush();
    return x;
}

void printAns(int x){
    cout<<"! "<<x<<endl;
    cout.flush();
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int low = 2;
        int high = 999;
        while(low<=high){
            int mid = (low+high)/2;
            int area = query(mid,mid);
            int idealArea = mid*mid;
            if(area==idealArea){
                low = mid + 1;
            }
            else{
                high = mid - 1; 
            }
        }
        printAns(low);
    }
    return 0;
}