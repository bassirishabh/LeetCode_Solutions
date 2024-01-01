class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        int step=1;

        queue<pair<string,int>> q;
        q.push({beginWord,step});
        s.erase(beginWord);

        while(!q.empty()){
            auto word=q.front();
            q.pop();
            if(word.first==endWord) return word.second;
            for(int i=0;i<word.first.size();i++){
                char original=word.first[i];
                for(char ch='a';ch<='z';ch++){
                    word.first[i]=ch;
                    if(s.find(word.first)!=s.end()){
                        s.erase(word.first);
                        if(word.first==endWord) return word.second+1;
                        q.push({word.first,word.second+1});
                    }
                }
                word.first[i]=original;
            }
            

        }
        return 0;
    }
};