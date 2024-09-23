#include <stdio.h>
#include <stdlib.h>

char memory[30000] = { 0 };
char *ptr = memory;

void parse(char *arr) {
    char *ch = &arr[0];

    while (*ch) {
        switch (*ch) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        ++ch;

                        if (*ch == '[') 
                            ++loop;
                        else if (*ch == ']') 
                            --loop;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int loop = 1;
                    while (loop > 0) {
                        --ch;

                        if (*ch == '[') 
                            --loop;
                        else if (*ch == ']') 
                            ++loop;
                    }
                }
                break;
        }
        *ch++;
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    
    if (file == NULL) {
        printf("Failed to open the file: %s", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *charArray = (char *) malloc(fileSize *sizeof(char));

    if (charArray == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fread(charArray, sizeof(char), fileSize, file);
    fclose(file);

    parse(charArray);

    free(charArray);
    return 0;
}