#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <queue>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;
#include "Dictionary.h"

const string menuOptions[] = {  "Learn words from file.",
                                "Learn phrases from file.",
                                "Load previous dictionary.",
                                "Print dictionary.",
                                "Save dictionary to file.",
                                "Delete low frequency words/phrases.",
                                "Input a word to guess.",
                                "Display Tree.",
                                "Quit"};


int Data::totalWords=0;
void displayMenu();
void goToMainMenu(Dictionary&);
void getFileName(string,string&);

int main()
{
    Dictionary dict;
    int userInput=0;
    
    while(userInput!=9)
    {
        displayMenu();
        string fileName,word;
        float freq;
        cin>>userInput;
        switch(userInput)
        {
            case 1://Learn words from file
            getFileName("article.txt",fileName);
            dict.learnFromFile(fileName);
            dict.print();
            break;
            
            case 2://Learn phrases from file
            getFileName("article.txt",fileName);
            dict.learnPhrases(fileName);
            dict.print();
            break;
            
            case 3://Load a dictionary
            getFileName("dictionary.txt",fileName);
            dict.buildFromFile(fileName);
            break;
            
            case 4://Print dictionary
            dict.print();
            break;
            
            case 5://Save dictionary
            getFileName("dictionary.txt", fileName);
            dict.saveToFile(fileName);
            break;
            
            case 6://Delete low frquency
            cout<<"Enter the frequency threshold (eg: 0.3):"<<endl;
            cin>>freq;
            dict.deleteLowFreq(freq);
            dict.print();
            break;
            
            case 7://Guess the word
            cout<<"Enter word:"<<endl;
            cin>>word;
            dict.predictWord(word);
            break;
            
            case 8://Display Tree
            dict.printAvlTree();
            break;
            
            case 9://Quit
            cout<<"Thank you!!"<<endl;
            break;
            default:
            cout<<"Invalid input!!!"<<endl;
            break;
        }
    }
    
    //displayMenu();
    //dict.learnPhrases("article.txt");
    //dict.learnFromFile("article2.txt");
    //dict.printAvlTree();
    //dict.saveToFile("dic.txt");
    //dict.buildFromFile("dic.txt");
    //dict.print();
    //dict.print();
    //dict.saveToFile("dic.txt");
    //dict.deleteLowFreq(5.0);
    //cout<<endl;
    //dict.print();
    //dict.predictWord("th");
   
    return 0;
}

void goToMainMenu(Dictionary& dict)
{
    int userInput;
    displayMenu();
    cin>>userInput;
}

void displayMenu()
{
    cout<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i < sizeof(menuOptions)/sizeof(menuOptions[0]);i++)
    {
        cout<<i+1<<". "<<menuOptions[i]<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
}

void getFileName(string fileExample, string& fileName)
{
    cout<<"Enter the name of the file "<<"(eg:"<<fileExample<<"):"<<endl;
    cin>>fileName;
}
