#include "Data.h"

/********************************************************************************************************************
* Function: Data()
* Description: A default constructor for Data class. It initializes its private members: command, description and points
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Data::Data()
{
	this->command = "";
	this->description = "";
	this->points = 0;
}

/********************************************************************************************************************
* Function: ~Data()
* Description: A destructor for Data class.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Data::~Data() //activated by using delete keyword to Data
{
}

/********************************************************************************************************************
* Function: getCommand()
* Description: A getter function for command. Used as a command accessor from other classes.
* Input parameters: Nothing
* Returns: command
*********************************************************************************************************************/
string Data::getCommand()
{
	return this->command;
}

/********************************************************************************************************************
* Function: getDescription()
* Description: A getter function for description. Used as a description accessor from other classes.
* Input parameters: Nothing
* Returns: description
*********************************************************************************************************************/
string Data::getDescription()
{
	return this->description;
}

/********************************************************************************************************************
* Function: getPoints()
* Description: A getter function points. Used as a points accessor from other classes.
* Input parameters: Nothing
* Returns: points
*********************************************************************************************************************/
int Data::getPoints()
{
	return this->points;
}

/********************************************************************************************************************
* Function: setCommand()
* Description: A setter function for command. Used as a modifier for command from other classes.
* Input parameters: command
* Returns: Nothing
*********************************************************************************************************************/
void Data::setCommand(string command)
{
	this->command = command;
}

/********************************************************************************************************************
* Function: setDescription()
* Description: A setter function for description. Used as a modifier for description from other classes.
* Input parameters: description
* Returns: Nothing
*********************************************************************************************************************/
void Data::setDescription(string description)
{
	this->description = description;
}

/********************************************************************************************************************
* Function: setPoints()
* Description: A setter function for points. Used as a modifier for points from other classes.
* Input parameters: points
* Returns: Nothing
*********************************************************************************************************************/
void Data::setPoints(int points)
{
	this->points = points;
}
