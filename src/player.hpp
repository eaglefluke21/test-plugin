#pragma once
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class Player : public CharacterBody2D {
    GDCLASS(Player, CharacterBody2D)
protected:
    static void _bind_methods();
public:
    float speed = 200.0;
    float jump_velocity = -400.0;

    void _physics_process(double delta) override;
};

