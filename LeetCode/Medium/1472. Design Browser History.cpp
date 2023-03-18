struct Node {
  Node* prev = nullptr;
  Node* next = nullptr;
  const string url;
  Node(const string& url) : url(url) {}
};
class BrowserHistory {
 private:
  Node* curr = nullptr;
 public:
  BrowserHistory(string homepage) {
    curr = new Node(homepage);
  }
  void visit(string url) {
    curr->next = new Node(url);
    curr->next->prev = curr;
    curr = curr->next;
  }

  string back(int steps) {
    while (curr->prev && steps--) {
      curr = curr->prev;
    }
    return curr->url;
  }
  string forward(int steps) {
    while (curr->next && steps--) {
      curr = curr->next;
    }
    return curr->url;
  }
};