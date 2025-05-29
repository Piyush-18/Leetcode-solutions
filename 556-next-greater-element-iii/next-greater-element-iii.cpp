class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.length();
        int dip = -1;

        // Step 1: Find dip
        for (int i = len - 1; i >= 1; i--) {
            if (str[i] > str[i - 1]) {
                dip = i - 1;
                break;
            }
        }

        if (dip == -1) return -1;

        // Step 2: Find the smallest character greater than str[dip]
        char minChar = CHAR_MAX;
        int index = -1;
        for (int i = dip + 1; i < len; i++) {
            if (str[i] > str[dip] && str[i] < minChar) {
                minChar = str[i];
                index = i;
            }
        }

        if (index == -1) return -1;

        // Step 3: Swap and sort
        swap(str[index], str[dip]);
        sort(str.begin() + dip + 1, str.end());

        // Step 4: Convert and check range
        long long result = stoll(str);
        return (result > INT_MAX) ? -1 : (int)result;
    }
};
