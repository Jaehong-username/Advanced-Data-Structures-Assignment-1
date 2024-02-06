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

#include "Node.h"


/********************************************************************************************************************
* Class name: List template <typename NODETYPE>
* Description: List class object has operations related to management of a list including loading, insertion, and
*              deletion. In this assignment Data replaces with NODETYPE.
*********************************************************************************************************************/
template <typename NODETYPE>
class List
{
public:
	List();
	~List();
	void destroyList();

	void loadList(Node<NODETYPE>* pHead, ifstream& fileStream);
	void insertAtFront(Node<NODETYPE>* pHead, string command, string description, int points);
	bool removeNode(Node<NODETYPE>* pHead, string commandToRemove);

	//Accessor:
	Node<NODETYPE>* getpHead();
	
private:
	Node<NODETYPE>* pHead;

};

/********************************************************************************************************************
* Function: List() template <typename NODETYPE>
* Description: A default constructor for List class. It initializes its private members pHead
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
List<NODETYPE>::List()
{
	this->pHead = nullptr;
}

/********************************************************************************************************************
* Function: ~List() template <typename NODETYPE>
* Description: A destructor for List class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
List<NODETYPE>::~List()
{
	//delete this->pHead;
	this->destroyList();
	cout << "Command List memory has been deallocated successfully!" << endl << endl;
}

/********************************************************************************************************************
* Function: destroyList() template <typename NODETYPE>
* Description: Deallocates the list by deallocating both Data and Node class objects from the heap.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
void List<NODETYPE>::destroyList()
{
	////destroying the pre-existing list with recursion
	//destroyList(pHead->getpNext());

	//if (pHead->getpNext() == nullptr) //it reaches to end recursive call.
	//{
	//	cout << "Node data: " << pHead->getpData()->getCommand() << "destructor invoked!" << endl;
	//	delete pHead->getpData();
	//	pHead->setpData(nullptr);
	//	cout << "The data's corresponding Node destructor also invoked!" << endl;
	//	delete pHead;
	//	pHead = nullptr;
	//}
	//if (this->pHead == nullptr)
	//	return;
	//destroyList(pHead->getpNext());
	//	//cout << "Data: " << pHead->getpData()->getCommand() << "destructor invoked!" << endl;
	//	delete pHead->getpData();
	//	pHead->setpData(nullptr);
	//	//cout << "The data's corresponding Node destructor also invoked!" << endl;
	//	delete pHead;
	//	pHead = nullptr;

	Node<NODETYPE>* pCurrent = pHead;;
	Node<NODETYPE>* pNext;

	// Traverse the list and delete each node
	while (pCurrent != nullptr) {
		pNext = pCurrent->getpNext();
		cout << "Data object destructor invoked! " << pCurrent->getpData()->getCommand() << endl;
		delete pCurrent->getpData();
		pCurrent->setpData(nullptr);

		cout << "Node object destructor invoked! " << endl; //<< current->getpData()->getCommand() << endl << endl;
		delete pCurrent;
		pCurrent = pNext; //to keep track of the node!!!
	}

	// Set head to nullptr to indicate an empty list
	this->pHead = nullptr;
}

/********************************************************************************************************************
* Function: loadList() template <typename NODETYPE>
* Description: Loads data from input file to the list.
* Input parameters: pHead, fileStream: input filestream.
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
void List<NODETYPE>::loadList(Node<NODETYPE>* pHead, ifstream& fileStream)
{
	char tempLine[200] = "";
	char placeHolder[200] = "";

	string tempCommand = "";
	string tempDescription = "";
	int tempPoints = 0;

	fileStream.open("commands.csv");

	if (fileStream.is_open()) //if the file is opened!
	{
		while (!fileStream.eof())
		{
			fileStream.getline(tempLine, 200); //extract each line from the csv file.

			//now will be stored as a string?
			tempCommand = strcpy(placeHolder, strtok(tempLine, ",\n"));
			tempDescription = strcpy(placeHolder, strtok(NULL, ",\n")); //Make sure to put NULL!!!!
			tempPoints = atoi(strcpy(placeHolder, strtok(NULL, ",\n")));

			this->insertAtFront(this->pHead, tempCommand, tempDescription, tempPoints);
		}
	}

	else
		cout << "The commands.csv input file is not opened yet, please sure to double check the file!\n" << endl;

	fileStream.close();
}

/********************************************************************************************************************
* Function: insertAtFront() template <typename NODETYPE>
* Description: inserts a new node of data to the very first place of the linked list.
* Input parameters: pHead, command, description, points
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(Node<NODETYPE>* pHead, string command, string description, int points)
{
	Node<NODETYPE>* pMem = new Node<NODETYPE>(); //dynamically allocates memory
	//I need to also populate Data object as well!!!
	NODETYPE* pMemData = new NODETYPE();

	if (pMem != nullptr && pMemData != nullptr)
	{
		pMem->setpData(pMemData); //firstable connect it to the data pointer!!!

		//Filling in the contents of the node.
		pMem->getpData()->setCommand(command); //important to not use this keyword in this case!
		pMem->getpData()->setDescription(description);
		pMem->getpData()->setPoints(points);

		if (pHead == nullptr)
		{
			this->pHead = pMem;
		}

		else
		{
			//pMem = this->pHead;!!!!!!!!!!!!!!!!!!!!It is not linking to the next Node pointer!!!!!!!!!!!!!!!!!!!!!!!!
			pMem->setpNext(this->pHead);
			this->pHead = pMem;
		}
	}

	else
	{
		cout << "Failed to allocate memory space for a Node. Insertion didn't occur!\n" << endl;
	}

}

/********************************************************************************************************************
* Function: removeNode() template <typename NODETYPE>
* Description: removes an pre-existing node of data from the linked list by user input of the command name for removal
* Input parameters: pHead, commandToRemove
* Returns: bool
*********************************************************************************************************************/
template <typename NODETYPE>
bool List<NODETYPE>::removeNode(Node<NODETYPE>* pHead, string commandToRemove)
{
	if (this->pHead != nullptr)
	{
		Node<NODETYPE>* localpCur = this->pHead; //local variable
		Node<NODETYPE>* localpPrev = nullptr; //FOR DELETING IN THE MIDDLE AND THE END  in a single linked list.

		while (pHead->getpData()->getCommand() != commandToRemove)
		{ //if not found the match go inside of the while loop
			localpPrev = localpCur;
			localpCur = localpCur->getpNext(); //increment it until finding the node to delete.

			if (localpCur->getpNext() == nullptr) //the command to delete doesn't exist in the loop
			{
				cout << "Warning: We couldn't find the command to remove that you had requested!\n" << endl;
				cout << "Please make sure the spelling is correct or to check if the requested command ever exists!\n" << endl;
				return false; //couldn't remove Node
			}
		}

		//Once out of the loop, found the node to delete.
		//1. case when there is only first Node left to delete.
		if (localpCur->getpNext() == nullptr)
		{
			delete localpCur->getpData(); //deallocates Data memory
			localpCur->setpData(nullptr);
			delete localpCur; //deallocates Node memory
			this->pHead = nullptr; //set it to nullptr
		}

		//2. Remove Node at front!
		else if (localpCur == this->pHead) // -> A -> B ->
		{
			this->pHead = this->pHead->getpNext();
			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
			delete localpCur->getpData();
			localpCur->setpData(nullptr);
			delete localpCur;
			return true;
		}

		//3. Remove Node at Middle                           ->
		else if (localpCur->getpNext() != nullptr)  // -> A - > B - > C ->
		{
			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
			localpPrev->setpNext(localpCur->getpNext());
			delete localpCur->getpData();
			localpCur->setpData(nullptr);
			delete localpCur; // since localpCur is just a local variable: no need to set it to nullptr
			return true;
		}

		//4. Remove Node at End.
		else if (localpCur->getpNext() == nullptr)
		{
			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
			localpPrev->setpNext(nullptr);
			delete localpCur->getpData();
			localpCur->setpData(nullptr);
			delete localpCur; // since localpCur is just a local variable: no need to set it to nullptr
			return true;
		}


	}

	else
	{
		cout << "No node to delete in the list of commands! Please make sure that the"
			<< "commands.csv file is loaded into the list correctly!\n" << endl;

		return false;
	}

	return true;
}

/********************************************************************************************************************
* Function: getpHead()
* Description: A getter function for pHead. Used as a pHead accessor from other classes.
* Input parameters: Nothing
* Returns: pHead
*********************************************************************************************************************/
template <typename NODETYPE>
Node<NODETYPE>* List<NODETYPE>::getpHead()
{
	return this->pHead;
}
