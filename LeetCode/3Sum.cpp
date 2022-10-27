// Question: 3 Sum
// Platform: Leetcode
// Difficulty: Medium

// **BEST APPROACH USING TWO POINTER (LOW & HIGH)**
// * Time Complexity: O(m*n)
// * Space Complexity: O(1)


class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low=i+1;
                int high=n-1;
                int sum=0-nums[i];
                
                while(low<high){
                    if(nums[low]+nums[high] == sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        
                        while(low<high && nums[low]==nums[low+1]){
                            low++;
                        }
                        while(low<high && nums[high]==nums[high-1]){
                            high--;
                        }
                        low++;high--;
                    }
                    else if(nums[low]+nums[high]<sum){
                        low++;
                    }
                    else{
                        high--;                
                    }
                }
            }
        }
        
        return ans;
    }

};

// **EXPLANATION:**
// 1. First,  we sort the array so that two pointe (low & high) can work.
// 2. Second, then we traverse till n-2 so that our pointer can work and does not go out of bound.
// 3. Then, we take the negative SUM, variable which is basically the negative of current value.
// 4. The, we find the low and high sum which is equal to SUM in this case 3 things happens:
//     * The sum is equal then we push the current value, low , high in answer.
//     * The current sum is lower than required sum then we move low to next value avoiding repetition
//     * Then current sum is higher than required sum then we move the high to lower avoiding repetition


// **BRUTE FORCE USING THE MAP**
// * Time Complexity: O(m*n)
// * Space Complexity: O(n)

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> res;
       
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            for (int j = i+1; j < nums.size(); j++) {
                if (j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                
                if (m[-(nums[i] + nums[j])] > j){
                    res.push_back({nums[i], nums[j], -(nums[i] + nums[j])});
                }
            }
        }
        return res;
    }

};


// **EXPLANATION:**
// 1. First we traverse the given array and store the value and its index in the map.
// 2. Then we iterate using the nested loop and check for the two value sum and its corresponding negative value.
