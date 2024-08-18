#ifndef __EXPR__
#define __EXPR__

#include <iostream>
#include <stack>
using namespace std;

namespace expr
{
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    char associativity(char c)
    {
        if (c == '^')
            return 'R';
        else
            return 'L';
    }
    string infixToPostfix(string infix)
    {
        string postfix{};
        stack<char> st;

        for (char c : infix)
        {
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
                postfix += c;
            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence(c) < precedence(st.top()) ||
                       !st.empty() && precedence(c) == precedence(st.top()) &&
                           associativity(c) == 'L')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
    string postfixToPrefix(string postfix)
    {
        stack<string> stack;
        string res;
        for (int i = 0; i < postfix.size(); i++)
        {
            char c = postfix[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                string op(1, c);
                stack.push(op);
            }
            else
            {
                string str1 = stack.top();
                stack.pop();
                string str2 = stack.top();
                stack.pop();
                stack.push(c + str2 + str1);
            }
        }
        return stack.top();
    }
    string reversePrefix(string infix)
    {
        cout << "at reversePrefix " << infix << "\n";
        string res;
        for (int i = infix.size(); i >= 0; i--)
        {
            if (infix[i] == '(')
                res += ')';
            else if (infix[i] == ')')
                res += '(';
            else
                res += infix[i];
        }
        return res;
    }
    string infixToPrefix(string infix)
    {
        string postfix = infixToPostfix(infix);
        return postfixToPrefix(postfix);
    }

    string prefixToInfix(string prefix)
    {
        stack<string> stack;
        string res;
        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            char c = prefix[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            { //|| (c >= '0' && c<= '9')){
                string op(1, c);
                stack.push(op);
                // continue;
            }
            else
            {
                string st1 = stack.top();
                stack.pop();
                string st2 = stack.top();
                stack.pop();
                stack.push("(" + st1 + c + st2 + ")");
            }
        }
        return stack.top();
        // return reversePrefix(stack.top());
    };
    string postfixToInfix(string postfix)
    {
        stack<string> stack;
        string res;
        for (char c : postfix)
        {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            { //|| (c >= '0' && c<= '9')){
                string op(1, c);
                stack.push(op);
                continue;
            }
            string st1 = stack.top();
            stack.pop();
            string st2 = stack.top();
            stack.pop();
            stack.push("(" + st1 + c + st2 + ")");
        }
        return reversePrefix(stack.top());
    }
    string prefixToPostfix(string prefix)
    {
        stack<string> stack;
        string res;
        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            char c = prefix[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                string op(1, c);
                stack.push(op);
            }
            else
            {
                string str1 = stack.top();
                stack.pop();
                string str2 = stack.top();
                stack.pop();
                stack.push(str1 + str2 + c);
            }
        }
        return stack.top();
    }
};
#endif