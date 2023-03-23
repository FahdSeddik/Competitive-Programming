class WordDictionary {
private:
  vector<unordered_set<string>> sets;

public:
  WordDictionary() : sets(25) {}
    
  void addWord(string word) {
    sets[word.length() - 1].emplace(word);
  }
    
  bool search(string word) {
    int length = word.length();
    const auto& set = sets[length - 1];
    if (word.find('.') == string::npos) {
      return !(set.find(word) == cend(set));
    }
    for (const auto& word2: set) {
      bool found = true;
      for (int i = 0; i < length; ++i) {
        if ((word[i] != '.') && (word[i] != word2[i])) {
          found = false;
          break;
        }
      }
      if (found) {
        return true;
      }
    }
    return false;
  }
};