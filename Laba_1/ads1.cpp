#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidExpression(const string& s) 
{
    stack<char> st;
    
    for (char c : s) 
    {
        if (c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') 
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);    
            else 
            {
                if (st.empty())
                    return false;

                 // Извлекаем верхний элемент из стека (последнюю открывающую скобку)
                char top = st.top();
                st.pop();

                // Проверяем соответствие пары для открывающейся скобки
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                    return false; 
            }
        }
        else 
        {
            // Если найден любой символ, не являющийся скобкой
            return false;
        }
    }

    return st.empty();
}

int main() 
{
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    if (input.empty())
        cout << "Строка не существует" << endl;
    else 
    {
        if (isValidExpression(input))
            cout << "Строка существует" << endl;
        else
            cout << "Строка не существует" << endl;
    }
}