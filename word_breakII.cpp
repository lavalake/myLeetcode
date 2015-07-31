class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        vector<string> path;
        vector<bool> flag;
        bool breakable = false;
        int pre=0;
        if(wordDict.empty())
            return result;
        for(int i=0; i<s.size(); ++i){
            if(i != 0)
                if(flag[i-1] == false)
                    continue;
            
            for(auto word : wordDict){
                if(s.compare(i,word.size(),word) == 0){
                    if(i+word.size() == s.size())
                        breakable = true;
                    flag[i+word.size()-1] = true;    
                        
                }
                    
            }
        }
        if(breakable == false)
            return result;
        dfs(s, wordDict, flag, 0,path, result);
        return result;
    }
private:
    void dfs(string& s, unordered_set<string>& wordDict, vector<bool>& flag, int index, vector<string>& path, vector<string>& result){
        if(index == s.size()){
            string temp;
            for(auto str:path){
                temp += str+" ";
            }
            temp.erase(temp.begin()+temp.size()-1,temp.end());
            result.push_back(temp);
            return;
        }
        
        
             
            for(auto word:wordDict){
                if(s.substr(index,word.size()) == word){
                    path.push_back(word);
                    dfs(s, wordDict, flag, index+word.size(),path, result);
                    path.pop_back();
                }
            }
    
    }
};
