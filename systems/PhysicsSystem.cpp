//
// Created by admin on 10/29/26.
//

#include "PhysicsSystem.h"

#include <iostream>

#include "../components/Components.h"
#include "../tags/Tags.h"

void PhysicsSystem::update(entt::registry &registry, float deltaTime) {
    // Сложность алгоритма линейное время 0(n2), в таких случаях, я буду использовать продвинутую библиотеку, или собирать алгоритм сам.
    // Баг пофикшен, я проверял размер самой модели, но не размер (Mesh), ?x?x?
    const entt::basic_view view = registry.view<PlayerTag, PhysicsTag, TransformComponent, SizeComponent>();
    const entt::basic_view allView = registry.view<PhysicsTag, TransformComponent, SizeComponent>();
    for (auto&&[entity_l, transform_l, size_l] : allView.each()) {
        const Vector3 min_l = {.x = transform_l.position.x - size_l.size_v.x, .y = transform_l.position.y - size_l.size_v.y, .z = transform_l.position.z - size_l.size_v.z};
        const Vector3 max_l = {.x = transform_l.position.x + size_l.size_v.x, .y = transform_l.position.y + size_l.size_v.y, .z = transform_l.position.z + size_l.size_v.z};
        const BoundingBox box_l = {.min = min_l, .max = max_l};
        for (auto&&[entity, transform, size] : view.each()) {
            if (entity == entity_l) continue;
            const Vector3 min = {.x = transform.position.x - size.size_v.x, .y = transform.position.y - size.size_v.y, .z = transform.position.z - size.size_v.z};
            const Vector3 max = {.x = transform.position.x + size.size_v.x, .y = transform.position.y + size.size_v.y, .z = transform.position.z + size.size_v.z};
            if (const BoundingBox box = {.min = min, .max = max}; CheckCollisionBoxes(box, box_l)) {
                transform.position.y = transform.vel_position.y;
                transform.velocity.y = .0f;
            }
        }
    }

}
