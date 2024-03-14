/*
Jackie Yee CSCI 235 Professor Ligorio
Post.hpp
9/20/2022
This file contains the class for Post and its private and public members.
The first part of Project 2.
*/

#ifndef Post_HPP_ 
#define Post_HPP_

#include <time.h>
#include <iostream>
using namespace std; //reminder: get in habit to stop using namespace std

class Post
{
    private: //private variables initilized title, body and time
        string title, body, username; 
        time_t currTime;
    public:
        Post(string title, string body, string username); //User input constructor
        string getTitle() const; //getter returns title of post and body
        string getBody() const; 
        string getUsername() const;
        void setTitle(const string& title); //setters, user sets title and body
        void setBody(const string& body);
        void setUsername(const string& username);
        void getTimeStamp() const; //gets Timestamp (current time)
        void displayPost() const; //function prints Posts
};

#endif