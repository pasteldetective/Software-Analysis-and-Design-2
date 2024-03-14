/*
Jackie Yee CSCI 235 Professor Ligorio
Account.cpp
9/5/2022
This file contains the functions for Account, including constructors, getters and setters.
The second part of Project 1.
*/
#include "Account.hpp"
#include "Post.hpp"
#include <iostream>
#include <vector>
using namespace std;

Account::Account() //default constructor sets Acc_pass, Acc_username to empty string, Post_object to empty vector
{
    Acc_pass = "";
    Acc_username = "";
    vector<Post> Post_obj;
}

Account::Account(string pass, string user) //default constructor sets Acc_pass, Acc_username to user input, Post_object to empty vector 
{
    Acc_pass = pass;
    Acc_username = user;
    vector<Post> Post_obj;
}

string Account::getUsername() const //getter function returns Username
{
    return Acc_username;
}
void Account::setUsername(const string& user) //setter function sets Acc_username to user input
{
    Acc_username = user;
}
string Account::getPassword() const
{
    return Acc_pass;
}
void Account::setPassword(const string& pass)
{
    Acc_pass = pass;
}

bool Account::addPost(const string& title, const string& body) //addPost does not currently produce expected output on gradescope 
{
    if (title != "" || body != "") // checks if reference title and body are empty strings, but missing one more conditional?
    {
        Post newPost(title,body); 
        Post_obj.push_back(newPost);
        return true;
    }
    else
    {
        return false;
    }
}

void Account::viewPosts() //displays posts of vector of class Post
{
    for (Post i : Post_obj) //iterates Posts of Post_obj
    {
        i.displayPost();
    }
    
}

