#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


vector<string> inputExpr()
{
    vector<string> vector;
    string value ;

    do
    {
        cout << "Veuillez saisir votre expression element par element (appuyez sur \"!\" pour indiquer la fin) : " ;
        getline(cin, value);
        if(value != "!")
        {
            vector.push_back(value);
        }
        cout << endl ;
    }
    while(value != "!");

    //for(int i = 0 ; i < int(vector.size()) ; i++)
    //{
    //    cout << vector[i] ;
    //}

    return vector ;
}

int returnResult(vector<string> inputExpr)
{

    stack<int> numbers;

    for(unsigned int i = 0 ; i < inputExpr.size() ; i++)
    {
        if(inputExpr[i] != "+" && inputExpr[i] != "-" &&  inputExpr[i] != "/" &&  inputExpr[i] != "*" )
        {
            numbers.push(stoi(inputExpr[i]));
        }
        else
        {
            int nb1 = numbers.top();
            numbers.pop();
            int nb2 = numbers.top();
            numbers.pop();
            if (inputExpr[i] == "+")
            {
                numbers.push(nb2 + nb1);
            }
            else if (inputExpr[i] == "-")
            {
                numbers.push(nb2 - nb1);
            }
            else if (inputExpr[i] == "*")
            {
                numbers.push(nb2 * nb1);
            }
            else if (inputExpr[i] == "/")
            {
                numbers.push(nb2 / nb1);
            }
        }
    }
    cout << endl << numbers.top();
    return numbers.top();
}



int main()
{
    returnResult(inputExpr());
    //inputExpr();
    return 0;
}
