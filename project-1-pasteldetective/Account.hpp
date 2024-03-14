/*
Jackie Yee CSCI 235 Professor Ligorio
Account.cpp
9/5/2022
This file contains the class for Account and all its private and public members.
The second part of Project 1.
*/
#ifndef Account_HPP_
#define Account_HPP_

#include <iostream>
#include <vector>
using namespace std;

class Account 
{
    private:
        string Acc_username, Acc_pass; //Acc_username, Acc_pass initialized, Post_obj vector also initialized
        vector<Post> Post_obj; 
    public:
        Account(); //default constructor
        Account(string Acc_username, string Acc_pass); //parametrized constructor for user_input based function
        string getUsername() const; //getter function returns username
        string getPassword() const; //getter function returns Password
        void setUsername(const string& Acc_username); //setter function sets Acc_username to user input
        void setPassword(const string& Acc_pass); //setter function sets Acc_pass to user input
        bool addPost(const string& title, const string& body); //bool funct adds post to vector, also Will return true if the Post does not have an empty title or body and the Post is successfully added to the vector
        void viewPosts(); //display function
};

#endif