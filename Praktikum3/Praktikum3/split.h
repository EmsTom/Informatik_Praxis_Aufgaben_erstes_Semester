//
// Created by tvolm on 25.11.2025.
//

#ifndef PRAKTIKUM3_SPLIT_H
#define PRAKTIKUM3_SPLIT_H
int split(char *string ,char splitChar, char **parts, int maxParts, int maxLength);
int split_ignore_empty(char *string ,char splitChar, char **parts, int maxParts, int maxLength);
#endif //PRAKTIKUM3_SPLIT_H