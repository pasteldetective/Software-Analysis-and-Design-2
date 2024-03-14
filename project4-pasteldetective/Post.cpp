/*
Jackie Yee CSCI 235 Professor Ligorio
Post.cpp
10/25/2022
This file contains the functions for Account, including constructors, getters and setters.
The first part of Project 4.
*/

#include "Post.hpp"

#include <time.h>
#include <iostream>
using namespace std;

Post::Post(std::string head, std::string bod) //Parametrized constructor user inputted
{
    title = head;
    body = bod;
}

Post::Post(std::string head, std::string bod, std::string user) //Parametrized constructor user inputted
{
    title = head;
    body = bod;
    username = user;
}

std::string Post::getTitle() const //getter function returns title
{
    return title;
}
void Post::setTitle(const std::string& head) //setter function sets user input as title
{
    title = head;
}
std::string Post::getBody() const //getter function returns body
{
    return body;
}
void Post::setBody(const std::string& bod) ////setter function sets user input as body
{
    body = bod;
}
std::string Post::getUsername() const
{
    return username;
}
void Post::setUsername(const std::string& user)
{
    username = user;
}

void Post::getTimeStamp() const //prints current time
{
    cout << asctime(localtime(&time_));
}

void Post::setTimeStamp()
{
    time_ = time(&time_);
}

//project 4 display post isnt implemented
/*
void Post::displayPost() const//prints when post was posted at current time
{
    
    cout << title << " posted at " << asctime(localtime(&time)) << ":" << endl;
    cout << body << endl;
    
}
*/