class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        set.insert(wordList.begin(),wordList.end());
        if(set.count(beginWord)) set.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;

            for(int i=0;i<word.size();i++) {
                char original = word[i];

                for(char j='a';j<='z';j++) {
                    word[i] = j;

                    if(set.count(word)) {
                        set.erase(word);
                        q.push({word,step + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};