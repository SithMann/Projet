#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char * s = "\033[44m";
    printf("%s",s); //Set the text to the color red
    printf("Hello\n"); //Display Hello in red
    printf("\033[0m"); //Resets the text to default color
    return 0;
}