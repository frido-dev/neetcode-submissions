class KthLargest {
public:
    int K;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp(pq);

        int count = K - 1;
        while(!temp.empty()) {
            int ele = temp.top();
            temp.pop();

            if (count == 0) {
                return ele;
            }
            count--;
        }
    }
};
