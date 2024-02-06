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

#include "Data.h"

/********************************************************************************************************************
* Class name: Node template <typename NODETYPE>
* Description: Node class object stores pointer to Data class object which stores Linux command, description adnd points.
*              This is a class template with 1 parameter of type NODETYPE. In this assignment Data replaces with
*              NODETYPE.
*********************************************************************************************************************/
//NODETYPE will be replaced with Data
template <typename NODETYPE>
class Node
{
public:
	Node();
	~Node();

	//Accessor
	NODETYPE* getpData();
	Node<NODETYPE>* getpNext();

	//Modifier
	void setpNext(Node<NODETYPE>* pNext);
	void setpData(NODETYPE* pData);

private:
	NODETYPE* pData;
	Node<NODETYPE>* pNext;
};


/********************************************************************************************************************
* Function: Node() template <typename NODETYPE>
* Description: A default constructor for Node class. It initializes its private members pNext and pData
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
Node<NODETYPE>::Node()
{
	this->pNext = nullptr;
	this->pData = nullptr;
}


/********************************************************************************************************************
* Function: ~Node() template <typename NODETYPE>
* Description: A destructor for Node class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
Node<NODETYPE>::~Node()
{
}


/********************************************************************************************************************
* Function: getpData() template <typename NODETYPE>
* Description: A getter function pData. Used as a pData accessor from other classes.
* Input parameters: Nothing
* Returns: pData
*********************************************************************************************************************/
template <typename NODETYPE>
NODETYPE* Node<NODETYPE>::getpData()
{
	return this->pData;
}

/********************************************************************************************************************
* Function: getpNext() template <typename NODETYPE>
* Description: A getter function pNext. Used as a pNext accessor from other classes.
* Input parameters: Nothing
* Returns: pNext
*********************************************************************************************************************/
template <typename NODETYPE>
Node<NODETYPE>* Node<NODETYPE>::getpNext()
{
	return this->pNext;
}


/********************************************************************************************************************
* Function: setpNext() template <typename NODETYPE>
* Description: A setter function for pNext. Used as a modifier for pNext from other classes.
* Input parameters: pNext
* Returns: Nothing
*********************************************************************************************************************/
template <typename NODETYPE>
inline void Node<NODETYPE>::setpNext(Node<NODETYPE>* pNext)
{
	this->pNext = pNext;
}

/********************************************************************************************************************
* Function: setpData() template <typename NODETYPE>
* Description: A setter function for pData. Used as a modifier for pData from other classes.
* Input parameters: pData
* Returns: Nothing
*********************************************************************************************************************/
template<typename NODETYPE>
inline void Node<NODETYPE>::setpData(NODETYPE* pData)
{
	this->pData = pData;
}


