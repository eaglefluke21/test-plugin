#pragma once

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

class Player : public CharacterBody2D {
    GDCLASS(Player, CharacterBody2D)

private:
    double speed = 200;
    double jump_velocity = -400;

protected:
    static void _bind_methods();

public:
    void _physics_process(double delta) override;
};
