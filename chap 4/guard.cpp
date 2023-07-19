#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[100]; char *searchValue;
    *searchValue = 'a';
    int size,pos; 
    bool found;
    cin>>s;
    size = strlen(s);
    strcat(s, searchValue);
    pos = 0;
    while(s[pos]!= *searchValue)
        pos++;
    if(pos< size) found = 1;
    else found =0;
    cout << found << " "<< pos;
    return 0;
}