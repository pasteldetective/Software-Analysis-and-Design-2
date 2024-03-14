/*
Jackie Yee CSCI 235 Professor Ligorio
Post.cpp
9/20/2022
This file contains the functions for Account, including constructors, getters and setters.
The first part of Project 2.
*/

#include "Post.hpp"
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

Post::Post(string head, string bod, string usrName) //Parametrized constructor user inputted
{
    title = head;
    body = bod;
    username = usrName;
    currTime = time(NULL);
}
string Post::getTitle() const //getter function returns title
{
    return title;
}
void Post::setTitle(const string& head) //setter function sets user input as title
{
    title = head;
}
string Post::getBody() const //getter function returns body
{
    return body;
}

void Post::setBody(const string& bod) ////setter function sets user input as body
{
    body = bod;
}

string Post::getUsername() const
{
    return username;
}

void Post::setUsername(const string& usrName)
{
    username = usrName;
}

void Post::getTimeStamp() const //prints current time
{
    cout << asctime(localtime(&currTime));
}

void Post::displayPost() const //prints when post was posted at current time
{
    cout << getTitle() << "posted at";
    getTimeStamp();
    cout << ":" << endl;
    cout << getBody() << endl;
}