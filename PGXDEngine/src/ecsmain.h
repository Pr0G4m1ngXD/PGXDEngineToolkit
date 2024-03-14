#include "ecscomponents.h"

uint64_t addComponenent(componentlist_s* clist, ctype_e type, void* data);

uint64_t remComponenent(componentlist_s* clist, ctype_e type, uint64_t entLookup);

uint64_t* findEntWithComponents(componentlist_s* clist, uint8_t typeAmount, ctype_e* type); // 1st value is amount, 2nd onward is entities

void* getDataFromComponent(componentlist_s* clist, ctype_e type, uint64_t entLookup);

uint64_t modComponenent(componentlist_s* clist, ctype_e type, void* data, uint64_t entLookup);

