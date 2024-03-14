/*
Jackie Yee CSCI 235 Professor Ligorio
Poll.cpp
9/20/2022
This file contains the functions for Poll.
*/
#include "Poll.hpp"
#include "Post.hpp"

#include <time.h>
#include <iostream>
using namespace std;

//parameterized constructor for Poll
Poll::Poll(string pollTitle, string pollBody, string pollUsername, vector<string> options): Post(pollTitle,pollBody,pollUsername)
{
    pollOpt = options; //set equal vectors
    for (int i = 0; i < pollOpt.size(); i++)
    {
        numVotes.push_back(0); //sets each object to 0
    }
}

bool Poll::votePoll(const int& pollOptIn) //func to votePoll
{
    if ((pollOptIn > 0) && (pollOptIn < pollOpt.size()))//returns true if greater than 0 and pollOpt less than size 
    {
        numVotes[pollOptIn]++;
        return true;
    }
    else //return false if case !=
    {
        return false;
    }
}

//change PollOption function
void Poll::changePollOption(const string newPollOpt, const int& optInRep)
{
     if(optInRep < pollOpt.size()) //sets Vote to zero and pollOpt to newPol
     {
        pollOpt[optInRep] =  newPollOpt;
        numVotes[optInRep] = 0;
    }
    else
    {
        pollOpt.push_back(newPollOpt);
        numVotes.push_back(0);
    }
}

void Poll::getPollOptions() const //func poll opt get
{
    for (int i = 0; i < pollOpt.size(); i++) //gets votes for each option
    {
        cout << numVotes[i] << " votes for: " << pollOpt[i] << endl;
    }
}

int Poll::getPollVotes(const int& inOpt) //return num of Votes func
{
    return numVotes[inOpt];
}

void Poll::displayPost() const //display Posts
{

    Post::displayPost();
    getPollOptions();
    cout << endl;
    /*
    cout << endl;
    cout << getTitle() << " at ";
    getTimeStamp();
    cout << ":" << endl;
    cout << getBody() << endl;
    getPollOptions();
    cout << endl;
    */
    
}






