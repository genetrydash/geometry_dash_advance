#include <tonc.h>

#define MAX_OBJECTS 32

extern struct Object gObject;
extern u32 *sprite_pointer;

void load_next_object();
void display_objects();