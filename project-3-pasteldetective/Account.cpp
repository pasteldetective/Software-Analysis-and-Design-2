/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 3: Account.cpp
 * @version 0.5
 * @date 2022-10-06
 * 
 * 
 **/

#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"
#include "Network.hpp"
#include "Post.hpp"

Account::Account() //default constructor sets Acc_pass, Acc_username to empty string, Post_object to empty vector
{
    Acc_pass = "";
    Acc_username = "";
    netPointer = nullptr;
}

Account::Account(const std::string pass, const std::string user) //default constructor sets Acc_pass, Acc_username to user input, Post_object to empty vector 
{
    Acc_pass = pass;
    Acc_username = user;
    netPointer = nullptr;
}

std::string Account::getUsername() const //getter function returns Username
{
    return Acc_username;
}
void Account::setUsername(const std::string user) //setter function sets Acc_username to user input
{
    Acc_username = user;
}
std::string Account::getPassword() const
{
    return Acc_pass;
}
void Account::setPassword(const std::string pass)
{
    Acc_pass = pass;
}

void Account::viewPosts() //displays posts of vector of class Post
{
    for (int i = 0; i < userAcc.size(); i++) //iterates Posts of Post_obj
    {
        userAcc[i].displayPost();
        std::cout << std::endl;
    }
    
}

Network<Account>* Account::getNetwork() const
{
    return netPointer;
    /*
    Network<Account>* suffering;
    return suffering;
    */
}

void Account::setNetwork(Network<Account>* netPoint_)
{
    netPointer = netPoint_;
}

/*adds the username to the vector of following accounts only if
it is affiliated to a Network AND it is not already following an account
with the same username */
bool Account::followAccount(const std::string& accUsr)
{
    
    bool ifFollow = true;
    for (int i = 0; i < vecUsr.size(); i++)
    {
        if (vecUsr[i] == accUsr)
        {
            ifFollow = false;
        }
    }
    if (netPointer != nullptr && ifFollow == true && getNetwork()->containsAccount(this))
    {
        vecUsr.push_back(accUsr);
        return true;
    }
    else
    {
        return false;
    }
    
    //return true;
    
}

std::vector<std::string> Account::viewFollowing() const //returns the vector of usernames the Account is following
{
    
    return vecUsr;   
    
    /*
    std::vector<std::string> test;
    return test;
    */
    
}

/* generates a Post with the given title and body and adds it to it's vector
of posts AND to the Network's feed if it is connected to a Network. */
bool Account::addPost(const std::string& title, const std::string& body) //addPost does not currently produce expected output on gradescope 
{
    
    Post morePost(title, body, Acc_username);
    if (title != "" || body != "") // checks if reference title and body are empty strings, but missing one more conditional?
    {
        userAcc.push_back(morePost);
        if(netPointer != nullptr)
        {
            netPointer -> addToFeed(morePost);
        }
        return true;
    }
    else
    {
        return false;
    }
    //return true;
}