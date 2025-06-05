#include <iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
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
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define forn(begin,end) for(int i=begin;i<end;i++)

using namespace std;
using namespace __gnu_pbds;

void findPrevSmallerElem(vecll& a,vecll& pse){
    stack<ll> st;
    forn(0,a.size()){
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        if(!st.empty()) pse[i] = st.top();
        st.push(i);
    }
}

template<typename T>
void printArray(vector<T>& a){
    int n = a.size();
    forn(0,n) cout<<a[i]<<" ";
    cout<<endl;
}

void helper(vecll& nums,int n)
{
    vecll a(nums);
    vecll isSmallerSizedSubPresent(n,1);
    //1 sized subseq toh humesha h
    //2 sized ke liye sare one ko check ki isse chote h 1 size wale(1 bhi hua toh 2 size ka banta
    //ending at i)
    //same for size=3, ab count of 2 sized - count of 3 sized krenge toh aajana chahiye real only 2 sized
    ordered_set sortedNumsWithIMinus1Size;
    ll countOfSize2=0,countOfSize3=0;
    forn(0,n){ 
        ll temp = isSmallerSizedSubPresent[i];
        if(sortedNumsWithIMinus1Size.order_of_key(a[i])!=0){
            isSmallerSizedSubPresent[i] = 1;
            countOfSize2++;
        }
        else isSmallerSizedSubPresent[i]=0;
        if(temp==1) sortedNumsWithIMinus1Size.insert(a[i]);
    }
    sortedNumsWithIMinus1Size.clear();
    forn(0,n){
        ll temp = isSmallerSizedSubPresent[i];
        if(sortedNumsWithIMinus1Size.order_of_key(a[i])!=0){
            countOfSize3++;
            isSmallerSizedSubPresent[i]=1;
        }
        else isSmallerSizedSubPresent[i]=0;
        if(temp==1) sortedNumsWithIMinus1Size.insert(a[i]);
    }
    cout<<countOfSize2-countOfSize3<<endl;
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
        forn(0,n)
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}