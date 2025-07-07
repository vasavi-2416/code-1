#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    bool running = true;

    cout << "Simple Calculator\n";
   
    while (running) {
        // Get first number
        cout << "\nEnter first number: ";
        cin >> num1;

        // Get second number
        cout << "Enter second number: ";
        cin >> num2;

        // Get operation
        cout << "Choose operation (+, -, *, /) or q to quit: ";
        cin >> op;

        if (op == 'q' || op == 'Q') {
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        switch (op) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << result << "\n";
                break;

            case '-':
                result = num1 - num2;
                cout << "Result: " << result << "\n";
                break;

            case '*':
                result = num1 * num2;
                cout << "Result: " << result << "\n";
                break;

            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << "\n";
                }
                break;

            default:
                cout << "Invalid operation. Please choose +, -, *, / or q.\n";
        }
    }

    return 0;
} 
