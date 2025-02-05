#include <queue>
#include <string>
using namespace std;

class Trie { // instead of queue you can use a runner node like iterating a
             // Linked List
private:
  struct s_Trie {
    char val;
    bool end;
    s_Trie *neighbours[26];

    s_Trie(char c) {
      this->val = c;
      this->end = 0;

      for (int i = 0; i < 26; i++) {
        this->neighbours[i] = nullptr;
      }
    }
  };

private:
  s_Trie *trie;

public:
  Trie() { this->trie = new s_Trie('\0'); }

  void insert(string word) {
    queue<s_Trie *> q;
    q.push(this->trie);

    for (const char &c : word) {
      s_Trie *curr = q.front();
      q.pop();

      if (!curr->neighbours[c - 'a']) {
        curr->neighbours[c - 'a'] = new s_Trie(c);
      }

      q.push(curr->neighbours[c - 'a']);
    }

    s_Trie *curr = q.front();
    q.pop();
    curr->end = 1;
  }

  bool search(string word) {
    queue<s_Trie *> q;
    q.push(this->trie);

    for (const char &c : word) {
      s_Trie *curr = q.front();
      q.pop();

      if (!curr->neighbours[c - 'a'])
        return 0;
      q.push(curr->neighbours[c - 'a']);
    }

    s_Trie *curr = q.front();
    q.pop();

    return curr->end;
  }

  bool startsWith(string prefix) {
    queue<s_Trie *> q;
    q.push(this->trie);

    for (const char &c : prefix) {
      s_Trie *curr = q.front();
      q.pop();

      if (!curr->neighbours[c - 'a'])
        return 0;
      q.push(curr->neighbours[c - 'a']);
    }

    return 1;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
