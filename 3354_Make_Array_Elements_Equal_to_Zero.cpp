class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<string> directions = {"left", "right"};
        int validCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (string dir : directions) {
                    vector<int> copy(nums);
                    int current = i;

                    while (current >= 0 && current < n) {
                        if (copy[current] == 0) {
                            if (dir == "right")
                                current += 1;
                            else
                                current -= 1;
                        } 
                        else if (copy[current] > 0) {
                            copy[current]--;

                            if (dir == "left")
                                dir = "right";
                            else if (dir == "right")
                                dir = "left";

                            if (dir == "right")
                                current += 1;
                            else
                                current -= 1;
                        }
                    }

                    bool allZero = true;
                    for (int x : copy) {
                        if (x != 0) {
                            allZero = false;
                            break;
                        }
                    }

                    if (allZero)
                        validCount++;
                }
            }
        }
        return validCount;
    }
};
