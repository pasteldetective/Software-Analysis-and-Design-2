/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Account.cpp
 * @version 0.5
 * @date 2022-10-25
 * 
 * Account.ccp includes all class functions
 **/
//Instead of storing Post objects, the Network and Account classes should now store POINTERS to Posts in a LINKED LIST (instead of a vector). Use the LinkedList class provide
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


Network<Account>* Account::getNetwork() const //returns Network Account pointer
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

//Project 4 addPost
/* generates a Post with the given title and body and adds it to it's vector
of posts AND to the Network's feed if it is connected to a Network. */
bool Account::addPost(Post *makePost) //addPost does not currently produce expected output on gradescope 
{
    // bool front = false;
    // front = userAcc.insert(makePost,0);
    // return front;
    
    // Post morePost(title, body, Acc_username);
    // checks if reference title and body are empty strings, 
    // but missing one more conditional? (fixed)
    if (makePost -> getTitle() != "" && makePost -> getBody() != "")  //getTitle and Body through pointer
    {
        userAcc.insert(makePost,0);//inserts post at 0
        if (netPointer != nullptr) //until nullptr, netPointer to addToFeed(makePost)
        {
            netPointer -> addToFeed(makePost);
        }
        return true;
    }
    return false;
    //return true;
}

void Account::viewPosts() const //displays posts of vector of class Post
{
    Node<Post *> *temp_post = userAcc.getHeadPtr(); //Node of Class Post temperary pointer to head
    while(temp_post != nullptr) //only when temp_post != nullptr
    {
        temp_post->getItem()->displayPost(); //points to getItem and afterwards displayPost
        temp_post = temp_post->getNext(); //then temp_post = nextObj 
    }
    // while loop through linklist
    // using displaypost
    // remember to use -> 
    /*
    while(userAcc.getSize()) //while loop contains forever
    {
        //userAcc->displayPost();
        //userAcc -> 
    }
    */
    /*
    for (int i = 0; i < userAcc.size(); i++) //iterates Posts of Post_obj
    {
        userAcc[i].displayPost();
        std::cout << std::endl;
    }
    */
}

//Project 4 functions
/*
This function will take the Post and given the new title and body,
update the Posts title and body as appropriate. It will also update the `timestamp_` to the current time of the update. This function should then
update the location of the Post in its list of `posts_` to the front of the list as well as utilizing its Network pointer to do the same in the `feed_`.
*/
void Account::updatePost(Post* post, const std::string title, const std::string body)
{
    if(!body.empty())
    {
        post -> setBody(body); //post pointed to setBody
    }
    if(!title.empty())
    {
        post-> setTitle(title); //post pointed to title
    }
    post->setTimeStamp(); //setTimeStamp helper function
    userAcc.moveItemToTop(post); 
    netPointer->moveItemToTop(post);
}


bool Account::removePost(const Post* post_pointer)
{
    /*int postIndex = userAcc.getIndexOf(post_pointer);
    if (postIndex == -1)
    {
        return false;
    }
    else
    {
        userAcc.remove(postIndex);
        //getNetwork()->removeAccount(post_pointer);
        return true;
    }
    */
    return true; //stubbed
}