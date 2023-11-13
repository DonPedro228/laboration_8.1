#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* User_Input() {
    const int size = 101;
    static char str[size];

    cout << "Enter string:" << endl;
    cin.getline(str, size);

    return str;
}

int Find_Three_Oklyk(char* str) {
    if (strlen(str) < 3)
        return 0;

    int k = 0;
    for (int i = 0; str[i+1] != 0; i++) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            k++;
            i += 2;
        }
    }
    if (k > 0) {
        return k;
    }else
        return 0;
}

void Replace_Group_With_Oklyk(char* str) {
    int len = strlen(str);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            str[i] = '*';
            str[i + 1] = '*';
            memmove(str + i + 2, str + i + 3, strlen(str + i + 3) + 1);
        }
    }
}

int main() {
    char* Input = User_Input();
    int count = 0;
    count = Find_Three_Oklyk(Input);
    cout <<"Count of Group !!! = " << count << endl;
    Replace_Group_With_Oklyk(Input);
    cout << Input << endl;
    return 0; 
}