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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::ifstream;
using std::ofstream;


/********************************************************************************************************************
* Class name: Data
* Description: Data class object stores Linux command name, its description and points pointed to by a private member
*              of Node.
*********************************************************************************************************************/
class Data
{
public:
	Data();
	~Data();
	//Accessor
	string getCommand();
	string getDescription();
	int getPoints();

	//Modifier
	void setCommand(string command);
	void setDescription(string description);
	void setPoints(int points);

protected:
	string command;
	string description;
	int points;

};

