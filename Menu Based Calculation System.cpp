/*
This is a Calculator. Initially, it displays a main menu to choose the calculator type. If a user chooses Standard calculator, then a menu appears for standard calculator options. Tf a user choose Scientific calculator, then a menu appears for scientific calculator options and the last option is to Quit.

In standard calculator, options are to add, subtract, multiply etc. and in scientific calculator , options are power, factorial, square root, etc.

In this program, preprocessors are defined for new calculation and old calculation. New calculation will accept an operand whereas in old calculation, one operands is already assumed from the result of the previous calculation.

Exception handling is not implemented in this project, so do not enter a string when system asks you for a number.
*/

// File including and preprocessor declaration

#include <iostream>
#include <math.h>
#include <stdlib.h>

#define new_cal 1
#define old_cal 0

using namespace std;

// stand_cal class to define standard calculator functions
class stand_calc
{
    /*
    Protyping of standard calculator functions. These functions are static, therefore calling of these functions is possible with the name of the class. There is no need to create an object of the class.
    */
public:
    static double addition(double, double);
    static double subtract(double, double);
    static double multiplication(double, double);
    static double division(double, double *);
    static double modulus(double *, double *);
};

// scien_calc class to define scientific calculator functions
class scien_calc
{
public:
    static double power(double, double);
    static long int fact(double);
    static double square(double);
    static double cube(double);
    static double sq_root(double);
    static double sin_func(double);
    static double cos_func(double);
    static double tan_func(double);
};

// addition function will add two numbers

double stand_calc::addition(double a, double b)
{
    return a + b;
}

// subtract function will subtract two numbers
double stand_calc::subtract(double a, double b)
{
    return a - b;
}

// multiplication function will multiply two numbers

double stand_calc::multiplication(double a, double b)
{
    return a * b;
}

/*Division function will first number by the second number. This function accepts two arguments, one is copy of a variable and another is a pointer type because if accepting divisor is zero, then this function will show a message to enter the divisor again. Using pointer means that the entered value of the divisor for this function should be updated at the main function also.*/

double stand_calc::division(double a, double *b)
{
    while (*b == 0)
    {
        cout << "Error: Division by zero. Enter a non-zero number." << endl;
        cin >> *b;
    }
    return a / *b;
}

/*Modulus function will will divide the first number by the second number and return the remainder part of the division. Similar to division function, it will not accept zero in the divisor. Modulus cannot be performed on a double number, so we need to convert it into an integer.*/

double stand_calc::modulus(double *a, double *b)
{
    while (*b == 0)
    {
        cout << "Error: Division by zero. Enter a non-zero number." << endl;
        cin >> *b;
    }
    // Converting double into a Integer
    int temp_a = (int)*a;
    int temp_b = (int)*b;
    if (*a - temp_a > 0 || *b - temp_b > 0)
    {
        cout << "\nConverting decimal number into an integer to perform modulus";
    }
    *a = temp_a;
    *b = temp_b;
    return temp_a % temp_b;
}

// Declaration of scien_calc class functions starts from here.
// Square function of scien_calc class to return accepting number to the power 2

double scien_calc::square(double a)
{
    return (pow(a, 2));
}

// Cube function of scien_calc class to return accepting number to the power 3

double scien_calc::cube(double a)
{
    return (pow(a, 3));
}

// Square root function of scien_calc class to return square root of accepting number

double scien_calc::sq_root(double a)

{
    return (sqrt(a));
}

// Power function of scien_calc class to return accepting number to the power of second number

double scien_calc::power(double a, double b)
{
    return (pow(a, b));
}

/* Fact function of the scien_calc class to return a long integer as factorial of an accepting number. This will covert accepting number into an integer to perform factorial operation. */
long int scien_calc::fact(double a)
{
    int temp_a = (int)a;
    long int fact = 1;
    if (temp_a < 0)
    {
        cout << "\nError: Factorial is not defined for negative numbers";
        return 0;
    }
    else if (temp_a == 0 || temp_a == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= temp_a; i++)
        {
            fact *= i;
        }
        return fact;
    }
}

