/*
Jackie Yee CSCI 235 Professor Ligorio
Promotional.cpp
9/20/2022
This file contains the fucntions for Promotional
*/
#include "Promotional.hpp"
#include "Post.hpp"

#include <time.h>
#include <iostream>
#include <regex>
using namespace std;

//parametrized constructor includes 4 parameters for promotional
Promotional::Promotional(string name, string body, string username, string postUrl) : Post(name,body,username)
{
    setLink(postUrl);
}

string Promotional::getLink() const //returns temURL
{
    return temURL;
}

//func sets Link to regex url
bool Promotional::setLink(const string& templateLink)
{
    const regex pattern("^(http[s]?:\\/\\/www\\.)[A-Za-z0-9]+\\.[a-zA-Z0-9]{2,}");

    if(regex_match(templateLink, pattern)) //set temURL to templateLink return true
    {
        temURL = templateLink;        
        return true;
    }
    else //else broken link and false
    {
        temURL = "Broken Link";
        return false;
    }
}

void Promotional::displayPost() const //display Post
{
    //Post::displayPost();
    //getLink()
    cout << endl;
    cout << getTitle() << " at ";
    getTimeStamp();
    cout << ":" << endl;
    cout << getBody() << endl << getLink();
    cout << endl;
}
