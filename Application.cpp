#include "Application.h"

/********************************************************************************************************************
* Function: Application()
* Description: A default constructor for Application class. It initializes its private members of Application class
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Application::Application()
{
    //No need for opening the file 

    this->exit = false;
    this->menu = 0;
    this->menuCheckAgain = false;

    this->previousGameLoaded = false;
    this->gamePlayed = false;

    this->totalProfileIndex = 0;
    this->profileIndex = 0;
    this->initProfiles();
    

    this->pointsEarned = 0;
    this->commandNumber = 0;
    this->commandNumberMax = 29;

    this->answer = "";
    this->answerKey = 0;
    this->pCur = nullptr;
   
}

/********************************************************************************************************************
* Function: ~Application()
* Description: A destructor for Application class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Application::~Application()
{
}

/********************************************************************************************************************
* Function: run()
* Description: runs the Linux command game from the start to the end with 7 different menus.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::run(void)
{
    this->loadProfilesToArray(this->ifStreamProfiles);
    this->CommandProblemList.loadList(this->pCur, this->ifStreamCommands); //Dont forget to load the csv data to a single linked list
    
    do
    {
        do
        {
            system("cls");
            this->menuDisplay();
            this->menuCheckAgain = this->menuInputCheck();
            if (menuCheckAgain)
            {
                system("pause");
            }
            
        } while (this->menuCheckAgain);
       
        switch (menu)
        {
        case 1:
            system("cls");
            this->gameRules();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            this->playNewGame();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            this->loadPreviousGame();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            this->addCommand();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            this->removeCommand();
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            this->displayAllCommands();
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            this->saveAndExit();
            system("pause");
            system("cls");
            break;
        }

    } while (!this->exit);
}

/********************************************************************************************************************
* Function: initProfiles()
* Description: initializes Profiles array of struct of size 100.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::initProfiles(void)
{
    for (int i = 0; i < 100; i++)
    {
        Profiles[i].playerName = "";
        Profiles[i].playerScore = 0;
        Profiles[i].currentQuestionNum = 0;
        Profiles[i].howManyQuestions = 0;
    }
}

/********************************************************************************************************************
* Function: menuDisplay()
* Description: Displays the seven main menu options.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::menuDisplay(void)
{
    cout << "Welcome to Linux Matching Game!\n\n" << endl;

    cout << "Warning! If you terminate the program without Save and Exit menu, your player name and score will not be saved next time\n\n" << endl;

    cout << "1. Game Rules\n" << endl;
    cout << "2. Play New Game\n" << endl;
    cout << "3. Load Previous Game\n" << endl;
    cout << "4. Add Command\n" << endl;
    cout << "5. Remove Command\n" << endl;
    cout << "6. Display All Commands\n" << endl;
    cout << "7. Save and Exit\n" << endl << endl << endl;

    cout << "Please select a menu listed above from 1 to 7" << endl;
    cin >> menu;
}

/********************************************************************************************************************
* Function: gameRules();
* Description: explains the game rules of the Linux command game.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::gameRules(void)
{
    system("cls");

    cout << "Welcome to the Linux Command Game!\n\n" << endl;
    cout << "The game will start after entering your player name (Empty string name not allowed!), and how many questions you would like to be asked! (throug 5 to 30 questions!)\n" << endl;
    cout << "You will earn points (1 ~ 4 pts) if you get one of the  three-multiple choice of Linux command questions!\n" << endl;
    cout << "However, you will lose points (1 ~ 4 pts) if you get a question wrong (A player's scores can even go lower than zero!\n" << endl;
    cout << "Furthermore, you can manually add additional Linux command questions to the list! by entering the command name, the description, and the points\n" << endl;
    cout << "But no same command questions will be accepted to the list!" << endl;
    cout << "You can also manually remove command questions from the list by typing the exact name of the command\n" << endl;
    cout << "If the command name is mispelled, the program will not know which one to delete from the list. So, Please be careful of any typos!\n" << endl;

    cout << "Caution: Please remember that, both the commands.csv file and the profiles.csv file will not be updated.\n"
        << "until an user saves and exits the program through menu 7!\n" << endl;
    cout << "So, please end the game program by going to the menu 7 (Save and exit) instead of aborting the game program!\n" << endl;
    cout << "If you save your player information last time, you can always load your previous game by entering the player name saved to the program!\n" << endl;
    cout << "Always when typing, make sure the spelling is correct!\n" << endl << endl;

    cout << "You can get access to the list of questions through commands.csv file\n" << endl;
    cout << "You may want to study the command questions before you play, if you want to get a high score!\n" << endl;
    cout << "Alrighty!!! These are all the rules you need to know to play the Linux Command Game!\n" << endl << endl;
    cout << "\n\n!!!See you at the game!!!\n\n";
}

/********************************************************************************************************************
* Function: playNewGame
* Description: plays the new game.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::playNewGame(void)
{

    if (this->previousGameLoaded == true)
        goto skip;

    
    //Check duplicate of the name
    //for (this->profileIndex = 0; this->profileIndex < 100; this->profileIndex++)
    
        //if (Profiles[this->profileIndex].playerName == "")
        {
        this->totalProfileIndex = this->profileIndex;
        
            bool nameSuitable = true;
            do
            {
                nameSuitable = true;
                cout << "Please enter your name: ";
                cin >> Profiles[this->profileIndex].playerName;
                
                Profiles[this->profileIndex].playerScore = 0;//!!we need to reset the score

                for (int i = 0; i < this->profileIndex; i++)
                {
                    if (Profiles[this->profileIndex].playerName == "")
                    {
                        cout << "You can't choose an empty string as your player name. Please choose a different one!\n" << endl;
                        nameSuitable = false;
                        break;
                    }
                    if (Profiles[this->profileIndex].playerName == Profiles[i].playerName)
                    {
                        cout << "The name has already taken over, Please type another name!\n" << endl;
                        nameSuitable = false;
                        break;
                    }

                }
            } while (!nameSuitable);
            
        }
            
        
    
    
skip: 
        
        this->gamePlayed = true;
        /*if (this->previousGameLoaded)
        {    
            this->tempIndex = this->profileIndex;
            this->profileIndex = this->oldProfileIndex;
            
        }*/
    do
    {
        cout << "Please enter how many questions you would like to be asked (5-30): " << endl;
        cin >> this->Profiles[this->profileIndex].howManyQuestions;
        if (this->Profiles[this->profileIndex].howManyQuestions < 5 || this->Profiles[this->profileIndex].howManyQuestions > 30)
            cout << "You can only choose within 5-30, please select again!" << endl << endl;
        
    } while (this->Profiles[this->profileIndex].howManyQuestions < 5 || this->Profiles[this->profileIndex].howManyQuestions > 30);
   
    int answerChoice = 0;

    for (int i = 0; i < this->Profiles[this->profileIndex].howManyQuestions; i++)
    {
        this->generateQuestion();
        cout << "Please type your answer through 1 to 3. Otherwise it will automatically be marked as wrong!" << endl;
        cout << "Answers other than numbers could crash the program. So, don't do it!" << endl;
        cout << "Answer: ";
        cin >> answerChoice;
        if (answerChoice != 1 && answerChoice != 2 && answerChoice != 3)
        {
            answerChoice = 0;
        }
        this->checkAnswer(answerChoice);
    }
        
}

