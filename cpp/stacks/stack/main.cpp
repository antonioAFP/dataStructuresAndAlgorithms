#include <QCoreApplication>
#include "Stack.h"
#include <QDebug>

bool isBalanced(const char *expression){
  Stack stack;

  for(int i = 0; expression[i] != NULL; i++){
      if(expression[i] == '(' ||
         expression[i] == '{' ||
         expression[i] == '[' )
        stack.push(expression[i]);
      else if(expression[i] == ')' ||
              expression[i] == '}' ||
              expression[i] == ']'){
          if(stack.isEmpty())
            return false;
          int opening = stack.pop();
          if( (opening == '(' && expression[i] != ')') ||
              (opening == '{' && expression[i] != '}') ||
              (opening == '[' && expression[i] != ']') )
            return false;
        }
  }

  return stack.isEmpty() ? true : false;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Stack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.display();

  qDebug() << "Pop: " << stack.pop();

  stack.display();

  char *formula = "((a+b)*(c+d))";
  qDebug() << formula << "Is balanced: " << isBalanced(formula);

  char *formula1 = "{([a+b])*[c-d]/e}";
  qDebug() << formula1 << " Is balanced: " << isBalanced(formula1);

  char *formula2 = "{([a+b))*[c-d]/e}";
  qDebug() << formula2 << " Is balanced: " << isBalanced(formula2);

  return a.exec();
}
