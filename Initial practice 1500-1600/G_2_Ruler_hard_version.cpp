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
    // cout<<endl;
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
        int low,high;
        low = 2;
        high = 999;
        while(low<=high){
            int part = (high - low + 1)/3;
            int mid1 = low+part;
            int mid2 = mid1+part;
            if(part==0) mid2++;
            int area = query(mid1,mid2);
            int idealArea = mid1*mid2;
            int size = high - low + 1;
            if(area == idealArea){
                low = mid2+1;
            }
            else if(area == (mid1)*(mid2+1)){
                low = mid1+1;
                high = mid2-1;
            }
            else if(area == ((mid2+1)*(mid1+1))){
                high = mid1-1;
            }
            else{
                break;
            }
        }
        printAns(low);
    }
    return 0;
}