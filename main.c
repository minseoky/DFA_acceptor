#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAvailable(char input[]);

int main() {
    char input[256];
    while(true){
        printf("INPUT: ");
        scanf("%s", input);
        if(strcmp(input, "x") == 0){
            printf("EXIT\n");
            return 0;
        }
        if(isAvailable(input)){
            printf("accept\n");
        }
        else{
            printf("reject\n");
        }
    }
}

bool isAvailable(char input[]){
    //state = 0 : DFA시작 상태
    //state = 1 : b
    //state = 2 : bb
    //state = 3 : bbb(종결상태)
    int state = 0;
    for(int idx = 0 ; idx < strlen(input) ; idx++){
        if(state == 0){
            if(input[idx] == 'a'){
                state = 0;
            }
            else if(input[idx] == 'b'){
                state = 1;
            }
        }
        else if(state == 1){
            if(input[idx] == 'a'){
                state = 0;
            }
            else if(input[idx] == 'b'){
                state = 2;
            }
        }
        else if(state == 2){
            if(input[idx] == 'a'){
                state = 0;
            }
            else if(input[idx] == 'b'){
                return true;
            }
        }
    }
    return false;
}