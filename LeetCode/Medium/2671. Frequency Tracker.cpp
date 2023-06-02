class FrequencyTracker {
    unordered_map<int,int> nums,freqs;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(nums.count(number)){
            freqs[nums[number]]--;
        }
        nums[number]++;
        freqs[nums[number]]++;
    }
    
    void deleteOne(int number) {
        if(nums.count(number)){
            if(nums[number]==1)nums.erase(number),freqs[1]--;
            else{
                freqs[nums[number]]--;
                nums[number]--;
                freqs[nums[number]]++;
            }            
        }
    }
    
    bool hasFrequency(int frequency) {
        return freqs[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */