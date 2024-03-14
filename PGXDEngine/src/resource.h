
typedef struct resource_dir {
    char path[64];
} resource_dir_s;

int tryLoadResource(resource_dir_s* res);

char* getResourceLocation(resource_dir_s res, const char* loc);