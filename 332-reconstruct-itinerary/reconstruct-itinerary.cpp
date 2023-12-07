class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
    vector<string> ans;

    void dfs(string source){
      while(!mp[source].empty()){
        string to=mp[source].top();
        mp[source].pop();
        dfs(to);
      }
      ans.push_back(source);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        for(auto t:tickets){
          mp[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};