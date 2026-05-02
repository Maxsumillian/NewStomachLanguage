#include "StomachLang.h"

int main() {
// Example code using my Stomach Lang
    //Built a simple Caculator
    Calorie a, b, result;// decleration
    Calorie choice;
    Edible loop = true;

    while (loop == true)// small limitation Edible does not return Bool
        //Workaround would be to make my own "while" class that takes in Ebible class
        //Or overload the while loop to add Edible to it.
    {
        StomachLang::poop() << "\n===== StomachLang Calculator =====";//Example of My cout [StomachLang::poop() << "string"]
        StomachLang::poop() << "\n1. Add";
        StomachLang::poop() << "\n2. Subtract";
        StomachLang::poop() << "\n3. Multiply";
        StomachLang::poop() << "\n4. Divide";
        StomachLang::poop() << "\n5. Exit";
        StomachLang::poop() << "\nChoose option:";

        StomachLang::eat() >> choice;//Example of My cin "StomachLang::eat() >> [varible]"

        if (choice == 5)// example of comparison of Edible to Int
        {
            StomachLang::poop() << "\nExiting calculator...";
            break;

        }

        Calorie choiceOne = 1;
        Calorie choiceFive = 5;

        // if (choice < 1 || choice > 5)
        if (choice < choiceOne || choice > choiceFive){//example of comparison operators using my INT
            StomachLang::poop() << "\nInvalid option";
        }

        StomachLang::poop() << "\nEnter first value:";
        StomachLang::eat() >> a;

        StomachLang::poop() << "\nEnter second value:";
        StomachLang::eat() >> b;



        // if (choice == choiceOne)// example of comparison Edible to Edible
        if (choice == choiceOne)
        {
            result = a + b; // example of overloaded= and overloaded+ as well as chaining
            StomachLang::poop() << a <<" + " << b <<" = " << result;// example of chaining in my custom cout
        }
        else if (choice == 2)
        {
            result = a - b;
            StomachLang::poop() << a <<" - " << b <<" = " <<  result;
        }
        else if (choice == 3)
        {
            result = a * b;
            StomachLang::poop() << a <<" * " << b <<" = " <<  result;
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
                StomachLang::poop() << a <<" / " << b <<" = " <<  result;
            }
        }
        else
        {
            StomachLang::poop() << "\nExiting calculator...";
            break;
        }
    }

    Calorie myCalorie = 0;
    Foods myFood = "Test Food";
    myFood = myFood + myCalorie;//not possible
    myFood = myFood - myCalorie;//example of error messeges


    Edible test = 100;// this compiles but is all wrong
    bool testing = 199;// its beacuse this is allowed for some reason...
    std::cout << testing << std::endl;


    return 0;
}
