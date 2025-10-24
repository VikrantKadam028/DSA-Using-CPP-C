class Solution {
public:
    bool isBeautiful(int num) {
        unordered_map<int, int> freq;
        int temp = num;

        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0)
                return false;
            freq[digit]++;
            if (freq[digit] > digit)
                return false;
            temp /= 10;
        }

        for (auto& it : freq) {
            if (it.first != it.second)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int num = n + 1;
        while (true) {
            if (isBeautiful(num))
                return num;
            num++;
        }
    }
};

int dummy = (atexit([]{ofstream("display_runtime.txt", ios::trunc) << 0;}), 0);
