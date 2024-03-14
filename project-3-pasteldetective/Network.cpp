/**
 * @file Network.hpp
 * @author Jackie Yee
 * @brief Project 3: Network.cpp
 * @version 0.5
 * @date 2022-10-06
 * 
 * 
 **/

#include "Network.hpp"
#include "Account.hpp"
#include <sstream>
#include <fstream>


template<class T>
Network<T>::Network(): numAcc(0)
{
}  // end default constructor

//Private Method
template<class T>
int Network<T>::getIndexOf(const std::string& userItemInd) const
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
template<class T>
int Network<T>::getSizeOfNetwork() const
{
    return numAcc;
}

//Public Method
template<class T>
bool Network<T>::isEmpty() const
{
    return numAcc == 0;
}

//maybe correct, stores a pointer to the item, if there is room. This is a network specific function
template<class T>
bool Network<T>::addAccount(T *anEntry_)
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
template<class T>
bool Network<T>::removeAccount(const T* anEntry_)
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
template<class T>
bool Network<T>::containsAccount(const T* anEntry_) const
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
template<class T>
void Network<T>::populateNetwork(const std::string fileName_)
{
    
    std::ifstream filePass(fileName_); //opens file user inputs
    std::istringstream parse;
    std::string eachLine;
    
    if (!filePass.is_open())
    {
        std::cout << "Error";
    }

    while (std::getline(filePass,eachLine))
    {
        if (eachLine == ";")
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
            T *accInput = new T(text_user,text_pass);
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
template<class T>
void Network<T>::operator-=(Network<T>& networkEquals_)
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
template<class T>
void Network<T>::printFeedForAccount(T& refAcc)
{
    
    for (int i = 0; i < refAcc.viewFollowing().size(); i++)
    {
        int accIndex = getIndexOf(refAcc.viewFollowing()[i]);
        if (accIndex > -1)
        {
            pointerArr[refAcc]->viewPosts();
        }
    }
    

} 

//maybe correct
/*
The referenced Account follows another account with the username
specified by the second argument if they both exist in the network
*/
template<class T>
bool Network<T>::authenticateFollow(T& acc_, const std::string& usrname_)
{
    
    if (containsAccount(&acc_) && getIndexOf(usrname_) != -1)
    {
        pointerArr.followAccount(usrname_);
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
template<class T>
bool Network<T>::addToFeed(const Post& post)
{
    
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
    
}






 