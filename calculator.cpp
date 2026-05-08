#include <iostream>

using namespace std;

// Function to perform calculations
void calc(int num1, int num2, char op)
{
    if (op == '+')
    {
        cout << num1 << " + " << num2 << " = ";
        cout << num1 + num2;
    }

    else if (op == '-')
    {
        cout << num1 << " - " << num2 << " = ";
        cout << num1 - num2;
    }

    else if (op == '/')
    {
        // Prevent division by zero
        if (num2 == 0)
        {
            cout << "Syntax error";
        }
        else
        {
            cout << num1 << " / " << num2 << " = ";
            cout << static_cast<float>(num1) / num2;
        }
    }

    else if (op == '*')
    {
        cout << num1 << " * " << num2 << " = ";
        cout << num1 * num2;
    }

    else if (op == '%')
    {
        // Prevent modulo by zero
        if (num2 == 0)
        {
            cout << "Syntax error";
        }
        else
        {
            cout << num1 << " % " << num2 << " = ";
            cout << num1 % num2;
        }
    }

    else
    {
        cout << "Please enter a valid operation\n";
    }
}

int main()
{
    char option;

    do
    {
        // Display available operations
        cout << "Available operations:\n";
        cout << "+\n*\n-\n/\n%\n";

        int x, y;
        char z;

        cout << "Enter number 1: ";
        cin >> x;

        cout << "Enter number 2: ";
        cin >> y;

        cout << "Enter the operation type: ";
        cin >> z;

        calc(x, y, z);

        cout << "\nDo you want to make another operation? (y/n)\n";
        cin >> option;

    } while (option == 'y' || option == 'Y');

    cout << "Thanks for using the calculator!\n";

    return 0;
}
