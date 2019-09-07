#include <iostream>
#include <map>
#include <stack>
#include <string>

bool ValideParentheses(std::string s) {
  // Valide parentheses.
  //
  // Time complexity: O(n), where n is the lenght of s.
  // Space complexity: O(n).
  std::string opens = "([{";
  std::string closes = ")]}";

  std::map<char, char> open_close_map = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
  };

  // Use stack to collect open parentheses.
  std::stack<char> stack;

  for (char& c : s) {
    // Check if char is open parentheses. 
    if (opens.find(c) != std::string::npos) {
      stack.push(c);
      continue;
    }
    
    // Check if char is close parentheses. 
    if (closes.find(c) != std::string::npos) {
      // Check if there is open parentheses, return not valid.
      if (stack.empty())
        return false;

      // If yes, store stack top and compare close parentheses.
      char open_c = stack.top();
      stack.pop();

      if (c != open_close_map[open_c])
        return false;
    }
  }

  // Finally check is there are open parentheses remaining.
  if (stack.empty())
    return true;
  else
    return false;
} 

int main() {
  // Ans: true
  std::string s = "(abcd)";
  std::cout << std::boolalpha << ValideParentheses(s) << std::endl;

  // Ans: true
  s = "([(a)bcd]{ef}g)";
  std::cout << std::boolalpha << ValideParentheses(s) << std::endl;

  // Ans: false
  s = "(ab{c}d]";
  std::cout << std::boolalpha << ValideParentheses(s) << std::endl;

  return 0;
}