// sin_func function of scien_calc class to return sine value of x

double scien_calc::sin_func(double x)
{
    return (sin(x));
}

// cos_func function of scien_calc class to return cosine value of x

double scien_calc::cos_func(double x)
{
    return (cos(x));
}

// tan_func function of scien_calc class to return tangent value of x

double scien_calc::tan_func(double x)
{
    return (tan(x));
}

// Displaying the menus to enter the options and values
void main()
{
    double num1, num2, num3, num4, temp;
    int choice_1 = 0, choice_2, flag;
    // Loop of main menu from where the program starts. It will show the menu to choose the type of calculator.
    do
    {
        clrscr();
        cout << "__________Type of Calculators__________\n";
        cout << "\n1\tStandard Calculator";
        cout << "\n2\tScientific Calculator";
        cout << "\n3\tQuit";
        cout << "\n\nEnter your choice of calculator: ";
        cin >> choice_1;
        flag = new_cal;
        // To perform an operation according to the entered option in the main menu of the calculator.
        switch (choice_1)
        {
        case 1:
            // Loop to display the standard calculator menu
            do
            {
                clrscr();
                cout << "__________Standard Calculator__________\n";
                cout << "\n1\tAddition";
                cout << "\n2\tSubtraction";
                cout << "\n3\tMultiplication";
                cout << "\n4\tDivision";
                cout << "\n5\tModulus";
                cout << "\n6\tBack to Main Menu";
                cout << "\n7\tQuit";
                // Option 8 will be displayed only when working on old calculations. Here, already a number is saved in the calculator memory.
                if (flag == old_cal)
                {
                    cout << "\n8\tClear Memory";
                }
                cout << "\n\nEnter your choice of calculator: ";
                cin >> choice_2;
                // To perform operation and call functions of the stand_calc class
                switch (choice_2)
                {
                case 1:
                    // If a new calculation is there, then accept the first number else previous calculation result will be the first number.
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the first number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number: " << num1 << endl;
                    }
                    cout << "\nEnter the second number: ";
                    cin >> num2;
                    num3 = stand_calc::addition(num1, num2);
                    cout << "\nAddition of " << num1 << " and " << num2 << " is " << num3 << endl;
                    cout << "Press any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 2:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the first number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number: " << num1 << endl;
                    }
                    cout << "\nEnter the second number: ";
                    cin >> num2;
                    num3 = stand_calc::subtract(num1, num2);
                    cout << "\nSubtraction of " << num2 << " and " << num1 << " is " << num3 << endl;
                    cout << "Press any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 3:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the first number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number: " << num1 << endl;
                    }
                    cout << "\nEnter the second number: ";
                    cin >> num2;
                    num3 = stand_calc::multiplication(num1, num2);
                    cout << "\nMultiplication of " << num1 << " and " << num2 << " is " << num3 << endl;
                    cout << "Press any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 4:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the first number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number: " << num1 << endl;
                    }
                    cout << "\nEnter the second number: ";
                    cin >> num2;
                    num3 = stand_calc::division(num1, &num2);
                    cout << "\nDivision of " << num1 << " by " << num2 << " is " << num3 << endl;
                    cout << "Press any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 5:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the first number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number: " << num1 << endl;
                    }
                    cout << "\nEnter the second number: ";
                    cin >> num2;
                    num3 = stand_calc::modulus(&num1, &num2);
                    cout << "\nModulus of " << num1 << " by " << num2 << " is " << num3 << endl;
                    cout << "Press any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 6:
                    cout << "\nReturning to previous menu.";
                    cout << "Press any key to continue...";
                    getch();
                    break;
                case 7:
                    cout << "\nQuitting the program.";
                    cout << "\nPress any key to continue...";
                    getch();
                    exit(0);
                case 8:
                    // If a new calculation is going on then 8 option is an invalid option, else 8 is an option to start a new calculation.
                    if (flag == new_cal)
                    {
                        cout << "\nError: Clear Memory option is not available in a new calculation.";
                        cout << "\nPress any key to continue...";
                        getch();
                    }
                    else
                    {
                        temp = 0;
                        cout << "\nMemory cleared.";
                        cout << "\nPress any key to continue...";
                        getch();
                        flag = new_cal;
                    }
                    break;
                default:
                    cout << "\nInvalid option. Please try again.";
                    cout << "\nPress any key to continue...";
                    getch();
                    break;
                }
            } while (choice_2 != 6);
            break;
        case 2:
            // Loop to display the scientific calculator menu
            do
            {
                clrscr();
                cout << "__________Scientific Calculator__________\n";
                cout << "\n1\tSquare";
                cout << "\n2\tCube";
                cout << "\n3\tPower";
                cout << "\n4\tFactorial";
                cout << "\n5\tSin";
                cout << "\n6\tCos";
                cout << "\n7\tTan";
                cout << "\n8\tReturn to Main Menu";
                cout << "\n9\tQuit the program";

                if (flag == old_cal)
                {
                    cout << "\n10\tClear Memory";
                }
                cout << "\n\nEnter your choice of calculator: ";
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the number to find its Square: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber is: " << num1 << endl;
                    }
                    num3 = scien_calc::square(num1);
                    cout << "\nSquare of " << num1 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 2:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the number to find its Cube: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber is: " << num1 << endl;
                    }
                    num3 = scien_calc::cube(num1);
                    cout << "\nCube of " << num1 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 3:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the base number: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number is: " << num1 << endl;
                    }
                    cout << "\nEnter second number for power to find power: ";
                    cin >> num2;
                    num3 = scien_calc::power(num1, num2);
                    cout << "\n"
                         << num1 << " raised to the power of " << num2 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 4:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the number to find its Factorial: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber to find Factorial is: " << num1 << endl;
                    }
                    long int num4 = scien_calc::fact(num1);
                    cout << "\nFactorial of " << num1 << " is: " << num4 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num4;
                    flag = old_cal;
                    break;
                case 5:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the Sin value: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nSin value is: " << num1 << endl;
                    }
                    num3 = scien_calc::sin_func(num1);
                    cout << "\nSin of " << num1 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 6:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the Cos value: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nCos value is: " << num1 << endl;
                    }
                    num3 = scien_calc::cos_func(num1);
                    cout << "\nCos of " << num1 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 7:
                    if (flag == new_cal)
                    {
                        cout << "\nEnter the Tan value: ";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nTan value is: " << num1 << endl;
                    }
                    num3 = scien_calc::tan_func(num1);
                    cout << "\nTan of " << num1 << " is: " << num3 << endl;
                    cout << "\nPress any key to continue...";
                    getch();
                    temp = num3;
                    flag = old_cal;
                    break;
                case 8:
                    cout << "\nReturning to previous menu.";
                    cout << "\nPress any key to continue...";
                    getch();
                    break;
                case 9:
                    cout << "\nQuitting the program.";
                    cout << "\nPress any key to continue...";
                    getch();
                    exit(0);
                case 10:
                    if (flag == new_cal)
                    {
                        cout << "\nInvalid choice.";
                        cout << "\nPress any key to continue...";
                        getch();
                    }
                    else
                    {
                        temp = 0;
                        flag = new_cal;
                    }
                    break;
                default:
                    cout << "\nInvalid option. Please try again.";
                    cout << "\nPress any key to continue...";
                    getch();
                    break;
                }
            } while (choice_2 != 8);
            break;
        case 3:
            cout << "\nQuitting the program.";
            cout << "\nPress any key to continue...";
            getch();
        default:
            cout << "\nInvalid option. Please try again.";
            cout << "\nPress any key to continue...";
            getch();
            break;
        }
    } while (choice_1 != 3);
}