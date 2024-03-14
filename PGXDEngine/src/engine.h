#include "raylib.h"

#include "types.h"
#include "util.h"
#include "input.h"
#include "camera.h"
#include "player.h"
#include "resource.h"
//#include "level.h"
//#include "components.h"
#include "ecsmain.h"


#define PGXDPURPLE CLITERAL(Color){ 51, 0, 255, 255 }
#define PGXDPURPLELO CLITERAL(Color){ 51, 0, 255, 127 }
#define PGXDPURPLELLO CLITERAL(Color){ 51, 0, 255, 63 }

void drawSplash(resource_dir_s resd);