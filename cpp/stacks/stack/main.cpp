#include <QCoreApplication>
#include "Stack.h"
#include <QDebug>

bool isBalanced(const char *expression){
  Stack stack;

  for(int i = 0; expression[i] != NULL; i++){
      if(expression[i] == '(')
        stack.push(expression[i]);
      else if(expression[i] == ')'){
          if(stack.isEmpty())
            return false;
          stack.pop();
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

  qDebug() << "Is balanced: " << isBalanced(formula);


  return a.exec();
}
