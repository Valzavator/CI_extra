#ifndef CSV_H
#define CSV_H

#include "list.h"

List * CSV_toList(const char * str);
char * CSV_fromList(List * list);

bool isValid(char buffer[][30]);


#endif