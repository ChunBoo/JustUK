/**
 * Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation: 
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:The length of accounts will be in the range [1, 1000].The length of accounts[i] will be in the range [1, 10].The length of accounts[i][j] will be in the range [1, 30].

Solution: Union-Find
*/


// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         unordered_map<string_view,int> ids;
//         unordered_map<int,string_view> names;
//         vector<int> parent_(1000);
//         iota(begin(parent_),end(parent_),0);

//         function<int(int)> find=[&](int x){
//             if(x!=parent_[x])
//                 parent_[x]=find(parent_[x]);
//             return parent_[x];
//         };
//         function<int(string_view)> getIdByMail=[&](string_view mail)
//         {
//             auto it=ids.find(mail);
//             if(it==ids.end()){
//                 int id=ids.size();
//                 return ids[mail]=id;
//             }
//             return it->second;
//         };

//         for(const auto& account: accounts){
//             int u=find(getIdByMail(account[1]));
//             for(int i=2;i<account.size();++i)
//                 parent_[find(u)]=find(getIdByMail(account[i]));
//             names[find(u)]=string_view(account[0]);
//         }

//         unordered_map<int,set<string>> mergered;
//         for(const auto& account:accounts){
//             for(int i=1;i<account.size();++i)
//             {
//                 int id=find(getIdByMail(account[i]));
//                 mergered[id].insert(account[i]);
//             }
//         }

//         vector<vector<string>> ans;
//         for(const auto& kv:mergered){
//             ans.push_back({string(names[kv.first])});
//             ans.back().insert(ans.back().end(),kv.second.begin(),kv.second.end());
//         }
//         return ans;
//     }
// };

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string_view, int> ids;   // email to id
    unordered_map<int, string_view> names; // id to name
    vector<int> p(10000);
    iota(begin(p), end(p), 0);
    
    function<int(int)> find = [&](int x) {
      if (p[x] != x) p[x] = find(p[x]);
      return p[x];
    };
    
    auto getIdByEmail = [&](string_view email) {
      auto it = ids.find(email);
      if (it == ids.end()) {
        int id = ids.size();
        return ids[email] = id;
      }
      return it->second;
    };
 
    for (const auto& account : accounts) {      
      int u = find(getIdByEmail(account[1]));      
      for (int i = 2; i < account.size(); ++i) 
        p[find(u)] = find(getIdByEmail(account[i]));      
      names[find(u)] = string_view(account[0]);
    }
 
    unordered_map<int, set<string>> mergered;
    for (const auto& account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        int id = find(getIdByEmail(account[i]));
        mergered[id].insert(account[i]);
      }    
 
    vector<vector<string>> ans;
    for (const auto& kv : mergered) {
      ans.push_back({string(names[kv.first])});
      ans.back().insert(ans.back().end(), kv.second.begin(), kv.second.end());
    }
 
    return ans;
  }
};



class UnionFind{
    public:
        vector<int> parent;
        UnionFind(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        void unionSet(int idx1,int idx2){
            parent[find(idx2)]=find(idx1);
        }

        int find(int idx){
            if(parent[idx]!=idx){
                parent[idx]=find(parent[idx]);
            }
            return parent[idx];
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> mailToIndex;
        map<string,string> mailToName;

        int mailsCount=0;
        for(auto& account:accounts){
            string& name=account[0];
            int sz=account.size();
            for(int i=1;i<sz;i++){
                string& mail=account[i];
                if(!mailToIndex.count(mail)){
                    mailToIndex[mail]=mailsCount++;
                    mailToName[mail]=name;
                }
            }
        }
        UnionFind uf(mailsCount);
        for(auto& account:accounts){
            string& firstMail=account[1];
            int firstIndex=mailToIndex[firstMail];
            int sz=account.size();
            for(int i=2;i<sz;i++){
                string& nextMail=account[i];
                int nextIndex=mailToIndex[nextMail];
                uf.unionSet(firstIndex,nextIndex);
            }
        }

        map<int,vector<string>> indexToMails;
        for(auto& [mail,_]:mailToIndex){
            int idx=uf.find(mailToIndex[mail]);
            vector<string>& account=indexToMails[idx];
            account.emplace_back(mail);
            indexToMails[idx]=account;
        }

        vector<vector<string>> ans;
        for(auto &[_,mails]:indexToMails){
            sort(mails.begin(),mails.end());
            string& name=mailToName[mails[0]];
            vector<string> account;
            account.emplace_back(name);

            for(auto& mail:mails){
                account.emplace_back(mail);
            }
            ans.emplace_back(account);
        }
        return ans;
    }
};