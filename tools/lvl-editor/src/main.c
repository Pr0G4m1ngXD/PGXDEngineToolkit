#include "PGXDEngine/src/engine.h"

int main() {
    resource_dir_s resd = { 0 };
    if (tryLoadResource(&resd)) {
        exit(1);
    }
    /*
    ecs_world_t* world = ecs_init();

    ECS_COMPONENT(world, v3position);
    ECS_COMPONENT(world, model_s);

    ecs_entity_t e = ecs_new_id(world);

    ecs_set(world, e, v3position, { 2, 4, 6 });
    ecs_set(world, e, model_s, { .path = "data/models/door_exit.glb" });

    const ecs_world_to_json_desc_t t = (ecs_world_to_json_desc_t){ .serialize_builtin = false, .serialize_modules = true };
    const ecs_entity_to_json_desc_t et = (ecs_entity_to_json_desc_t){
        .serialize_alerts = true,
        .serialize_base = true,
        .serialize_brief = true,
        .serialize_color = true,
        .serialize_hidden = true,
        .serialize_id_labels = true,
        .serialize_ids = true,
        .serialize_label = true,
        .serialize_link = true,
        .serialize_matches = true,
        .serialize_path = true,
        .serialize_private = true,
        .serialize_refs = true,
        .serialize_type_info = true,
        .serialize_values = true,
    };


    FILE* f = fopen("out.lvl", "w");
    fputs(ecs_world_to_json(world, &t), f);
    fputs(ecs_entity_to_json(world, e, &et), f);
    fclose(f);

    ecs_fini(world);
    */



    return 0;
}