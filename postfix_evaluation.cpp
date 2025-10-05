#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int applyOperator(char op, int a, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluatePostfix(string expr)
{
    stack<int> S;

    for (char ch : expr)
    {
        if (isspace(ch)) continue; // skip spaces
        
        if (isdigit(ch))
        {
            S.push(ch - '0'); // push number
        }
        else
        {
            int op2 = S.top(); S.pop();
            int op1 = S.top(); S.pop();
            int result = applyOperator(ch, op1, op2);
            S.push(result);
        }
    }

    return S.top();
}

int main()
{
    string postfix = "1234*+5-"; // Example: 1 + (2 * 3 * 4) - 5
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
