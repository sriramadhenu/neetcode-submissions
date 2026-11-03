class Solution {
public:
    bool isOneLetterAway(string a, string b){
        int difference = 0;
        for (int i = 0; i < a.size(); i++){
            if (a[i] != b[i]) difference++;
            if (difference > 1) return false;
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // think of this as a minimumcost change
        // cost + 1 for each swap
        // bfs
        // endWord must exist in wordList
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (beginWord == endWord || it == wordList.end()) return 0;

        unordered_map<string, vector<string>> adjList;
        for (int i = 0; i < wordList.size() - 1; i++){
            for (int j = i + 1; j < wordList.size(); j++){
                if (isOneLetterAway(wordList[i], wordList[j])){
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // push every word in wordList that is one letter away from the current word
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        for (int i = 0; i < wordList.size(); i++){
            if (isOneLetterAway(beginWord, wordList[i])){
                q.push({wordList[i], 2});
                visited.insert(wordList[i]);
            }
        }

        while (!q.empty()){
            auto t = q.front();
            string currWord = t.first;
            int cost = t.second;
            q.pop();
            if (currWord == endWord) return cost;
            for (auto& str : adjList[currWord]){
                if (!visited.contains(str)){
                    q.push({str, cost + 1});
                    visited.insert(str);
                }
            }
        }

        return 0;
    }
};
