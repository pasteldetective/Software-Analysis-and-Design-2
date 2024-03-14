/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Account.hpp
 * @version 0.5
 * @date 2022-10-25
 * 
 *Account.hpp includes the Account class private and public members
 **/
#ifndef Account_H 
#define Account_H 

#include <iostream>
#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"
#include <vector>
#include <string>

class Account 
{
    private:
        std::string Acc_username, Acc_pass; //Acc_username, Acc_pass initialized, Post_obj vector also initialized
        
        
        //Project 3 private members
        std::vector<std::string> vecUsr;

        //Project 4 
        Network<Account> *netPointer = nullptr;
        LinkedList<Post*> userAcc; //change variable later
         
    public:
        Account(); //default constructor
        Account(std::string Acc_username, std::string Acc_pass); //parametrized constructor for user_input based function
        std::string getUsername() const; //getter function returns username
        std::string getPassword() const; //getter function returns Password
        void setUsername(const std::string Acc_username); //setter function sets Acc_username to user input
        void setPassword(const std::string Acc_pass); //setter function sets Acc_pass to user input
        

        //Project 3 Task 1 public members 
        Network<Account> *getNetwork() const;
        void setNetwork(Network<Account>* netPoint_);

        //Project 3 Task 2 public members
        bool followAccount(const std::string& accUsr);
        std::vector<std::string> viewFollowing() const;

        //Project 4 
        bool addPost(Post* makePost);
        void viewPosts() const; //display function
        void updatePost(Post* post, const std::string title, const std::string body);
        bool removePost(const Post* post_pointer);

};

#endif