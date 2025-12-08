//
// Created by tvolm on 24.11.2025.
//

#ifndef UNTITLED_SPLIT_H
#define UNTITLED_SPLIT_H
int split(char *string ,char splitChar, char **parts, int maxParts, int maxLength);
int split_ignore_empty(char *string ,char splitChar, char **parts, int maxParts, int maxLength);

#endif //UNTITLED_SPLIT_H