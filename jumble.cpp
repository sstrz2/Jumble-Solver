#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

int main(int argc, char *argv[]){
  unordered_map<string, vector<string>> dict;
  ifstream file;
  string word;
  string sorted;
  string bigClass;
  unsigned numWords=0;
  unsigned numClasses=0;
  unsigned bigSize=0;


  if(argc != 2) {
    std::cout << "usage:  ./freq <filename>\n";
    std::cout << "goodbye\n";
    return 1;
  }
  file.open(argv[1], ios::in);

  if(!file.is_open()){
    std::cout << "Error: could not open file '" <<
                     argv[1] << "'\n";
    std::cout << "goodbye\n";
    return 1;
  }
  std::cout << "reading input file...\n";

  while(file >> word) { 
    sorted=word;
    sort(sorted.begin(),sorted.end());
    if(dict.count(sorted) > 0){
        dict[sorted].push_back(word);
    }
    else{
        dict[sorted].push_back(word);
        numClasses++;
    }
    numWords++;
    if(dict.at(sorted).size() > bigSize){
        bigSize=dict.at(sorted).size();
        bigClass=sorted;
    }
  }

  file.close();
  cout << "start entering jumbled words (ctrl-d to terminate)\n";
  while(cin >> word){
    sorted=word;
    sort(sorted.begin(),sorted.end());
    if(dict.count(sorted) > 0){
        cout << "English Anagrams Found:\n";
        for(int i=0;i<dict.at(sorted).size();i++){
            cout << "    " << dict.at(sorted).at(i)<<endl;
        }
    }
    else{
        cout << "no anagrams found...try again\n";
    }
  }
  cout << "REPORT:\n\n";
  cout << "num_words             :  " << numWords << endl;
  cout << "num_classes           :  " << numClasses << endl;
  cout << "size-of-largest-class :  " << bigSize << endl;
  cout << "largest-class key     :  " << bigClass << endl;
  cout<< "members of largest class:\n\n";
  for(int i=0;i<dict.at(bigClass).size();i++){
    cout << " '" << dict.at(bigClass).at(i)<<"'\n";
  }   



}
