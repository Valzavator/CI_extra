#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include <csv.h>
#include <students.h>
#include <list.h>

List * CSV_toList(const char * str) {
    int i = 0;
    List * list = List_new();
    char buffer[10][30] = {"\0", "\0", "\0","\0"};
    int row = 0, col = 0;
    if (strlen(str) == 0) return list;
    for (i = 0; i <= strlen(str); i++) {
        char ch = str[i];     
        if ((ch == '\n' || ch == '\0') && isValid(buffer) == true) {
            List_addLast(list, Student_newFromString(buffer));
            row = 0;
            continue;
        } 
        if (ch == '\n') {
            row = 0; continue;
        } 
        if (ch == ',') {
            row++;
            continue;
        }
        if (isspace(ch)) continue;
        if (isalpha(ch) || isdigit(ch)) {
            while (isalpha(str[i]) || isdigit(str[i]) || str[i] == '.') {
                buffer[row][col] = str[i];
                col++;
                i++;
            }
            buffer[row][col] = '\0';            
            col = 0;
            i--;            
        }
    }
    return list;
}


char * CSV_fromList(List * list) {
    char str[100];
    int i = 0;
    int len = 5;
    for (i = 0; i < List_count(list); i++) {
        len += strlen(Student_toString(List_get(List_elementAt(list, i)), str));
    }
    char * stringCSV = (char *) malloc(sizeof(char) * len);
    stringCSV[0] = '\0';
    for (i = 0; i < List_count(list); i++) {
        Student_toString(List_get(List_elementAt(list, i)), str);
        strcat(stringCSV, str);
        strcat(stringCSV, "\n");
    }
    stringCSV[strlen(stringCSV) - 1] = '\0';
    return stringCSV; 
}

bool isValid(char buffer[][30]) {
    if (strlen(buffer[0]) == 0 || 
        strlen(buffer[1]) == 0 || 
        strlen(buffer[2]) == 0 || 
        strlen(buffer[3]) == 0) return false; 
    if (strlen(buffer[2]) != 0) {
        if(atoi(buffer[2]) == 0) return false;
    } 
    if (strlen(buffer[3]) != 0) {
        if(atof(buffer[3]) < 0.1) return false;
    }
    return true;
}