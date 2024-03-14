/*
Jackie Yee CSCI 235 Professor Ligorio
Post.cpp
9/5/2022
This file contains the functions for Account, including constructors, getters and setters.
The first part of Project 1.
*/

#include "Post.hpp"

#include <time.h>
#include <iostream>
using namespace std;

Post::Post(string head, string bod) //Parametrized constructor user inputted
{
    title = head;
    body = bod;
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

void Post::getTimeStamp() const //prints current time
{
    cout << asctime(localtime(&time));
}

void Post::displayPost() //prints when post was posted at current time
{
    cout << title << " posted at " << asctime(localtime(&time)) << ":" << endl;
    cout << body << endl;
}