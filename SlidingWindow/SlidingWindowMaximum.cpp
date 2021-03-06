//link of the question
//https://leetcode.com/problems/sliding-window-maximum/submissions/

//1)brute_force solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        int mx;
        for (int i = 0; i <= n - k; i++)
    {
        mx = nums[i];
 
        for (int j = 1; j < k; j++)
        {
            if (nums[i + j] > mx)
                mx = nums[i + j];
        }
        ans.push_back(mx);
    }
        return ans;
    }
};



//2) sliding window solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        //suppose if k is greater than nums.size()
         if (k>nums.size()) {
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }
        int i=0,j=0;
        list<int>ls;
        while(j<nums.size()){
           while(ls.size()>0 && ls.back()<nums[j]){
               ls.pop_back();
           }
            ls.push_back(nums[j]);
            
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                ans.push_back(ls.front());
                if(ls.front()==nums[i]){
                    ls.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
