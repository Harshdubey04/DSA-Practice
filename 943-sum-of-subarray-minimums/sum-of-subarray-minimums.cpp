class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // int total=0;
        // int mod=(int)(1e9+7);
        // for(int i=0;i<arr.size();i++){
        //     int mini=INT_MAX;
        //     for(int j=i;j<arr.size();j++){
        //         mini=min(mini,arr[j]);
        //         total=(total+mini)%mod;
        //     }
        // }
        // return total;

        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous strictly smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + 1LL * arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};

/*

 */