#include <iostream>
#include <string>
#include <stack>

/*
int main(void) {
    std::string input;
    std::cin >> input;
    int n = 0;
    std::stack<char> s;
    for(char c:input) {
        if(c == '(') {
            s.push('(');
            n++;
        }
        else if(c == ')') {
            s.pop();
            n--;
            n += s.size();
        }
        std::cout << n;
    }
    
    return 0;
}
(((()(()()))(())()))(()())
*/

int main(void) {
    std::string input;
    std::cin >> input;
    int stacks = 0;
    int num = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '(') {
            if(input[i+1] == ')') {
                num += stacks;
                i++;
            }
            else stacks++;
        }
        else if(input[i] == ')') {
            num++;
            stacks--;
        }
    }
    std::cout << num;
    return 0;
}