
/*¡°ADVANTAGES / DISADVANTAGES LINKED LIST : 
The advantage of using a linked list of the linux commands in this assignment was that insertion of new data 
at the front Node is a constant time compared to using array because a linked list uses dynamic memory allocation
which does not have a fix size. Therefore, it is much efficient to use a linked list in this assignment, since we
were instructed to use InsertionAtFront¡±. However the disadvantage of using a linked list is inefficiency in random access of data elements compared to 
array-based structure because of a sequential access feautre of a linked list. /*

/* ¡°ADVANTAGES / DISADVANTAGES ARRAY :
* The advantage of using an array is facilitation of random access to data elemtns within constant-time. Array enables 
* quick retrival of user profiles that were previously stored in the game file by index for a quick look up or modification
* purposes. Therefore, array is a more efficient choice of data structures than a linked list due to the random access to 
* one of user profiles to load the previous game. However, the disadvantage of an array is the fixed size that can't be
dynamically changed compared to a linked list. Such limitation becomes problematic, when there are more users uploading profiles than
the declared size of the array in this assignment. */

//Load Previous Game Requirement: Design Consideration
/*For organizing a collection of user profile data (player's name and points) in this assingment, an array of structs is
more suitable. Given just a pair of player's name and points for user data, struct can encapsulate these variables without
the overhead of class feature.*/

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

#include "Application.h"
//#include "Application.cpp"

int main(void)
{
    srand(time(NULL));
    Application application;
    application.run();
    return 0;
}

//Question Answer: You must store the name,points pairs in a single array. Should it be an array of structs or classes?
// From Load previous game requirement

//Question: 
//
//you must list 1 advantage and 1 disadvantage of using a linked list for the data structure involved with
//storing the commands and descriptions; you must relate your ideas to the way the list is used in THIS
//assignment.Your advantage and disadvantage must be listed in the comment block at the top of your
//main.cpp file under a clearly marked area called ¡°ADVANTAGES / DISADVANTAGES LINKED LIST : ¡±.
//You must list 1 advantage and 1 disadvantage of using an array for the data structure involved with
//storing the user profiles; you must relate your ideas to the way the list is used in THIS assignment.Your
//advantage and disadvantage must be listed in the comment block at the top of your main.cpp file under
//a clearly marked area called ¡°ADVANTAGES / DISADVANTAGES ARRAY :