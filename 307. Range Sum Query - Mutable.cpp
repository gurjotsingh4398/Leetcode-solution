// https://leetcode.com/problems/range-sum-query-mutable/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class NumArray {
public:
    vector<int> tree;
    int n;
    void build(vector<int>& nums, int index, int s, int e) {
        if(s==e) tree[index]=nums[s];
        else {
           int mid=(s+e)/2; 
           build(nums,2*index+1,s,mid); 
           build(nums,2*index+2,mid+1,e);
           tree[index]=tree[2*index+1] + tree[2*index+2];           
        }
        
    }
    
    void updateTree(int index ,int i, int val ,int s, int e) {
        if(s==e) tree[index]=val;
        else {
            int mid=(s+e)/2;
            if(i<=mid) updateTree(2*index+1,i,val,s,mid);
            else if(i>mid) updateTree(2*index+2,i,val,mid+1,e);
            tree[index]=tree[2*index+1] + tree[2*index+2];
        }
    }
    
    int query(int index, int i, int j, int s, int e) {
        if(i>e || j<s) return 0;
        if(i<=s && j>=e) return tree[index];
        
        int mid=(s+e)/2;
        int l=query(2*index+1,i,j,s,mid);
        int r=query(2*index+2,i,j,mid+1,e);
        return l+r;
    }
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        int treeSize = 2 * pow(2, ceil(log2(n)));
        if(treeSize>0) {
            tree.resize(treeSize, 0);
            build(nums,0,0,n-1);
        }
    }
    
    void update(int i, int val) {
        // nums[i]=val;
        updateTree(0,i,val,0,n-1);
    }
    
    int sumRange(int i, int j) {
        return query(0,i,j,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */