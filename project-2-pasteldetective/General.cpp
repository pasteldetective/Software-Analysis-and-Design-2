/*
Jackie Yee CSCI 235 Professor Ligorio
General.cpp
9/20/2022
*/

#include "General.hpp"
#include "Post.hpp"
#include <iostream>
#include <string>
using namespace std;


//constructor for general class
General::General(string name, string body, string username): Post(name,body,username) //parametrized constructor 
{
    
    for (int i = 0; i < 6; i++)
    {
        reactionArr[i] = 0;
    }
    
    /* name = nameInput; // change name
    body = bodyInput; //change body
    username = usernameInput; //change username 
    */
    
}

bool General::reactToPost(const Reactions& makeReaction)
{
    if (makeReaction == LIKE)
    {
        reactionArr[0] += 1;
        return true;
    }
    else if (makeReaction == DISLIKE)
    {
        reactionArr[1] += 1;
        return true;
    }
    else if (makeReaction == LAUGH)
    {
        reactionArr[2] += 1;
        return true; 
    }
    else if (makeReaction == WOW)
    {
        reactionArr[3] += 1;
        return true;
    }
    else if (makeReaction == SAD)
    {
        reactionArr[4] += 1;
        return true;
    }
    else if (makeReaction == ANGRY)
    {
        reactionArr[5] += 1;
        return true;
    }
    else
    {
        return false;
    }
}

void General::getReactions() const //A reference to reaction (represented by a value of type Reaction)
{
    cout << "Like : " << reactionArr[0] 
    << " | Dislike : " << reactionArr[1]
    << " | Laugh : " << reactionArr[2] 
    << " | Wow : " << reactionArr[3] 
    << " | Sad : " << reactionArr[4] 
    << " | Angry : " << reactionArr[5] << endl;

}



void General::displayPost() const // Sample: {post_title_} at {time_stamp_}: {post_body_},  Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 |  Angry : 5
{
    Post::displayPost();
    getReactions();
    /*
    cout << endl;
    cout << getTitle() << "at";
    getTimeStamp();
    cout << ":" << endl;
    cout << getBody() << endl;
    getReactions();
    cout << endl;
    */

}