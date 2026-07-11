class NumArray {
public:
    vector<int> segTree;
    int n;

    void buildTree(vector<int>& nums, int ind, int l, int r){
        if(l == r){
            segTree[ind] = nums[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        buildTree(nums, 2*ind + 1, l, mid);
        buildTree(nums, 2*ind + 2, mid + 1, r);
        segTree[ind] = segTree[2*ind + 1] + segTree[2*ind + 2];
        return;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*n, 0);
        buildTree(nums, 0, 0, n - 1);
    }
    
    void up(int index, int val, int ind, int l, int r){
        if(l == r){
            segTree[ind] = val;
            return;
        }
        int mid = l + (r - l)/2;
        if(index <= mid){
            up(index, val, 2*ind + 1, l, mid);
        }
        else{
            up(index, val, 2*ind + 2, mid + 1, r);
        }
        segTree[ind] = segTree[2*ind + 1] + segTree[2*ind + 2];
        return;
    }
    void update(int index, int val) {
        up(index, val, 0, 0, n - 1);
    }
    
    int query(int left, int right, int l, int r, int ind){
        if(l > right || r < left){
            return 0;
        }

        if(l >= left && r <= right){
            return segTree[ind];
        }
        int mid = l + (r - l)/2;
        return query(left, right, l, mid, 2*ind + 1) + query(left, right, mid + 1, r, 2*ind + 2);
    }
    int sumRange(int left, int right) {
        return query(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */