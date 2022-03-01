class Solution {
public:
    int numUniqueEmails(vector<string>& emails){
	int emailCount = emails.size();
	if(emailCount <= 1) return emailCount;
	set<string> uniqueEmails;
	for(int i = 0; i < emailCount; i++){
	    string currentEmail;
	    int j = 0;
	    for(; j < emails[i].size(); j++){
		    if(emails[i][j] == '.') continue;
		    if(emails[i][j] == '+' || emails[i][j] == '@') break;
		    currentEmail.push_back(emails[i][j]);
        }
        while(emails[i][j] != '@')j++;
        j++;
        currentEmail.push_back('@');
        while(j < emails[i].size()){
	        currentEmail.push_back(emails[i][j]);
            j++;
        }
        cout << currentEmail << endl;
        uniqueEmails.insert(currentEmail);
    }
    return uniqueEmails.size();
    }

};