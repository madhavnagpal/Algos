class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> wordList)
  {
    if (!beginWord.size() or !endWord.size() or !wordList.size())
      return 0;
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    int ans = 0, n = beginWord.size();

    while (!q.empty())
    {
      ans++;
      int initial_size = q.size();
      while (initial_size--)
      {
        string curr = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
          char old = curr[i];
          for (char ch = 'a'; ch <= 'z'; ch++)
          {
            curr[i] = ch;
            if (s.find(curr) == s.end())
              continue;
            if (curr == endWord)
              return ans + 1;
            q.push(curr);
            s.erase(curr);
          }
          curr[i] = old;
        }
      }
    }
    return 0;
  }
};