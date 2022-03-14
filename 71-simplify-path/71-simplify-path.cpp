class Solution {
public:
    string simplifyPath(string path) {
        string resultPath;
        string currentToken;
        vector<string> tokenStack;
        istringstream in(path);
        while(getline(in, currentToken, '/')){
            if(currentToken == "" || currentToken == ".")continue;
            if(currentToken == ".." && tokenStack.size()){
                // .. is move up a level
                tokenStack.pop_back();
            }else if(currentToken != "..") tokenStack.push_back(currentToken);
        }
        for(auto token: tokenStack){
            resultPath += "/" + token;
        }
        if(tokenStack.size()) return resultPath;
        return "/";
    }
};