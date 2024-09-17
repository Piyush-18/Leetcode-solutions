class Solution {
public:
    void countWords(const string& sentence, unordered_map<string, int>& wordCount) {
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        wordCount[word]++;
    }
}

vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    
    // Count words from both sentences
    countWords(s1, wordCount);
    countWords(s2, wordCount);
    
    // Collect uncommon words
    vector<string> result;
    for (const auto& entry : wordCount) {
        if (entry.second == 1) {
            result.push_back(entry.first);
        }
    }
    
    return result;
}

};