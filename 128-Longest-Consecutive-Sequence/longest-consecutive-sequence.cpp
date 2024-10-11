#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        //map of endpoint and size of part
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            m[nums[i]]=1;
            s.insert(nums[i]);
        }
        unordered_set<int> ::iterator itr;
        int res=0;
        for(itr=s.begin();itr!=s.end();itr++){
            int num=*itr;
            //will process only the end points
            if(m.count(num)){
                    //only n-1 is endpoint
                if(m.count(num-1)){
                    int rightLength=m[num];
                    int leftLength=m[num-1];
                    m.erase(num);
                    m.erase(num-1);
                    int len=leftLength+rightLength;
                    m[num-leftLength]=len;
                    m[num+rightLength-1]=len;
                }
            }
        }
        for(auto c:m){
            res=max(res,c.second);
        }
        return res;
    }
};