#include "MyAvl.h"

class Dictionary
{
    private:
        MyAvl<Data,string> tree;
    public:
        Dictionary ();
        void learnFromFile(string);
        void learnPhrases(string);
        string trim(string);
        void print();
        void printAvlTree();
        void saveToFile(string);
        void buildFromFile(string);
        void predictWord(string);
        void deleteLowFreq(float);
};
ofstream fout;
void writeToFile(Data);

/*
* This function takes in as argument the frequency
* of words that the user wants to delete from the
* dictionary. This is done by making a list of keys
* that have a low frequency and then deleting them.
*/
void Dictionary:: deleteLowFreq(float freq)
{
    vector<string> keyList;
    tree.makeList(keyList,freq);
    for(int i=0;i<keyList.size();i++)
        tree.AVL_Delete(keyList[i]);
}

/*
* This method takes in the string as input that
* that the user wants the computer to guess the
* word from the dictionary.
*/
void Dictionary::predictWord(string input)
{
    priority_queue<Data,vector<Data>> wordList;
    tree.makeList(input,wordList);
    cout<<endl;
    while(!wordList.empty())
    {
        cout<<"- "<<wordList.top().key;
        cout<<" ("<<wordList.top().counter<<")"<<endl;
        wordList.pop();
    }
}

/*
* This method creates a dictionary from a previously
* saved dictionary. "|" are used as delimiters and 
* the format expected is key|occurrence|totalWords.
*/
void Dictionary::buildFromFile(string fileName)
{
    ifstream fin;
    string eachLine;
    Data node;
    vector<string> tokens;
    fin.open(fileName);
    if(fin.fail())
    {
        cout<<"Input file failed to open."<<endl;
        exit(3);
    }
    while(!fin.eof())
    {
        getline(fin,eachLine);
        if(eachLine=="!") break;
        split(tokens,eachLine,is_any_of("|"));
        
        node.key=tokens[0];
        node.counter=atoi(tokens[1].c_str());
        
        tree.insertNode(node);
        
    }
    Data::totalWords=atoi(tokens[2].c_str());
    fin.close();
}

/*
* This method creates a file and saves the dictionary to a file.
* The format in which it is saved is key|occurrence|totalwords
*/
void Dictionary::saveToFile(string fileName)
{
    fout.open(fileName);
    if(fout.fail())
    {
        cout<<"Could not create output file!!"<<endl;
        exit(1);
    }
    tree.AVL_Traverse(writeToFile);
    fout<<"!";
    fout.close();
}

/*
* This non-member function define the fomat in which
* the dictionary is written to the file.
*/
void writeToFile(Data words)
{
    
    fout<<words.key<<"|"<<words.counter<<"|"<<words.totalWords<<endl;
}

void Dictionary::printAvlTree()
{
    tree.AVL_Print();
}

/*
* This method defines how the data in the AVL dictionary
* is printed on the screen.
*/
void dictionaryOutput(Data words)
{
    cout<<words.key<<" "<<getFreq(words.counter)<<endl;
}

Dictionary::Dictionary()
{
    MyAvl<Data,string> tree;
}

/*
* Function created to print the contents of the dictionary
* on the screen.
*/
void Dictionary::print()
{
    cout<<"The dictionary contains the following words:"<<endl;
    tree.AVL_Traverse(dictionaryOutput);
    cout<<endl<<"Total number of words: "<<tree.AVL_Count();
}

/*
* Function to learn and create a dictionary from a text file.
* The entire contents of the file is read, and only words
* are stored in the dictionary.
*/
void Dictionary::learnFromFile(string fileName)
{
    ifstream fin;
    Data node;
    string temp;
    fin.open(fileName);
    if(fin.fail())
    {
        cout<<"Input file dailed to open."<<endl;
        exit(3);
    }
    while(!fin.eof())
    {
        fin>>temp;
        node.key=trim(temp);
        tree.insertNode(node);
        Data::totalWords++;
    }
    cout<<"Learning completed!!"<<endl;
    fin.close();
}

/*
* Function that learns a dictionary from a text file,
* but in addition to words, will also learn phrases.
*/
void Dictionary::learnPhrases(string fileName)
{
    ifstream fin;
    Data node;
    vector<string> phraseElements;
    string temp,temp1,temp2;
    fin.open(fileName);
    if(fin.fail())
    {
        cout<<"Input file dailed to open."<<endl;
        exit(3);
    }
    while(!fin.eof())
    {
        fin>>temp;
        node.key=trim(temp);
        tree.insertNode(node);
        
        phraseElements.push_back(node.key);
        if(phraseElements.size()==3)
        {
            temp1=phraseElements[0] + " " + phraseElements[1];
            temp2= temp1 + " " + phraseElements[2];
            
            node.key = temp1;
            tree.insertNode(node);
            Data::totalWords++;
            
            node.key = temp2;
            tree.insertNode(node);
            Data::totalWords++;
            
            phraseElements[0]=phraseElements[1];
            phraseElements[1]=phraseElements[2];
            phraseElements.pop_back();
        }
        
        Data::totalWords++;
    }
    cout<<"Learn completed!!"<<endl;
    fin.close();
}


string Dictionary:: trim(string input)
{
    stringstream ss;
   for (int x = 0; x < (int) input.size(); x++)
   {
       if(isalpha(input[x]))
       {
           ss << input[x];
       }
   }

    if (ss.str().length() > 0)
        return ss.str();
    else
        return "";
}