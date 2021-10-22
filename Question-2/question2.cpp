#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
std::string rev(std::string s)
{
    std::string rev;
    for (int i = s.size()-1; i >= 0; i--)
    {
        rev+=s[i];
    }
    return rev;
}
void addA(std::string &init)
{
    init+="A";
    //std::cout<<"[ADD A]: "<< init<<"*"<<std::endl;
}
std::string addB(std::string init)
{
    std::string temp=init;
    temp = rev(temp);
    //std::cout<<"[ADD B]: "<< temp<<"*"<<std::endl;
    return temp+="B";
}


    static std::vector<std::string> vec;


void printVector(std::vector<std::string> vector)
{
    std::cout<<"****************************"<<std::endl;
  for (std::vector<std::string>::iterator it = vector.begin(); it != vector.end(); ++it)
        {
            std::cout << " " << *it;
        }
    std::cout<<std::endl;
    std::cout<<"****************************"<<std::endl;
}

void solve(std::vector<std::string> initial, int targetSize)
{
    std::vector<std::string> temp;
    std::string test;
    for(std::vector<std::string>::iterator it = initial.begin(); it != initial.end(); ++it)
    {
        std::string initWord =*it;
        std::cout<<"initial word "<< initWord<<std::endl;
        std::string tempWord = initWord;

        //Adding A
        addA(initWord);
        initWord.erase(std::remove_if(initWord.begin(), initWord.end(), ::isspace), initWord.end());
        vec.push_back(initWord);
        vec.shrink_to_fit();
        temp.push_back(initWord);

        //Adding B
        tempWord = addB(tempWord);
        tempWord.erase(std::remove_if(tempWord.begin(), tempWord.end(), ::isspace), tempWord.end());
        vec.push_back(tempWord);
        vec.shrink_to_fit();

        temp.push_back(tempWord);


        test = tempWord;
    }
    int longestWord = vec.back().size();
    std::cout<<"test size "<< test.size()<<std::endl;
    std::cout<<"vec at "<< vec.at(vec.size()-1)<<std::endl;
    std::cout<<"target size "<< targetSize<<std::endl;
    for (int i = 0; i <longestWord; i++)
    {
        std::cout<< vec.back()[i]<<std::endl;
    }
    
    if (longestWord < 999 && test.size() < targetSize)
    {
        solve(temp,targetSize);
    }
}



int main()
{
    bool check = false;
    std::string init;
    std::cin>>init;
    std::vector<std::string> task;
    std::string result;
    std::cin>>result;
    task.push_back(init);
    solve(task,result.size());
    printVector(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        std::string value;
        if (vec[i]==result)
        {
            check = true;
            std::cout<<"Okay"<<std::endl;
            break;
        } 
    }
    system("pause");
}
