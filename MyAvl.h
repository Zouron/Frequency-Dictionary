#include "AVL_ADT.h"


struct Data
{
    string key;
    int counter=1;
    static int totalWords;
    bool operator<(const Data&)const ;
};

bool Data::operator<(const Data& a)const
{
    return this->counter < a.counter;
}

float getFreq(int counter)
{
    return (float)counter/Data::totalWords*1000;
}

template<class TYPE, class KTYPE>
class MyAvl : public AvlTree<TYPE, KTYPE>
{
    public:
    void insertNode(TYPE dataIn);  
    void addToCounter(KTYPE dataIn);
    void makeList(string,priority_queue<Data,vector<Data>>&);
    void gatherWords(string&,priority_queue<Data,vector<Data>>&,NODE<TYPE> *root);
    void gatherWords(vector<string>&,float,NODE<TYPE> *root);
    void makeList(vector<string>&,float);
};

/*
* A function used to create a vector of selected words based on it frequency
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE>::makeList(vector<string>& list, float freq)
{
    gatherWords(list,freq,AvlTree<TYPE,KTYPE>::tree);
    return;
}

/*
* A recursive function that puts words in a vector, those with a 
* frequency less than that specified by the user. This list can
* then be used to iterate an perform multiple tasks, like deleting keys
* from the AVLtree.
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE>::gatherWords(vector<string>& list,float freq,
                                    NODE<TYPE> *root)
{
    if(root)
    {
        gatherWords(list,freq,root->left);
        if(getFreq(root->data.counter)<freq)
            list.push_back(root->data.key);
        gatherWords(list,freq,root->right);
    }
}

/*
* This method is used to create a priority list of words, based on what the user
* has entered.
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE>::makeList(string input,priority_queue<Data,vector<Data>>& list)
{
    gatherWords(input,list,AvlTree<TYPE,KTYPE>::tree);
    return;
}


/*
* This is a recursive function that builds a list of words that frequently occur
* in the dictionary based on what the user has typed. 
* This is done by checking that the substring of the right length matches the key
* in the dictionary, it is then added to the queue.
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE>::gatherWords(string& input, priority_queue<Data,vector<Data>>& list,
                                    NODE<TYPE> *root)
{
    if(root)
    {
        if(input<(root->data.key.substr(0,input.size())))
            gatherWords(input,list,root->left);
        else if(input>(root->data.key.substr(0,input.size())))
            gatherWords(input,list,root->right);
        else
        {
            gatherWords(input,list,root->left);
            list.push(root->data);
            gatherWords(input,list,root->right);
        }
            
    }
}

/*
* A function to increment the counter of a node, with a given key.
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE> :: addToCounter(KTYPE key)
{
    //	Local Definitions
	NODE<TYPE> *node;
	
//	Statements 
	if (!AvlTree<TYPE,KTYPE>::tree)
	   return ;
	   
	node = AvlTree<TYPE,KTYPE>::_retrieve (key,AvlTree<TYPE,KTYPE>::tree);
	if (node)
	{
	    node->data.counter++;
	}
	
}

/*
* A function that was created to only insert a node, if
* the key for the node is not there in the tree. This ensures
* that there are no duplicates in the tree. if it is found,
* the counter for the node is incremented.
*/
template <class TYPE, class KTYPE>
void MyAvl<TYPE,KTYPE> :: insertNode(TYPE dataIn)
{
    Data item;
    
    if(this->AVL_Retrieve(dataIn.key,item))
    {
        this->addToCounter(dataIn.key);
    }
        
    else
        this->AVL_Insert(dataIn);
}
