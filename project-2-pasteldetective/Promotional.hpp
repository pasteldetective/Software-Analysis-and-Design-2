/*
Jackie Yee CSCI 235 Professor Ligorio
Promotional.hpp
9/20/2022
This file contains the class for Promotional and inheritance post 
*/
#ifndef PROMOTIONAL_HPP_ 
#define PROMOTIONAL_HPP_

#include "Post.hpp"
#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Promotional : public Post //class Promotional inherits from Post class
{
    private: //private variables initilized title, body and time
        string temURL;
    public:
        Promotional(string name, string body, string username, string postUrl); //User input constructor
        bool setLink(const string& templateLink); // function set Link to templateLink
        string getLink() const; //function returns Link
        void displayPost() const; //func displays post

};

#endif