/********************************************************************************************************************
* Function: loadPreviousGame()
* Description: loads the previous game by retrieving one of the pre-existing user profiles.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::loadPreviousGame(void)
{
    string previousPlayerName = "";
    bool askAgain;
    bool nameFound;
    
    this->loadProfilesToArray(this->ifStreamProfiles);

    do
    {
        askAgain = false;

        cout << "\nTo load your previous game, please enter your name: ";
        cin >> previousPlayerName;

        if (previousPlayerName == "")
        {
            cout << "Name: cannot be an empty string! Please enter the name again!\n" << endl;
            askAgain = true;
        }
    } while (askAgain);
   
    nameFound = this->checkPreviousName(previousPlayerName);

    if (nameFound)
    {
        this->previousGameLoaded = true;
        this->playNewGame(); //start the game with the saved score
    }

    else
    {
        cout << "There was no record match of the player name you entered!\n";
    }

}


/********************************************************************************************************************
* Function: addCommand()
* Description: adds a new command with its description and points to the linked list.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::addCommand(void)
{
    bool askAgain = false; // needs to be outside of the while loop!!!
    char quits = NULL;

    do
    {
        askAgain = false;
        quits = NULL;
        string commandToAdd = "";
        
        cout << "\nPlease enter the name of the command you want to add: ";
        std::getline(cin >> std::ws, commandToAdd);
        cout << commandToAdd;
        bool duplicatesPresent = this->checkDuplicates(this->CommandProblemList.getpHead(), commandToAdd);

        if (!duplicatesPresent)
        {
            string descriptionToAdd = "";
            cout << "  ----------->  You can add this command to the commands.csv file!" << endl;
            cout << "\nPlease enter the description of the command" << endl;
            cout << "Warning! Do not use comma and make it less than 150 letters to prevent error in the csv data processing" << endl;
            cout << "Description: ";
            std::getline(cin >> std::ws,descriptionToAdd);
            cout << descriptionToAdd;

            int pointsToAdd = 0;
            bool askPointsAgain = false;
            do
            {
                pointsToAdd = 0;
                askPointsAgain = false;
                cout << "\nPlease enter the points of the command (max 4 points): ";
                cin >> pointsToAdd;
                cin.ignore(200, '\n');
                cout << pointsToAdd;

                if (pointsToAdd != 1 && pointsToAdd != 2 && pointsToAdd != 3 && pointsToAdd != 4)
                {
                    cout << "\nInvalid Input! Please enter only 1, 2, 3 or 4 for points!" << endl;
                    askPointsAgain = true;
                }
            } while (askPointsAgain);
       

            this->CommandProblemList.insertAtFront(this->CommandProblemList.getpHead(), commandToAdd, descriptionToAdd, pointsToAdd);
            cout << "\n\nThe new command: " << commandToAdd << " has been added to the commands.csv file successfully!" << endl;
            this->commandNumberMax++;
        }

        else
        {
            cout << "The duplicate command found in the list. The requested command cannot be added." << endl;
            cout << "If you no longer want to add any commands to the list" << endl;
            cout << "Quits? (This will get you back to the main menu of the program!)" << endl;
            cout << "1. Yes            2. No" << endl;
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!If you enter mkdir by mistake quits will only take letter m and
            //the rest of the letters will be bushed back!!!! to the string var that will be used in the next cycle.
            //so it will automatically cin >> commandToAdd kdir will be pushed into it without asking!!!!
            cout << "Please only 1 or 2: ";


            bool askQuitsAgain = false;
            do
            {
                bool askQuitsAgain = false;
                cin >> quits;
                cin.ignore(200, '\n');
                if (quits != 49 && quits != 50)
                {
                    cout << "\nInvalid Input! Please enter only 1 or 2: " << endl;
                    askQuitsAgain = true;
                }
            } while (askQuitsAgain);
            

            if (quits == '1')
            {
                cout << "Quits selected!" << endl;
                system("pause");
                system("cls");
                break;
            }

            else if (quits == '2')
            {
                cout << "No Quits!" << endl;
            }

            askAgain = true;
        }

    } while (askAgain);
}

/********************************************************************************************************************
* Function: removeCommand()
* Description: removes an existing command with its description and points from the linked list
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::removeCommand(void)
{
    bool removed = false;
    bool askAgain = false;
    string commandToRemove = "";
    char quits = NULL;

    do
    {
        askAgain = false;

        cout << "Caution: Please remember that, both the commands.csv file and the profiles.csv file will not be updated"
            << "until an user saves and exits the program through menu 7!\n" << endl;

        cout << "Please enter the exact name of the command for removal from the commands.csv file!\n" << endl;
        std::getline(cin >> std::ws, commandToRemove);

        removed = this->CommandProblemList.removeNode(this->CommandProblemList.getpHead(), commandToRemove);

        if (!removed) //if not removed!!
        {
            cout << "The command aname does not exist in the list! So, It cannot be removed!" << endl;
            cout << "If you no longer want to remove any commands from the list" << endl;
            cout << "Quits? (This will get you back to the main menu of the program!)" << endl;
            cout << "1. Yes            2. No" << endl;
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!If you enter mkdir by mistake quits will only take letter m and
            //the rest of the letters will be bushed back!!!! to the string var that will be used in the next cycle.
            //so it will automatically cin >> commandToAdd kdir will be pushed into it without asking!!!!
            cout << "Please only 1 or 2: ";


            bool askQuitsAgain = false;
            do
            {
                bool askQuitsAgain = false;
                cin >> quits;
                if (quits != 49 && quits != 50)
                {
                    cout << "\nInvalid Input! Please enter only 1 or 2: " << endl;
                    askQuitsAgain = true;
                }
            } while (askQuitsAgain);


            if (quits == '1')
            {
                cout << "Quits selected!" << endl;
                system("pause");
                system("cls");
                break;
            }

            else if (quits == '2')
            {
                cout << "No Quits!" << endl;
            }

            askAgain = true;
        }

        else
        {
            cout << "Command: " << commandToRemove << " has been removed successfully from the program!\n" << endl;
            this->commandNumberMax--;
        }
            
    } while (askAgain);
    
}

/********************************************************************************************************************
* Function: displayAllCommands()
* Description: displays all commands with its description and points from the csv file to the console.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::displayAllCommands(void)
{
    cout << "Printing the list:" << endl;
    Node<Data>* localpCur = this->CommandProblemList.getpHead(); //local pCur

    int questionNumber = 1;

    while (localpCur != nullptr)
    {
        cout << questionNumber << " -" << "\t" << localpCur->getpData()->getCommand()
            << "\t" << localpCur->getpData()->getDescription() << " ("
            << localpCur->getpData()->getPoints() << " points)" << endl;

        localpCur = localpCur->getpNext(); //TO prevent an infinite loop!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        ++questionNumber;
    }
}

/********************************************************************************************************************
* Function: saveAndExit()
* Description: saves the user's points and edited linked list of the command questions to both profiles.csv and
*              commands.csv file.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::saveAndExit(void)
{
    this->exit = true;

    system("Pause");
    system("cls");

    this->updateCommandsCsv(this->ofStreamCommands);
    this->updateProfilesCsv(this->ofStreamProfiles);

    //delete this->CommandProblemList.getpHead();
    
    cout << "The Linux command game program saved the most recent command question list in the commands.csv!" << endl;
    cout << "The current player information (name, current scores) is saved to the profiles.csv file!" << endl;
    cout << "\nWe will see you next time!!!" << endl;
}

/********************************************************************************************************************
* Function: menuInputCheck()
* Description: checks for a valid input for menu.
* Input parameters: Nothing
* Returns: bool
*********************************************************************************************************************/
bool Application::menuInputCheck(void)
{
    this->menuCheckAgain = false;

    //number checking
    if (menu < 1 || menu > 7)
    {
        this->menuCheckAgain = true;
        cout << "Please Enter number only through 1 to 7!" << endl << endl;
    }

    return this->menuCheckAgain;
}

