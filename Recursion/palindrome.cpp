#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str,int start,int end){
    if(start>=end){
        return true;
    }
    if(str[start]!=str[end]){
        return false;
    }
    return isPalindrome(str,start+1,end-1);

}

int main(){
    string user_input;
    cout<<"Enter a string to check if it is palindrome :";
    cin>>user_input;

    if (isPalindrome(user_input, 0, user_input.length() - 1)) {
        cout << user_input << " is a palindrome." << endl;
    } else {
        cout << user_input << " is not a palindrome." << endl;
    }

    return 0;
}