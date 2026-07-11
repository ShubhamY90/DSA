class NumArray {
public:
    vector<int> segTree;
    int n;
    int buildTree(vector<int>& nums, int ind, int l, int r){
        if(l == r){
            segTree[ind] = nums[l];
            return segTree[ind];
        }
        int mid = l + (r - l)/2;
        int leftSum = buildTree(nums, 2*ind + 1, l, mid);
        int rightSum = buildTree(nums, 2*ind + 2, mid + 1, r);
        segTree[ind] = leftSum + rightSum;
        return segTree[ind];
    }
    int query(int ind, int l, int r, int left, int right){
        if(l > right || r < left){
            return 0;
        }
        if(left <= l && r <= right){
            return segTree[ind];
        }
        int mid = l + (r - l)/2;
        return query(2*ind + 1, l, mid, left, right) + query(2*ind + 2, mid + 1, r, left, right);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*n, 0);
        buildTree(nums, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */