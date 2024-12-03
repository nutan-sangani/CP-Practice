#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define om map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

void findNGE(vector<int>& nums,vector<int>& nge)
{
    stack<int> st;
    int n = nums.size();
    for(int i=n-1;i>=0;--i){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(st.empty()){
            nge[i]=n;
            st.push(i);
            continue;
        }
        nge[i]=st.top();
        st.push(i);
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    om<int,int> countOfOperationsAvailable;
    vector<int> a,b;
    om<int,int> reach;
    vector<int> nge;
    while(t--)
    {
        countOfOperationsAvailable.clear();
        reach.clear();
        int n;
        int flag=0;
        cin>>n;
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n);
        nge.clear();
        nge.resize(n);
        forn(0,n)   cin>>a[i];
        forn(0,n){
            cin>>b[i];
            if(b[i]>a[i] && flag!=1){
                cout<<"NO"<<endl;
                flag=1;
            }
        }
        int m;
        cin>>m;
        forn(0,m){
            int z;
            cin>>z;
            ++countOfOperationsAvailable[z];
        }
        if(flag==1) continue; 
        findNGE(b,nge);
        forn(0,n){
            if(a[i]==b[i]) continue;
            if(reach[b[i]]>i) continue;
            else{
                if(countOfOperationsAvailable[b[i]]==0){
                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }
                else{
                    --countOfOperationsAvailable[b[i]];
                    reach[b[i]]=nge[i];
                }
            }
        }
        if(flag==1) continue;
        cout<<"YES"<<endl;
    }
    return 0;
}