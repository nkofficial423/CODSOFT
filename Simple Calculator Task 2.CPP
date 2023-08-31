#include <iostream>

using namespace std;

int main() {
  int number1, number2;
  char operator;

  cout << "Welcome to the calculator!" << endl;

  cout << "Enter the first number: ";
  cin >> number1;

  cout << "Enter the second number: ";
  cin >> number2;

  cout << "Choose an operation (+, -, *, /): ";
  cin >> operator;

  switch (operator) {
    case '+':
      cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
      break;
    case '-':
      cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
      break;
    case '*':
      cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
      break;
    case '/':
      cout << number1 << " / " << number2 << " = " << number1 / number2 << endl;
      break;
    default:
      cout << "Invalid operator." << endl;
      break;
  }

  return 0;
}
