/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 4: Network.cpp
 * @version 0.5
 * @date 2022-10-25
 * 
 * Network.hpp includes the functions of Network class
 **/

#include "Network.hpp"
#include "Account.hpp"
#include <sstream>
#include <fstream>


template<class ItemType>
Network<ItemType>::Network(): numAcc(0)
{
}  // end default constructor

//Private Method
template<class ItemType>
int Network<ItemType>::getIndexOf(const std::string& userItemInd) const
{
    
    bool found = false;
    int result = -1;
    int search_index = 0;

   // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < numAcc))
    {
        if (pointerArr[search_index] -> getUsername() == userItemInd)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        }  // end if
    }  // end while

    return result;
    
    //return 0;
}

//Public Method
template<class ItemType>
int Network<ItemType>::getSizeOfNetwork() const
{
    return numAcc;
}

//Public Method
template<class ItemType>
bool Network<ItemType>::isEmpty() const
{
    return numAcc == 0;
}

//maybe correct, stores a pointer to the item, if there is room. This is a network specific function
template<class ItemType>
bool Network<ItemType>::addAccount(ItemType *anEntry_)
{
    
    bool has_room = (numAcc < MAXIM);
	if (has_room && !containsAccount(anEntry_))
	{
        pointerArr[numAcc] = anEntry_;
		numAcc++;
		anEntry_->setNetwork(this);
        return true;
	}  // end if
    else
    {
        return false;
    }
    
   //return true;
}  // end add

//Maybe correct, updates the bag/network to remove the pointer, if a pointer to that item was found.
template<class ItemType>
bool Network<ItemType>::removeAccount(const ItemType* anEntry_)
{
    
    int found_index = getIndexOf(anEntry_->getUsername());
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
        pointerArr[found_index] = pointerArr[numAcc - 1];
		pointerArr[numAcc - 1] = nullptr;
        numAcc--;
        return true;
	}  // end if

	return can_remove;
    
   //return true;
}  // end remove

//maybe correct
template<class ItemType>
bool Network<ItemType>::containsAccount(const ItemType* anEntry_) const
{
    return getIndexOf(anEntry_ -> getUsername()) > -1;
    //return true;
}

//maybe correct
/*
Reads every line in the input file, creates an Account from that information and
adds the Account to the network. If a line of input is missing some required information,
it prints out "Improper Format" and terminates.
*/
template<class ItemType>
void Network<ItemType>::populateNetwork(const std::string fileName_)
{
    
    std::ifstream filePass(fileName_); //opens file user inputs
    std::istringstream parse; 
    std::string eachLine;
    
    if (!filePass.is_open()) //not open then error
    {
        std::cout << "Error";
    }

    while (std::getline(filePass,eachLine)) //iterates through each line of file
    {
        if (eachLine == ";") //reaches end then close
        {
            filePass.close();
        }

        std::string text_user, text_pass;
        std::stringstream seqChar(eachLine);
        seqChar >> text_user >> text_pass;

        if (text_user == "" || text_pass == "")
        {
            std::cout << "Improper Format" << std::endl;
            filePass.close();
        }
        else
        {
            ItemType *accInput = new ItemType(text_user,text_pass);
            addAccount(accInput);
        }
    }
    filePass.close();
    
}

//maybe correct
/*
Removes from the Network any items that also appear in the other Network.
In other words, removes elements from the network on the left of the operator that
are also found in the network on the right of the operator.
*/
template<class ItemType>
void Network<ItemType>::operator-=(Network<ItemType>& networkEquals_)
{
    
   for (int i = 0; i < networkEquals_.numAcc; i++)
   {
      if (containsAccount(networkEquals_.pointerArr[i]))
      {
          removeAccount(networkEquals_.pointerArr[i]);
      } 
   }   
}

//maybe correct
template<class ItemType>
void Network<ItemType>::printFeedForAccount(ItemType& refAcc)
{
    
    for (int i = 0; i < refAcc.viewFollowing().size(); i++)
    {
        int accIndex = getIndexOf(refAcc.viewFollowing()[i]);
        if (accIndex > -1)
        {
            pointerArr[accIndex]->viewPosts();
        }
    }
    

} 

//maybe correct
/*
The referenced Account follows another account with the username
specified by the second argument if they both exist in the network
*/
template<class ItemType>
bool Network<ItemType>::authenticateFollow(ItemType& acc_, const std::string& usrname_)
{
    
    if (containsAccount(&acc_) && getIndexOf(usrname_) != -1)
    {
        acc_.followAccount(usrname_);
        return true;
    }
    else
    {
        return false;
    }
    

    //return true;
    
}

/*
Adds the post to its feed only if the Post was created by an Account
in this Network.
*/

//Project 4 change postStored
template<class ItemType>
bool Network<ItemType>::addToFeed(Post* newerPost) 
{
    //see if works
    if (getIndexOf(newerPost->getUsername()) != -1) //changed add to feed to adjust to pointers 
    {
        postStored.insert((Post*)newerPost,0); //inserts post at beginning of list
        return true;
    }
    else
    {
        return false;
    }
    
    /*
    if (getIndexOf(post.getUsername()))
    {
        postStored.push_back(post);
        return true;
    }
    else
    {
        return false;
    }
    return true;
    //return true;
    */
    //return false;
}

/*
This function will look through the body and title of all Posts in the Network's feed.
If a Post contains the provided word or phrase, then it must be removed from the Network's `feed_` 
as well as the Account's `posts_`.
*/

template<class ItemType>
int Network<ItemType>::removeIfContains(const std::string &flagged)
{
    int counter = 0;//counter set to 0
    Node<Post*> *presentPtr = postStored.getHeadPtr(); //make a current/presentptr as Node class Post set to Head Pointer
    while(presentPtr != nullptr) //while != nullptr
    {//finds flagged search terms in body and title
        if(presentPtr->getItem()->getBody().find(flagged) != std::string::npos || presentPtr->getItem()->getTitle().find(flagged) != std::string::npos)
        {
            int indexTemp = getIndexOf(presentPtr->getItem()->getUsername()); //make tempindex to index of username
            pointerArr[indexTemp]->removePost(presentPtr->getItem()); //removes the post
            counter++; //increments
        }
        presentPtr = presentPtr->getNext(); //goes to next list object
    }
    std::cout << postStored.getSize();
    return counter;
    //int counter = 0;
    //curr -> getBody()
    //title && body == flaggedremoveacc and network
    /*
    while()!= nullptr
    {
        
        contains++;
    }
    */
    //return counter;
    //return 0;
}

/*
This function will take the item from its current position and move it to the front
of the list.
*/

template<class ItemType>
void Network<ItemType>::moveItemToTop(Post* object)
{
    postStored.moveItemToTop(object);
}

template<class ItemType>
void Network<ItemType>::updateFeed(Post * list)
{
    postStored.moveItemToTop(list);
}