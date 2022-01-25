#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream source ;
    source.open(filename.c_str());
    string file1;
    char check[]= "%[^:]: %d %d %d";
    char name[100];
    int a1,a2,a3;
    while(getline(source,file1)){
        sscanf(file1.c_str(),check,name,&a1,&a2,&a3);
        names.push_back(name);
        scores.push_back(a1+a2+a3);
        grades.push_back(score2grade(a1+a2+a3));
        
    }
    source.close();

}

void getCommand(string &command, string &key){
    string kee;
    int sub;
    cout<<"Please input your command: ";
    getline(cin,kee);
    sub = kee.find_first_of(" ");
    command = kee.substr(0,sub);
    key = kee.substr(sub+1);

}

void searchName(vector<string> name, vector<int> scores, vector<char> grades, string key){
    bool checker = false;
    for(unsigned int i=0;i<name.size();i++){
        if(key == toUpperStr(name[i])){
            checker = true ;
            cout<<"---------------------------------"<<"\n";
            cout<< name[i]<<"'s score = "<< scores[i] <<"\n";
            cout<< name[i]<<"'s grade = "<< grades[i] <<"\n";
            cout<<"---------------------------------"<<"\n";

        }
    }
    if(checker == false){
        cout<<"---------------------------------"<<"\n";
        cout<<"Cannot found. "<<"\n";
        cout<<"---------------------------------"<<"\n";
    }

}

void searchGrade(vector<string> name,vector<int> scores, vector<char> grades, string key){
    cout<<"---------------------------------"<<"\n";
    for(unsigned int i=0;i<grades.size();i++){
        if(key[0] == grades[i]){
        cout<< name[i] << " "<<"("<<scores[i] <<")"<<"\n";
        }
        
    }
    cout<<"---------------------------------"<<"\n";
}
    

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
