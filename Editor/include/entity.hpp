#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include "entt.hpp"
#include "scene.hpp"
#include "light.hpp"

class Entity {
    Entity(entt::entity entity, Scene* scene);
    template<typename T, typename... Args>
    inline T& addComponent(Args... args) {
        if (m_scene.m_registry.has<T>(m_entity))
            LIGHT_CORE_ERROR("Entity already has the component!");
        return m_scene->m_registry.emplace<T>(std::forward(args)...);
    }
private:
    entt::entity m_entity;
    Scene* m_scene;
};

#endif // __ENTITY_HPP__
