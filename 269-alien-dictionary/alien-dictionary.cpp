class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char>>graph;
        unordered_map<char,int> indegree;

        for(string word:words){
          for(auto c:word) indegree[c]=0;
        }

        for(int i=1;i<words.size();i++){
          string words1=words[i-1];
          string words2=words[i];

          int len=min(words1.size(),words2.size());
          bool found=false;

          for(int j=0;j<len;j++){
            char c1=words1[j];
            char c2=words2[j];
            if(c1!=c2){
              if(!graph[c1].count(c2)){
                graph[c1].insert(c2);
                indegree[c2]++;
              }
              found=true;
              break;
            }
          }
          if(!found && words1.size()>words2.size()){
            return "";
          }
        }
        string result;
        queue<char> q;
        for(auto entry:indegree){
          if(entry.second==0){
            q.push(entry.first);
          }
        }

        while(!q.empty()){
          char c=q.front();
          q.pop();
          result+=c;

          for(char nei:graph[c]){
            indegree[nei]--;
            if(indegree[nei]==0) q.push(nei);
          }
        }
        if(result.size()<indegree.size()) return "";
        return result;
    }
};