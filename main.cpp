#include "StomachLang.h"

int main() {
// Example code using my Stomach Lang
    //Built a simple Caculator
    Calorie a, b, result;
    Calorie choice;

    while (true)
    {
        StomachLang::poop() << "\n===== StomachLang Calculator =====";
        StomachLang::poop() << "\n1. Add";
        StomachLang::poop() << "\n2. Subtract";
        StomachLang::poop() << "\n3. Multiply";
        StomachLang::poop() << "\n4. Divide";
        StomachLang::poop() << "\n5. Exit";
        StomachLang::poop() << "\nChoose option:";

        StomachLang::eat() >> choice;

        if (choice == 5)
        {
            StomachLang::poop() << "\nExiting calculator...";
            break;
        }

        if (choice < 1 || choice > 5) {
            StomachLang::poop() << "\nInvalid option";
        }

        StomachLang::poop() << "\nEnter first value:";
        StomachLang::eat() >> a;

        StomachLang::poop() << "\nEnter second value:";
        StomachLang::eat() >> b;

        if (choice == 1)
        {
            result = a + b;
            StomachLang::poop() << a <<" + " << b <<" = " << result;
        }
        else if (choice == 2)
        {
            result = a - b;
            StomachLang::poop() << result;
        }
        else if (choice == 3)
        {
            result = a * b;
            StomachLang::poop() << result;
        }
        else if (choice == 4)
        {
            if (b == 0)
            {
                StomachLang::poop() << "\nError: division by zero";
            }
            else
            {
                result = a / b;
                StomachLang::poop() << result;
            }
        }
        else
        {
            StomachLang::poop() << "\nExiting calculator...";
            break;
        }
    }

    return 0;
}