/********************************************************************************************************************
* Function: moveToCommandNumber()
* Description: randomly chooses a command.
* Input parameters: Nothing
* Returns: Node<Data>*
*********************************************************************************************************************/
Node<Data>* Application::moveToCommandNumber(void)
{
    this->pCur = CommandProblemList.getpHead();
    this->commandNumber = rand() % this->commandNumberMax; //Number starts from 0 to the max

    for (int i = 0; i <= this->commandNumber; i++)
    {
        this->pCur = this->pCur->getpNext();
    }

    return pCur;
}

/********************************************************************************************************************
* Function: makeMultipleChoice()
* Description: Randomly distributes three command multiple choice to each number 1 2 3.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::makeMultipleChoice(void)
{
    this->answer = this->pCur->getpData()->getDescription();
    this->pointsEarned = this->pCur->getpData()->getPoints();
    string wrong1 = "";
    string wrong2 = "";

    do
    {
        this->pCur = this->moveToCommandNumber();
        wrong1 = this->pCur->getpData()->getDescription();
    } while (wrong1 == this->answer);

    do
    {
        this->pCur = this->moveToCommandNumber();
        wrong2 = this->pCur->getpData()->getDescription();
    } while (wrong2 == this->answer || wrong2 == wrong1);

    //Make Multiple choice
    string firstChoice;
    string secondChoice;
    string thirdChoice;
    this->answerKey = rand() % 3 + 1;

    switch (this->answerKey)
    {
    case 1:
        firstChoice = this->answer;
        secondChoice = wrong1;
        thirdChoice = wrong2;
        break;

    case 2:
        firstChoice = wrong1;
        secondChoice = this->answer;
        thirdChoice = wrong2;
        break;

    case 3:
        firstChoice = wrong1;
        secondChoice = wrong2;
        thirdChoice = this->answer;
        break; //actually for case 3 no need for a break statement.
    }

    cout << "1. " << firstChoice << endl;
    cout << "2. " << secondChoice << endl;
    cout << "3. " << thirdChoice << endl << endl;
}

/********************************************************************************************************************
* Function: generateQuestion()
* Description: randomly generates a question for users to choose which command is the right answer.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Application::generateQuestion(void)
{
    cout << "-----------------------------------------------------------------------------------" << endl;
    this->pCur = this->moveToCommandNumber();
    cout << "Please pick the correct description for the following command: " << this->pCur->getpData()->getCommand()
        << " (" << this->pCur->getpData()->getPoints() << "pts)" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    
    this->makeMultipleChoice();
}

/********************************************************************************************************************
* Function: checkAnswer()
* Description: checks for an user's answer choice
* Input parameters: answerChoice
* Returns: Nothing
*********************************************************************************************************************/
void Application::checkAnswer(int answerChoice)
{
    if (answerChoice == this->answerKey)
    {
        Profiles[this->profileIndex].playerScore += this->pointsEarned;
        cout << "\nCorrect! You earned " << this->pointsEarned << " points" << endl;
        cout << "Total points: " << Profiles[this->profileIndex].playerScore << endl << endl;
    }
        
    else
    {
        Profiles[this->profileIndex].playerScore -= this->pointsEarned;
        cout << "\nWrong! You lost " << this->pointsEarned << " points" << endl;
        cout << "The answer was " << this->answerKey << endl;
        cout << "Total points: " << Profiles[this->profileIndex].playerScore << endl << endl;
    }
        
}

