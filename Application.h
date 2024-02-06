/****************************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CPTs 223, Spring 2024
* Programming Assignment: PA1
* Date: February 2nd, 2024
* Description: This PA assignment is creating the Linux command game program. Each comma separated data from commands.csv file
*              will be organized into a single linked list with insertion of node at front which takes a constant time in a list
*              in contrast with an array. However, retrival of older user's profile from data requires random access to
*              data. This is the reason why array-based data structure was used for arranging a collection of user's profiles
*              for a quick access which takes constant time in an array in contrast with a linked list.
****************************************************************************************************************************/

#pragma once

#include "List.h"

/********************************************************************************************************************
* Struct name: Profile
* Description: Encapsulates user profile related variables into a struct called Profile.
*********************************************************************************************************************/
struct Profile
{
    string playerName;
    int playerScore;
    int howManyQuestions;
    int currentQuestionNum;
};

/********************************************************************************************************************
* Class name: Application
* Description: Application class object has operations related to running the Linux command game.
*********************************************************************************************************************/
class Application
{
public:

    Application();
    ~Application();

    void run(void);

private:
    
    bool exit;
    int menu;
    bool menuCheckAgain;
    
    bool previousGameLoaded;
    bool gamePlayed;
    //Array of struct called Profile
    struct Profile Profiles[100]; //Max player stored is 100
    int profileIndex;
    int totalProfileIndex;
    void initProfiles(void);
 

    int commandNumber;
    int commandNumberMax;

    string answer;
    int answerKey;
    int pointsEarned;
    List<Data> CommandProblemList;
    Node<Data>* pCur;

    ifstream ifStreamCommands;
    ifstream ifStreamProfiles;
    ofstream ofStreamCommands;
    ofstream ofStreamProfiles;
    
    
    void menuDisplay(void);

    void gameRules(void);
    void playNewGame();
    void loadPreviousGame(void);
    void addCommand(void);
    void removeCommand(void); //commands.csv should not be modified until exit and save
    void displayAllCommands(void);
    void saveAndExit(void);

    bool menuInputCheck(void);

    Node<Data>* moveToCommandNumber(void);
    void makeMultipleChoice(void);
    void generateQuestion(void);

    void checkAnswer(int answerChoice);

    bool checkDuplicates(Node<Data>* pHead, string commandToAdd);

    bool checkPreviousName(string previousName);

    void loadProfilesToArray(ifstream& fileStream);

    void updateCommandsCsv(ofstream& fileStream);

    void updateProfilesCsv(ofstream& fileStream);

};
