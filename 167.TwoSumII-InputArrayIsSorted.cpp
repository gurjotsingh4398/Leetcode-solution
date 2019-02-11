https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

----------------------------------------------------1st solution(best)---------------------------------------------------

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0;
        int right = numbers.size() - 1; 
        vector<int> vec;
        int sum = 0;
        while(left < right)
        {
            sum = numbers[left] + numbers[right];
            if(sum > target)
                right--;
            else if(sum < target)
                left++;
            else
            {
                vec.push_back(left + 1);
                vec.push_back(right + 1);
                break;
            }
        }
        return vec;
        
    }
};


--------------------------------------------------------2nd solution--------------------------------------------

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res(2,0);
            for(int i=0;i<nums.size();i++) {
            int comp = target - nums[i];
            if(map[comp]) {
                res[0]=map[comp]-1+1;
                res[1]=i+1;
                break;
            } 
            else  {
                map[nums[i]]=i+1;
                
            }
            
        }
        return res;
    }
};

---------------------------------------------------3rd solution------------------------------------------------

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int bs(vector<int>& arr,int s,int e,int k) {
    if(s<=e) {
        int mid= (s+e)/2;
        if(arr[mid]==k) {
            return mid;
        }
        else if(arr[mid]>k) {
            return bs(arr,s,mid-1,k);
        }
       return bs(arr,mid+1,e,k); 
    }
    return -1;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        for(int i=0;i<numbers.size()-1;i++) {
            ans[1] = bs(numbers,i+1,numbers.size()-1,target-numbers[i]);
            if (ans[1]!= -1) {
                ans[0]= i+1;
                ans[1]= ans[1]+1;
                break;
            }
        }
        return ans;
    }
};