/********************************************************************************************************************
* Function: checkPreviousName()
* Description: checks for an user's previous name from the Profiles array stored.
* Input parameters: previousName
* Returns: bool
*********************************************************************************************************************/
bool Application::checkPreviousName(string previousName)
{
    for (int i = 0; this->Profiles[i].playerName != ""; i++)
    {
        if (this->Profiles[i].playerName == previousName)
        {
            cout << this->Profiles[i].playerName << " has " << this->Profiles[i].playerScore << " points" << endl;
            this->totalProfileIndex = this->profileIndex - 1;
            this->profileIndex = i; // so that the program knows where to insert the profile data in the array.

            return true;
        }
    }

    return false;
}

/********************************************************************************************************************
* Function: checkDuplicates()
* Description: Checks for if an added command overlaps with the same one from the linked list.
* Input parameters: pHead, commandToAdd
* Returns: bool
*********************************************************************************************************************/
bool Application::checkDuplicates(Node<Data>* pHead, string commandToAdd)
{
    Node<Data>* pCur = this->CommandProblemList.getpHead();

    while (pCur != nullptr) //traverses throgh to the end of the node.
    {
        if (pCur->getpData()->getCommand() == commandToAdd) // found the same command!
        {
            cout << "The command you are trying to add already exists in the commands.csv file! Please double check!\n" << endl;
            return true;
        }

        //Infinite loop Caution!! Make sure to travere to the next node!
        pCur = pCur->getpNext();
    }
    // once out of the while loop, there is no duplicate of commands in the list!

    return false;
}

