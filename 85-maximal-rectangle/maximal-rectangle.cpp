class Solution {
public:
    int lHist(vector<int>& psum) {
        stack<int> st;
        int maxArea = 0;
        int n = psum.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && psum[st.top()] > psum[i]) {
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, psum[ele] * (nse - pse - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, psum[ele] * (nse - pse - 1));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> psum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1')
                    sum++;
                else
                    sum = 0;

                psum[i][j] = sum;
            }
        }

        int maxAr = 0;

        for (int i = 0; i < n; i++) {
            maxAr = max(maxAr, lHist(psum[i]));
        }

        return maxAr;
    }
};

// int largestRectangleArea(vector<int>& heights) {
// stack<int> st;
// int maxArea = 0;
// int n = heights.size();

// for (int i = 0; i <= n; i++) {
//     int currHeight = (i == n) ? 0 : heights[i];

//     while (!st.empty() && heights[st.top()] > currHeight) {
//         int height = heights[st.top()];
//         st.pop();

//         int width;
//         if (st.empty())
//             width = i;
//         else
//             width = i - st.top() - 1;

//         maxArea = max(maxArea, height * width);
//     }

//     st.push(i);
// }

// return maxArea;
//     }

//  if (matrix.empty() || matrix[0].empty())
//             return 0;

//         int rows = matrix.size();
//         int cols = matrix[0].size();

//         vector<int> heights(cols, 0);
//         int ans = 0;

//         for (int i = 0; i < rows; i++) {

//             // Build histogram for current row
//             for (int j = 0; j < cols; j++) {
//                 if (matrix[i][j] == '1')
//                     heights[j]++;
//                 else
//                     heights[j] = 0;
//             }

//             ans = max(ans, largestRectangleArea(heights));
//         }

//         return ans;