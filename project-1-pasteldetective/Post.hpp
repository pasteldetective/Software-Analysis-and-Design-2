/*
Jackie Yee CSCI 235 Professor Ligorio
Post.cpp
9/5/2022
This file contains the class for Post and its private and public members.
The first part of Project 1.
*/

#ifndef Post_HPP_ 
#define Post_HPP_

#include <time.h>
#include <iostream>
using namespace std; //reminder: get in habit to stop using namespace std

class Post
{
    private: //private variables initilized title, body and time
        string title, body; 
        time_t time;
    public:
        Post(string title, string body); //User input constructor
        string getTitle() const; //getter returns title of post and body
        string getBody() const; 
        void setTitle(const string& title); //setters, user sets title and body
        void setBody(const string& body);
        void getTimeStamp() const; //gets Timestamp (current time)
        void displayPost(); //function prints Posts
};

#endif