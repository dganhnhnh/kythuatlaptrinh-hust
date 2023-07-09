#include<bits/stdc++.h>
#include <conio.h>

using namespace std;

int outerChoice;


void handleInput(){
    cout << "Input" << endl;
}

void handleOutput(){
    cout << "Output" << endl;
}

void handleExit(){
    cout << "Exit" << endl;
}

void prompt(){
    // menu of 3 choices: input, output, exit
    cout << "\n1. Input" << endl;
    cout << "2. Output" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;
    outerChoice = choice;
    switch(choice){

        case 1:
            handleInput();
            break;
        case 2:
            handleOutput();
            break;
        case 3:
            handleExit();
            break;
        default:
            cout << "Invalid choice " << choice << endl;
            break;
    }
}
int main(){
    // prompt();
    while(outerChoice!= 3){

        prompt();
        // cout<< cin.get();
        // cin.get();
        // cout<< 
        // getchar();
        cout<< "Bam phim bat ky de tiep tuc";
        _getch();
        // if (getchar()){
        //     continue;
        // }
    }
}