#include<bits/stdc++.h>
using namespace std;

bool checkOperator(char ch){
    char operators[] = "+-*/%=(){},";
    for (int i = 0; i < 11; ++i){
        if (ch == operators[i]){
            return true; 
        }
    }
    return false;
}


int checkKeyWord(string program){
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i){
        if (keywords[i] == program){
            flag = 1;
            break;
        }
    }
    return flag;
}


void Check(string &program){
    if(program.size() != 0){
        if (checkKeyWord(program) == 1){
            cout << program <<  " is keyword" << endl;
        }
        else{
            if(program == "include" || program =="stdioh" || program == "define" || program == "stdlibh" || program == "stringh" || program == "ctypeh" || program == "bitsstdch"){
                cout << program << " is not an identifier" << endl;
            }else{
                cout << program << " is identifer" << endl;
            }
        }
        program = "";
    }
}

int main(){
    char ch;
    string program = "";
    FILE *file;
    file = fopen("input.c", "r");
    if (file == NULL){
        printf("Error while opening file ...\n");
        exit(0);
    }
    while ((ch = fgetc(file)) != EOF){   
        if(checkOperator(ch)){
            cout << ch << " is operator" << endl;
            Check(program);
        }
        if(isalnum(ch)){
            program += ch;
        }
        else if ((ch == ' ' || ch == '\n') && (program.size() != 0)){
            Check(program);
        }
    }
    fclose(file);
    cout << endl;
    return 0;
}
