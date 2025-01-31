#include <string>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size())
      return 0;

    int cnt['z' + 1]{0};

    for (int i = 0; i < magazine.size(); i++) {
      if (i < ransomNote.size())
        cnt[ransomNote[i]]++;

      cnt[magazine[i]]--;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
      if (cnt[ransomNote[i]] > 0)
        return 0;
    }

    return 1;
  }
};
