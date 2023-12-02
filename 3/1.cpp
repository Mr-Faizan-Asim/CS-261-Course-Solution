
// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// bool isOperator(char ch) {
//     return ch == '+' || ch == '-' || ch == '*' || ch == '/';
// }

// int getPrecedence(char op) {
//     if (op == '*' || op == '/') {
//         return 2;
//     } else if (op == '+' || op == '-') {
//         return 1;
//     }
//     return 0;
// }

// string infixToPostfix(const string& infix) {
//     stack<char> operators;
//     string postfix = "";
    
//     for (char c : infix) {
//         if (isalnum(c)) {
//             postfix += c;
//         } else if (c == '(') {
//             operators.push(c);
//         } else if (c == ')') {
//             while (!operators.empty() && operators.top() != '(') {
//                 postfix += ' ';
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             if (!operators.empty() && operators.top() == '(') {
//                 operators.pop(); // Pop the opening parenthesis
//             }
//         } else if (isOperator(c)) {
//             while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(c)) {
//                 postfix += ' ';
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             operators.push(c);
//         }
//     }
    
//     while (!operators.empty()) {
//         postfix += ' ';
//         postfix += operators.top();
//         operators.pop();
//     }
    
//     return postfix;
// }

// int main() {
//     string infixExpression;
//     cout << "Enter an infix expression: ";
//     getline(cin, infixExpression);

//     string postfixExpression = infixToPostfix(infixExpression);

//     cout << "Postfix: " << postfixExpression << endl;

//     return 0;
// }

// // #include<iostream>
// // #include<stack>
// // #include<string>
// // #include<algorithm>
// // using namespace std;

// // bool checkOperator(char ch)
// // {
// //     string arr = "+-()*/";
// //     for(char c : arr)
// //     {
// //         if(ch == c)
// //         {
// //             return true;
// //         }
// //     }
// //     return false;
// // }
// // int precidenceChecker(char c)
// // {
// //     if (c == '*' || c == '/') {
// //         return 2;
// //     } else if (c == '+' || c == '-') {
// //         return 1;
// //     }
// //     return 0;
// // }
// // string postfixer(string infinix)
// // {
// //     stack<char> oper;
// //     string postfix = "";
// //     for(char c : infinix)
// //     {
        
// //         if(!checkOperator(c))
// //         {
// //             postfix+=c;
// //         }
// //         else if(checkOperator(c) && c != ')')
// //         {
// //             oper.push(c);
// //         }
// //         else if(c == ')')
// //         {
// //             while(oper.top() != '(')
// //             {
// //                 postfix += oper.top();
// //                 oper.pop();
// //             }
// //             oper.pop();
// //         }
// //         else {
// //             while (!oper.empty() && precidenceChecker(oper.top()) >= precidenceChecker(c)) {
// //                 postfix += oper.top();
// //                 oper.pop();
// //             }
// //             oper.push(c);
// //         }
// //     }
// //     while(!oper.empty())
// //     {
// //         postfix += oper.top();
// //         oper.pop();
// //     }
// //     return postfix;
// // }

// // string Prefix(string infix)
// // {
// //     string rev = infix;
// //     reverse(rev.begin(),rev.end());
    
// //     for(char c : rev)
// //     {
// //         if(c == '(')
// //         {
// //             c = ')';
// //         }
// //         else if(c==')')
// //         {
// //             c = '(';
// //         }
// //     }

// //     string res = postfixer(rev);
// //     reverse(res.begin(),res.end());

// //     return res;
// // }

// // int main()
// // {
// //     cout<< Prefix("5*(6+2)/4");

// //     return 0;
// // }


// #include <iostream>
// #include <stack>
// #include <string>
// #include <algorithm>
// using namespace std;

// bool isOperator(char ch) {
//     return ch == '+' || ch == '-' || ch == '*' || ch == '/';
// }

// int getPrecedence(char op) {
//     if (op == '*' || op == '/') {
//         return 2;
//     } else if (op == '+' || op == '-') {
//         return 1;
//     }
//     return 0;
// }

// string infixToPostfix(const string& infix) {
//     stack<char> operators;
//     string postfix = "";
//     for (char c : infix) {
//         if (!isOperator(c) && c != '(' && c != ')') {
//             postfix += c;
//         } else if (c == '(') {
//             operators.push(c);
//         } else if (c == ')') {
//             while (!operators.empty() && operators.top() != '(') {
//                 postfix += ' ';
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             if (!operators.empty() && operators.top() == '(') {
//                 operators.pop(); // Pop the opening parenthesis
//             }
//         } else {
//             while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(c)) {
//                 postfix += ' ';
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             operators.push(c);
//         }
//     }
//     while (!operators.empty()) {
//         postfix += ' ';
//         postfix += operators.top();
//         operators.pop();
//     }
//     return postfix;
// }

// string infixToPrefix(const string& infix) {
//     string reversedInfix = infix;
//     reverse(reversedInfix.begin(), reversedInfix.end());

//     for (char& c : reversedInfix) {
//         if (c == '(') {
//             c = ')';
//         } else if (c == ')') {
//             c = '(';
//         }
//     }

//     string reversedPostfix = infixToPostfix(reversedInfix);
//     reverse(reversedPostfix.begin(), reversedPostfix.end());

//     return reversedPostfix;
// }

// int main() {
//     string infixExpression;
//     cout << "Enter an infix expression: ";
//     getline(cin, infixExpression);

//     // Remove spaces from the infix expression
//     infixExpression.erase(remove_if(infixExpression.begin(), infixExpression.end(), ::isspace), infixExpression.end());

//     string postfixExpression = infixToPostfix(infixExpression);
//     string prefixExpression = infixToPrefix(infixExpression);

//     cout << "Prefix: " << prefixExpression << endl;
//     cout << "Postfix: " << postfixExpression << endl;

//     return 0;
// }

