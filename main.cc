#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

// Trying to make sure the screen clear is semi cross platform
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif


int menuSelection;
std::string ynAnswer;

// The main menu
void menu()
{
    //Clear the screen upon starting
    system(CLEAR);
    
    //Main menu
    std::cout << "\t Keep track of your tips, and other misc functions.\n\n" << std::endl;
    
    std::cout << "\t 1) Enter Today's Tips \t" 
        << "\t 2) Calculate Total \n\n"
        << "\t 3) Review Day \t\t" 
        << "\t 4) Reset records \n\n" 
        << "\t 5) Quit \n\n\n" << std::endl;

    std::cout << "Enter your selection: ";
    std::cin >> menuSelection;
}

// "Do you wish to quit" question
int quitQuestion()
{
    std::cout << "Quit program? (y/n): ";
    std::cin >> ynAnswer;

    if (ynAnswer[0] == 'y'){
        return 0;
    }
    else {
        system(CLEAR);
        menu();
    }
    
    return 0;
}

int main()
{
    menu();
    
    // 1) Enter today's tips
    if (menuSelection == 1){
        system(CLEAR);
        
        double amount;
        std::string news, date;
        
        // Planning to add dates automagically in the future
        std::cout << "Today's Date (mm/dd/yyyy): ";
        std::cin >> date;
        system(CLEAR);

        // The amount of tips made that day
        std::cout << "How much did you make?: ";
        std::cin >> amount;
        std::cin.ignore();
        system(CLEAR);

        // Daily news
        std::cout << "What's happening today?: ";
        std::getline(std::cin,news);
        system(CLEAR);
        
        // Make a new file with the date as the file name
        std::ofstream ("C:/Users/John/Desktop/Coding/Tips/Records/"+date+".txt");

        // Write the amount of tips made, and daily news, into the file you just made above
        std::ofstream tipFile;
        tipFile.open("c:/users/John/Desktop/Coding/Tips/Records/"+date+".txt");
        tipFile << "Tip money made: $" << amount << "\n\n";
        tipFile << "News of the day - " <<  news;
        tipFile.close();

        // Write today's tips to a file containing the amount of all tips earned thus far
        int x;
        std::fstream total;
        total.open("c:/users/John/Desktop/Coding/Tips/Records/total.txt");
        total >> x;
        total.close();

        // I have to close and re-open the file after reading from it, or I can't write back into it. Don't know why.
        total.open("c:/users/John/Desktop/Coding/Tips/Records/total.txt");
        total << x + amount;
        total.close();

        std::cout << "\t\t\t Information entered! Thank you!\n\n" << std::endl;
        quitQuestion();
    }

    // 2) Calculate total of all tips earned
    if (menuSelection == 2){
        int totalVariable;
        std::fstream total;

        total.open("c:/users/John/Desktop/Coding/Tips/Records/total.txt");
        total >> totalVariable;
        total.close();

        system(CLEAR);
        std::cout << "\tSo far you have made " << totalVariable << " dollars in tips. Good job!\n\n" << std::endl;

        quitQuestion();
    }

    // 3) Review what happened, and how much you made in tips on a certain day
    if (menuSelection == 3){
        system(CLEAR);

        std::string dayToReview;
        std::cout << "What day would you like to review?: ";
        std::cin >> dayToReview;

        std::string fileContent;
        std::ifstream content;

        content.open("c:/users/John/Desktop/Coding/Tips/Records/"+dayToReview+".txt");
        system(CLEAR);

        while(getline(content, fileContent)){
            std::cout << fileContent << "\n\n" << std::endl;
        }

        content.close();

        quitQuestion();
    }

    // 4) Reset all the records stored thus far. Why would you want to do that? Who knows. People be cray.
    if (menuSelection == 4){
        system(CLEAR);

        std::cout << "Are you sure to want to reset? (y/n): ";
        std::cin >> ynAnswer;
        system(CLEAR);

        if (ynAnswer[0] == 'y'){
            std::cout << "Foh realz though. This will delete everything. Do you want to do that? (y/n): ";
            std::cin >> ynAnswer;
            system(CLEAR);

            // This doesn't actually work yet. I'm waiting to figure out how to install the boost library, than implement it.
            if (ynAnswer[0] == 'y'){
                std::cout << "Welp, you did it. It's all gone. I hope you had good reason for that" << std::endl;
            }
        }
    }
 
    return 0;
}