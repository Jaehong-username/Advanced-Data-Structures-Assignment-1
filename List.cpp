#include "List.h"

//List::List()
//{
//	this->pHead = nullptr;
//}
//
//List::~List()
//{
//	//delete this->pHead;
//	this->destroyList();
//	cout << "Command List memory has been deallocated successfully!" << endl  << endl;
//}
//
//void List::destroyList()
//{
//	////destroying the pre-existing list with recursion
//	//destroyList(pHead->getpNext());
//
//	//if (pHead->getpNext() == nullptr) //it reaches to end recursive call.
//	//{
//	//	cout << "Node data: " << pHead->getpData()->getCommand() << "destructor invoked!" << endl;
//	//	delete pHead->getpData();
//	//	pHead->setpData(nullptr);
//	//	cout << "The data's corresponding Node destructor also invoked!" << endl;
//	//	delete pHead;
//	//	pHead = nullptr;
//	//}
//	//if (this->pHead == nullptr)
//	//	return;
//	//destroyList(pHead->getpNext());
//	//	//cout << "Data: " << pHead->getpData()->getCommand() << "destructor invoked!" << endl;
//	//	delete pHead->getpData();
//	//	pHead->setpData(nullptr);
//	//	//cout << "The data's corresponding Node destructor also invoked!" << endl;
//	//	delete pHead;
//	//	pHead = nullptr;
//	
//	Node<Data>* pCurrent = pHead;;
//	Node<Data>* pNext;
//
//	// Traverse the list and delete each node
//	while (pCurrent != nullptr) {
//		pNext = pCurrent->getpNext();
//		cout << "Data object destructor invoked! " << pCurrent->getpData()->getCommand() << endl;
//		delete pCurrent->getpData();
//		pCurrent->setpData(nullptr);
//
//		cout << "Node object destructor invoked! " << endl; //<< current->getpData()->getCommand() << endl << endl;
//		delete pCurrent;
//		pCurrent = pNext; //to keep track of the node!!!
//	}
//
//	// Set head to nullptr to indicate an empty list
//	this->pHead = nullptr;
//}
//
//void List::loadList(Node<Data>* pHead, ifstream& fileStream)
//{
//	char tempLine[200] = "";
//	char placeHolder[200] = "";
//
//	string tempCommand = "";
//	string tempDescription = "";
//	int tempPoints = 0;
//
//	fileStream.open("commands.csv");
//	
//	if (fileStream.is_open()) //if the file is opened!
//	{
//		while (!fileStream.eof())
//		{
//			fileStream.getline(tempLine, 200); //extract each line from the csv file.
//
//			//now will be stored as a string?
//			tempCommand = strcpy(placeHolder, strtok(tempLine, ",\n"));
//			tempDescription = strcpy(placeHolder, strtok(NULL, ",\n")); //Make sure to put NULL!!!!
//			tempPoints = atoi(strcpy(placeHolder, strtok(NULL, ",\n")));
//
//			this->insertAtFront(this->pHead, tempCommand, tempDescription, tempPoints);
//		}
//	}
//
//	else
//		cout << "The commands.csv input file is not opened yet, please sure to double check the file!\n" << endl;
//
//	fileStream.close();
//}
//
//void List::insertAtFront(Node<Data>* pHead, string command, string description, int points)
//{
//	Node<Data>* pMem = new Node<Data>(); //dynamically allocates memory
//	//I need to also populate Data object as well!!!
//	Data* pMemData = new Data();
//
//	if (pMem != nullptr && pMemData != nullptr)
//	{
//		pMem->setpData(pMemData); //firstable connect it to the data pointer!!!
//
//		//Filling in the contents of the node.
//		pMem->getpData()->setCommand(command); //important to not use this keyword in this case!
//		pMem->getpData()->setDescription(description);
//		pMem->getpData()->setPoints(points);
//
//		if (pHead == nullptr)
//		{
//			this->pHead = pMem;
//		}
//
//		else
//		{
//			//pMem = this->pHead;!!!!!!!!!!!!!!!!!!!!It is not linking to the next Node pointer!!!!!!!!!!!!!!!!!!!!!!!!
//			pMem->setpNext(this->pHead);
//			this->pHead = pMem;
//		}
//	}
//
//	else
//	{
//		cout << "Failed to allocate memory space for a Node. Insertion didn't occur!\n" << endl;
//	}
//	
//}
//
//bool List::removeNode(Node<Data>* pHead, string commandToRemove)
//{
//	if (this->pHead != nullptr)
//	{
//		Node<Data>* localpCur = this->pHead; //local variable
//		Node<Data>* localpPrev = nullptr; //FOR DELETING IN THE MIDDLE AND THE END  in a single linked list.
//
//		while (pHead->getpData()->getCommand() != commandToRemove)
//		{ //if not found the match go inside of the while loop
//			localpPrev = localpCur;
//			localpCur = localpCur->getpNext(); //increment it until finding the node to delete.
//
//			if (localpCur->getpNext() == nullptr) //the command to delete doesn't exist in the loop
//			{
//				cout << "Warning: We couldn't find the command to remove that you had requested!\n" << endl;
//				cout << "Please make sure the spelling is correct or to check if the requested command ever exists!\n" << endl;
//				return false; //couldn't remove Node
//			}
//		}
//
//		//Once out of the loop, found the node to delete.
//		//1. case when there is only first Node left to delete.
//		if (localpCur->getpNext() == nullptr)
//		{
//			delete localpCur->getpData(); //deallocates Data memory
//			localpCur->setpData(nullptr);
//			delete localpCur; //deallocates Node memory
//			this->pHead = nullptr; //set it to nullptr
//		}
//
//		//2. Remove Node at front!
//		else if (localpCur == this->pHead) // -> A -> B ->
//		{
//			this->pHead = this->pHead->getpNext();
//			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
//			delete localpCur->getpData();
//			localpCur->setpData(nullptr);
//			delete localpCur;
//			return true;
//		}
//
//		//3. Remove Node at Middle                           ->
//		else if (localpCur->getpNext() != nullptr)  // -> A - > B - > C ->
//		{
//			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
//			localpPrev->setpNext(localpCur->getpNext());
//			delete localpCur->getpData();
//			localpCur->setpData(nullptr);
//			delete localpCur; // since localpCur is just a local variable: no need to set it to nullptr
//			return true;
//		}
//
//		//4. Remove Node at End.
//		else if (localpCur->getpNext() == nullptr)
//		{
//			cout << "Command: " << localpCur->getpData()->getCommand() << "  has been removed successfully from the list\n" << endl;
//			localpPrev->setpNext(nullptr);
//			delete localpCur->getpData();
//			localpCur->setpData(nullptr);
//			delete localpCur; // since localpCur is just a local variable: no need to set it to nullptr
//			return true;
//		}
//
//
//	}
//	
//	else
//	{
//		cout << "No node to delete in the list of commands! Please make sure that the"
//			<< "commands.csv file is loaded into the list correctly!\n" << endl;
//
//		return false;
//	}
//
//	return true;
//}
//
//Node<Data>* List::getpHead()
//{
//	return this->pHead;
//}
