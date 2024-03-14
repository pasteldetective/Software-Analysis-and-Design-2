/*
Jackie Yee CSCI 235 Professor Ligorio
Post.cpp
10/25/2022
This file contains the class for Post and its private and public members.
The first part of Project 4.
*/
#ifndef POST_
#define POST_

#include <iostream>
#include <string>
#include <time.h>

class Post
{
private: // private variables initilized title, body and time
   std::string title, body, username;
   time_t time_;

public:
   Post(std::string title, std::string body); // User input constructor
   Post(std::string title, std::string body, std::string user);
   std::string getTitle() const; // getter returns title of post and body
   std::string getBody() const;
   std::string getUsername() const;
   void setTitle(const std::string &title); // setters, user sets title and body
   void setBody(const std::string &body);
   void setUsername(const std::string &user);
   void getTimeStamp() const; // gets Timestamp (current time)
   //Project helper func
   void setTimeStamp();
   //Project 4, turn to virtual void and const to 0
   virtual void displayPost() const = 0;
};
#endif
