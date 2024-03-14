#include "resource.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tryLoadResource(resource_dir_s* res) {
    FILE* file;
    file = fopen("../resources/core/gameinfo", "r");
    if (!file) {
        file = fopen("resources/core/gameinfo", "r");
        if (!file) {
            return 1;
        }
        else {
            strcpy(res->path, "resources/");
            return 0;
        }
    }
    else {
        strcpy(res->path, "../resources/");
        return 0;
    }
}

char* getResourceLocation(resource_dir_s res, const char* loc) {
    char* result = malloc(strlen(res.path) + strlen(loc) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, res.path);
    strcat(result, loc);
    return result;
}