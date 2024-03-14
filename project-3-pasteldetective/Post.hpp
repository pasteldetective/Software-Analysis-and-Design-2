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
        std::string title, body, username; 
        time_t time;
    public:
        Post(std::string title, std::string body); //User input constructor
        Post(std::string title, std::string body, std::string user);
        std::string getTitle() const; //getter returns title of post and body
        std::string getBody() const; 
        std::string getUsername() const;
        void setTitle(const std::string& title); //setters, user sets title and body
        void setBody(const std::string& body);
        void setUsername(const std::string& user);
        void getTimeStamp() const; //gets Timestamp (current time)
        void displayPost(); //function prints Posts
};

#endif