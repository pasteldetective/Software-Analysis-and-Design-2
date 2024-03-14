/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 3: Account.hpp
 * @version 0.5
 * @date 2022-10-06
 * 
 * 
 **/
#ifndef Account_H 
#define Account_H 

#include <iostream>
#include "Post.hpp"
#include "Network.hpp"
#include <vector>
#include <string>

class Account 
{
    private:
        std::string Acc_username, Acc_pass; //Acc_username, Acc_pass initialized, Post_obj vector also initialized
        std::vector<Post> userAcc; //vector of usernames Account
        
        //Project 3 private members
        std::vector<std::string> vecUsr;
        Network<Account> *netPointer;
         
    public:
        Account(); //default constructor
        Account(std::string Acc_username, std::string Acc_pass); //parametrized constructor for user_input based function
        std::string getUsername() const; //getter function returns username
        std::string getPassword() const; //getter function returns Password
        void setUsername(const std::string Acc_username); //setter function sets Acc_username to user input
        void setPassword(const std::string Acc_pass); //setter function sets Acc_pass to user input
        void viewPosts(); //display function

        //Project 3 Task 1 public members 
        Network<Account> *getNetwork() const;
        void setNetwork(Network<Account>* netPoint_);

        //Project 3 Task 2 public members
        bool followAccount(const std::string& accUsr);
        std::vector<std::string> viewFollowing() const;
        bool addPost(const std::string& title, const std::string& body);

};

#endif