/********************************************************************************************************************
* Function: loadProfilesToArray()
* Description: loads profiles.csv data to an array of structs.
* Input parameters: input fileStream (passed by referance)
* Returns: Nothing
*********************************************************************************************************************/
void Application::loadProfilesToArray(ifstream& fileStream)
{
    fileStream.open("profiles.csv");

    if (fileStream.is_open())
    {
        char tempLine[100];
        string tempPlayerName = "";
        int tempPlayerScores = 0;

        while (!fileStream.eof())
        {
            fileStream.getline(tempLine, 100);
            tempPlayerName = strtok(tempLine, ",\n");
            tempPlayerScores = atoi(strtok(NULL, ",\n"));

            this->Profiles[this->profileIndex].playerName = tempPlayerName;
            this->Profiles[this->profileIndex].playerScore = tempPlayerScores;

            this->profileIndex++;
        }

        fileStream.close();
    }

    else
    {
        cout << "\nprofile.csv file can't be opened! Please make sure that the file is stored in the correct directory!" << endl;
    }

}

/********************************************************************************************************************
* Function: updateCommandsCsv()
* Description: Updates commands.csv file after saving and exit button from the menu.
* Input parameters: output fileStream (passed by referance)
* Returns: Nothing
*********************************************************************************************************************/
void Application::updateCommandsCsv(ofstream& fileStream)
{
    fileStream.open("commands.csv");

    if (fileStream.is_open())
    {
        Node<Data>* currentPtr = this->CommandProblemList.getpHead();
        while (currentPtr->getpNext() != nullptr)
        {
            fileStream << currentPtr->getpData()->getCommand() << "," << currentPtr->getpData()->getDescription()
                << "," << currentPtr->getpData()->getPoints() << endl;
            currentPtr = currentPtr->getpNext(); //Dont forget to traverse to the next pointer!!!!!!
        }
        //One more left
        fileStream << currentPtr->getpData()->getCommand() << "," << currentPtr->getpData()->getDescription()
            << "," << currentPtr->getpData()->getPoints();

        fileStream.close();
    }

    else
    {
        cout << "\ncommands.csv file can't be opened. Please make sure the file is stored in the currect directory!\n" << endl;
    }
}

