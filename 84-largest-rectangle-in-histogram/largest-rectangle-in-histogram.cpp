class Solution {
public:
    // vector<int> findPSE(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> ans;
    //     stack<int> st;

    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }

    //         if (st.empty()) {
    //             ans.push_back(-1);
    //         } else {
    //             ans.push_back(st.top());
    //         }

    //         st.push(i);
    //     }

    //     return ans;
    // }

    // vector<int> findNSE(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> ans;
    //     stack<int> st;

    //     for (int i = n - 1; i >= 0; i--) {
    //         while (!st.empty() && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }

    //         if (st.empty()) {
    //             ans.push_back(n);
    //         } else {
    //             ans.push_back(st.top());
    //         }

    //         st.push(i);
    //     }

    //     reverse(ans.begin(),ans.end());

    //     return ans;
    // }

    int largestRectangleArea(vector<int>& heights) {
        // vector<int> pse = findPSE(heights);
        // vector<int> nse = findNSE(heights);
        // int maxArea = 0;

        // for (int i = 0; i < heights.size(); i++) {
        //     int area = heights[i] * (nse[i] - pse[i] - 1);
        //     maxArea = max(area, maxArea);
        // }
        // return maxArea;

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
        }

        return maxArea;
    }
};
