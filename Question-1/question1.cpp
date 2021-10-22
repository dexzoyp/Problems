#include<iostream>
#include<vector>
using namespace std;

extern constexpr const int BUFFER_SIZE = 1024;

void PrintBuffer(char* buffer)
{
    cout<<"***** PrintBuffer *****"<<endl;
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        cout<<" ["<<buffer[i]<<"] ";
    }
    cout<<endl;
}

void PrintVector(vector<int> positions)
{
    cout<<"***** PrintVector *****"<<endl;
    for (int i = 0; i < positions.size(); ++i)
    {
        cout<<" ["<<positions[i]<<"] ";
    }
    cout<<endl;
}

int RandomNumber()
{
    return rand()%BUFFER_SIZE;
}

vector<int> FindEmptyPositions(char* buffer)
{
    vector<int> positions;
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        if (buffer[i] == '*')
        {
            positions.push_back(i);
            //buffer example 0 1 * * * 5 * * * 9 10 
            //vector example 2 3 4 6 7 8
        }
    }
    return positions;
}

bool indexExists(vector<int>positions, int number)
{
    for (int i = 0; i < positions.size(); ++i)
    {
        if(positions.at(i)==number)
        {
            return true;
        }
    }
    return false; 
}

bool EnoughSpace(vector<int> positions, int number,int nWordSize)
{
      
      
    int nCount= 0;
    for (int i = 0; i < positions.size()-1;++i)
    {
        if(positions[i] == positions[i+1]-1 && positions[i-1]>=number)
        {
            ++nCount;
            if(nCount == nWordSize)
            {
                return true;
            }
        }
        else
        {
            nCount = 0;
            continue;
        }
    }
    return false;
}

void AllocateWord(char* buffer, vector<int>& positions, vector<string>& words)
{
    int nRandomNumber=RandomNumber();
    int nWordSize = words.back().size();
    if (indexExists(positions,nRandomNumber))
    {
        if(EnoughSpace(positions,nRandomNumber,nWordSize))
        {
            //Filling buffer with the word
            int j=0;
            for (int i = nRandomNumber; i < nRandomNumber+nWordSize; ++i)
            {
                buffer[i]=words.back().at(j);
                ++j;
            }
            cout<<"[Program] The word is allocated in buffer!"<<endl;
            words.pop_back();
            positions = FindEmptyPositions(buffer);
            PrintBuffer(buffer);
            PrintVector(positions);
        }
        else
        {
        cout<<"[Program] Not enough storage!"<<endl;
        }
    }
}
int main()
{
    char* buffer = new char[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; ++i)
    {
        buffer[i]='*';
    }
    vector<int> positions;
    vector<string> words = {
        "places", 
        "each",  
        "subsequent", 
        "word",
        "equal", 
        "probability",
        "no", 
        "free", 
        "position", 
        "for", 
        "the", 
        "next", 
        "word",
        "or", 
        "if", 
        "the", 
        "word", 
        "list", 
        "is", 
        "exhausted",
        "to", 
        "print", 
        "on", 
        "the", 
        "screen", 
        "information", 
        "about", 
        "the", 
        "entered", 
        "words", 
        "and", 
        "their", 
        "occupied", 
        "positions", 
        "in", 
        "the",
        "buffer",
        "places", 
        "each",  
        "subsequent", 
        "word",
        "equal", 
        "probability",
        "no", 
        "free", 
        "position", 
        "for", 
        "the", 
        "next", 
        "word",
        "or", 
        "if", 
        "the", 
        "word", 
        "list", 
        "is", 
        "exhausted",
        "to", 
        "print", 
        "on", 
        "the", 
        "screen", 
        "information", 
        "about", 
        "the", 
        "entered", 
        "words", 
        "and", 
        "their", 
        "occupied", 
        "positions", 
        "in", 
        "the",
        "buffer",
        "places", 
        "each",  
        "subsequent", 
        "word",
        "equal", 
        "probability",
        "no", 
        "free", 
        "position", 
        "for", 
        "the", 
        "next", 
        "word",
        "or", 
        "if", 
        "the", 
        "word", 
        "list", 
        "is", 
        "exhausted",
        "to", 
        "print", 
        "on", 
        "the", 
        "screen", 
        "information", 
        "about", 
        "the", 
        "entered", 
        "words", 
        "and", 
        "their", 
        "occupied", 
        "positions", 
        "in", 
        "the",
        "buffer",
        "places", 
        "each",  
        "subsequent", 
        "word",
        "equal", 
        "probability",
        "no", 
        "free", 
        "position", 
        "for", 
        "the", 
        "next", 
        "word",
        "or", 
        "if", 
        "the", 
        "word", 
        "list", 
        "is", 
        "exhausted",
        "to", 
        "print", 
        "on", 
        "the", 
        "screen", 
        "information", 
        "about", 
        "the", 
        "entered", 
        "words", 
        "and", 
        "their", 
        "occupied", 
        "positions", 
        "in", 
        "the",
        "buffer",
    };

    positions= FindEmptyPositions(buffer);

    //Allocate loop
    while(words.size())
    {   
        cout<<"Word size: "<<words.back().size()<<endl;
        cout<<"EnoughSpace 0: "<<EnoughSpace(positions,0,words.back().size())<<endl;
        if (!EnoughSpace(positions,0,words.back().size())) 
        {
            cout<<"Pop!"<<endl;
            words.pop_back();
        }
        else
        {
        AllocateWord(buffer,positions,words);
        }
    }
        system("pause");
}
