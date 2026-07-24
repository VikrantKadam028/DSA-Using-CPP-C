class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int longest = 0;
        int distinctcnt = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < fruits.size(); i++) {
            if (freq.find(fruits[right]) == freq.end()) {
                distinctcnt++;
            }
            freq[fruits[right]]++;

            while (distinctcnt > 2 && left < fruits.size()) {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                    distinctcnt--;
                }
                left++;
            }

            if (distinctcnt <= 2) {
                longest = max(longest, right - left + 1);
            }
            right++;
        }
        return longest;
    }
};