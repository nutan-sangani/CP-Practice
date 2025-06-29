#include <stdio.h>
#include<bits/stdc++.h>
#include<iostream>
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

void removeStart(deque<int>& maxQ,deque<int>& minQ,vector<int>& nums,int start){
    if(!minQ.empty() && minQ.front()==nums[start]) minQ.pop_front();
    if(!maxQ.empty() && maxQ.front()==nums[start]) maxQ.pop_front();
}

int monotonicQ(vector<int>& nums,int limit){
    deque<int> minQ,maxQ;
    ll maxSize = 1;
    int start = 0,end = 0;
    while(1){
        while(!minQ.empty() && minQ.back()>nums[end]) minQ.pop_back();
        minQ.push_back(nums[end]);
        while(!maxQ.empty() && maxQ.back()<nums[end]) maxQ.pop_back();
        maxQ.push_back(nums[end]);
        ll maxDiff = maxQ.front() - minQ.front();
        if(maxDiff<=limit){
            maxSize = max<ll>(maxSize,end-start+1);
        }
        else{
            //start se nikalna chalu kr
            while(!maxQ.empty() && !minQ.empty() && (maxQ.front()-minQ.front()) > limit){
                removeStart(maxQ,minQ,nums,start);
                start++;
            }
        }
        end++;
    }
    return maxSize;
}


string removeKDigits(string num,int k){
    int n = num.size();
    vecll a(n);
    forn(0,n) a[i] = num[i]-'0';
    deque<ll> q;
    forn(0,n){
        while(!q.empty() && q.back()>a[i] && k>0){
            k--;
            q.pop_back();
        }
        q.push_back(a[i]);
    }
    while(!q.empty() && k>0){
        q.pop_back();
        k--;
    }
    while(!q.empty() && q.front()==0) q.pop_front();
    string ans="";
    while(!q.empty()){
        ans+=(q.front()+'0');
        q.pop_front();
    }
    if(ans=="") ans="0";
    return ans;
}

ll maximizeGCD(vector<int>& nums,int k){
    ll maxScore = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        ll gcd = nums[i];
        ll numbersWhoNeed2 = 1;
        for(int j=i;j<n;j++){
            int length = j-i+1;
            ll tempGcd = __gcd(gcd,nums[j]+0LL);
            ll divisor = gcd/tempGcd;
            ll rem = nums[j]/tempGcd;
            if(divisor%2==0){
                numbersWhoNeed2 = 1;
            }
            else if(rem%2!=0 && j!=i) numbersWhoNeed2++;
            gcd = tempGcd;
            ll currScore = length*gcd;
            if(k>=numbersWhoNeed2){
                currScore*=2;
            }
            maxScore = max<ll>(maxScore,currScore);
        }
    }
    return maxScore;
}

int main(){

}