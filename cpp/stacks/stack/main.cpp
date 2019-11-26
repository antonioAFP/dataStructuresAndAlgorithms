#include <QCoreApplication>
#include "Stack.h"
#include <QDebug>

/* Check if a expression is parenthesis balanced,
    example: ((a+b)*(c+d))  == true
*/
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

bool isOperand(char x){
  if(x == '+' || x == '-' ||
     x == '*' || x == '/')
    return false;
  else
    return true;
}

int precedence(char x){
   if(x == '+' || x == '-')
     return 1;
   else if(x == '*' || x == '/')
     return 2;
   else
     return 0;
}

char * toPostFix(char *infix){
  Stack stack;
  char *postfix = new char[strlen(infix) + 1];

  int i = 0;
  int j = 0;

  while(infix[i] != NULL){
      if(isOperand(infix[i]))
        postfix[j++] = infix[i++];
      else {
          if(precedence(infix[i]) > precedence(stack.stackTop()))
            stack.push(infix[i++]);
          else
            postfix[j++] = stack.pop();
        }
    }

  while (!stack.isEmpty()) {
      postfix[j++] = stack.pop();
    }

  postfix[j] = NULL;

  return  postfix;
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

  char *infix = "a+b*c";
  qDebug() << infix << " to postfix : " << toPostFix(infix);

  char *infix1 = "a+b*c-d/e";
  qDebug() << infix1 << " to postfix : " << toPostFix(infix1);

  return a.exec();
}
