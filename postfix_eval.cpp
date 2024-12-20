//Project 2 Bianca Amoako
#include <iostream> //input output library
#include <string> //string library
#include <stack> //stack library

using namespace std; //using namepace for std::

// Function that evaluates postfix expressuion from user
int evalPostfix(string exp)
{
    //check if NOT postfix/letter variable
    string::iterator it = exp.end()-1;
    if(*it != '+' && *it != '-' && *it != '*' && *it != '/' && *it !=(*it >='a' && *it<='z')){
        cout << "Cannot Evaluate Expression - ERROR \n";
        return 0;
    }
    // creates empty stack
    stack<int> stack;
    
    // traverses given expression
    for (char c : exp)
    {
        // if current character is a operand then push it into stack
        if (c >= '0' && c <= '9') {
            stack.push(c - '0');
        }
        // if current character is a operator
        else if (stack.size() > 1){
            // remove top 2 elements from the stack
            int x = stack.top();
            stack.pop();
            
            int y = stack.top();
            stack.pop();
            
            // evaluate expression 'x op y', and push the
            // result back to the stack
            switch (c) {
                case '+':
                    stack.push(y + x);
                    break;
                case '-':
                    stack.push(y - x);
                    break;
                case '*':
                    stack.push(y * x);
                    break;
                case '/':
                    stack.push(y / x);
                    break;
            }
        }
    }

    // At this point, the stack is left with only one element, i.e.,
    // expression result
    return stack.top();
}

int main() // int main driver
{
    cout << "Enter an expression: ";
    string exp; // THIS IS WHERE USER INPUTS THEIR EXPRESSION FOR EVALUATION
    cin >> exp;
    cout << evalPostfix(exp); // output of evalutation

    return 0; // return 0 end of program driver
}