/********************************************************************************************************************
* Function: updateProfilesCsv()
* Description: Updates profiles.csv file after saving and exit button from the menu.
* Input parameters: output fileStream (passed by referance)
* Returns: Nothing
*********************************************************************************************************************/
void Application::updateProfilesCsv(ofstream& fileStream)
{
    if (!this->gamePlayed)
        return;

    fileStream.open("profiles.csv");
    
    if (fileStream.is_open())
    {
        
       /* for (int i = 0; i < this->profileIndex; i++)
        {
            if (this->Profiles[i].playerName == this->Profiles[this->profileIndex].playerName)
            {
                this->Profiles[i].playerScore = this->Profiles[this->profileIndex].playerScore;
                this->profileIndex--;
            }
        }*/
        if (this->previousGameLoaded)
        {
            this->totalProfileIndex /= 2;
        }
       
        for (int i = 0; i < this->totalProfileIndex; i++)
        {
            fileStream << this->Profiles[i].playerName << "," << std::to_string(this->Profiles[i].playerScore) << endl;
        }

        //one last player record left
        fileStream << this->Profiles[this->totalProfileIndex].playerName << "," << std::to_string(this->Profiles[this->totalProfileIndex].playerScore);

        fileStream.close();
    }

    else
    {
        cout << "\nprofiles.csv file can't be opened. Please make sure the file is stored in the currect directory!\n" << endl;
    }
}
