#include <iostream>
#include <deque>
#include <stack>

// Mirror a deque and append to it.
// Example: {'a', 'b', 'c'} => {'a', 'b', 'c', 'c', 'b', 'a'}
// Time complexity: O(n), where n is the size of deque.
// Space complexity: O(n).
void Mirror(std::deque<char>& deque) {
  std::stack<char> stack;

  // Pop & push back to deque and use stack to collect reverse items.
  auto size = deque.size();
  for (unsigned int i = 0; i < size; i++) {
    auto x = deque.front();
    stack.push(x);
    deque.pop_front();
    deque.push_back(x);
  }

  // Pop stack to push back reverse items to deque.
  while (!stack.empty()) {
    auto x = stack.top();
    stack.pop();
    deque.push_back(x);
  }
}

int main() {
    std::deque<char> deque;
    deque.push_back('a');
    deque.push_back('b');
    deque.push_back('c');

    Mirror(deque);

    for (auto x : deque)
      std::cout << x << std::endl;

    return 0;
}
