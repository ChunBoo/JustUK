/**
 * @brief 
 * 
 * Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

Implement the FrequencyTracker class.

FrequencyTracker(): Initializes the FrequencyTracker object with an empty array initially.
void add(int number): Adds number to the data structure.
void deleteOne(int number): Deletes one occurrence of number from the data structure. The data structure may not contain number, and in this case nothing is deleted.
bool hasFrequency(int frequency): Returns true if there is a number in the data structure that occurs frequency number of times, otherwise, it returns false.
 

Example 1:

Input
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
Output
[null, null, null, true]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.add(3); // The data structure now contains [3, 3]
frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice
 * 
 */
class FrequencyTracker {
public:
    FrequencyTracker():freq(N),freqCnt(N) {

    }
    
    void add(int number) {
        --freqCnt[freq[number]];
        ++freq[number];
        ++freqCnt[freq[number]];
    }
    
    void deleteOne(int number) {
        if(freq[number]==0)
            return;
        --freqCnt[freq[number]];
        --freq[number];
        ++freqCnt[freq[number]];
    }
    
    bool hasFrequency(int frequency) {
        return freqCnt[frequency];
    }
private:
    static const int N=100001;
    vector<int> freq;
    vector<int> freqCnt;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */