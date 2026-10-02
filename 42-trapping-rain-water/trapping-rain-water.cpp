class Solution {
public:
    vector<int> leftMax(vector<int>& height) {
        int n = height.size();
        vector<int> leftPM(n);

        leftPM[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftPM[i] = max(leftPM[i - 1], height[i]);
        }

        return leftPM;
    }

    vector<int> rightMax(vector<int>& height) {
        int n = height.size();
        vector<int> rightPM(n);

        rightPM[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightPM[i] = max(rightPM[i + 1], height[i]);
        }

        return rightPM;
    }

    int trap(vector<int>& height) {
        if (height.empty())return 0;
        int water = 0;
        vector<int> left = leftMax(height);
        vector<int> right = rightMax(height);
        for (int i = 0; i < height.size(); i++) {
            water = water + min(left[i], right[i]) - height[i];
        }
        return water;
    }
};

/*

    stack<int> st;
        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if (st.empty())break;

                int left = st.top();
                int width = i - left - 1;
                int h = min(height[left], height[i]) - height[bottom];

                water += width * h;
            }

            st.push(i);
        }

        return water;

*/