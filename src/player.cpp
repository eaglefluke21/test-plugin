#include "player.hpp"
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/print_string.hpp>

using namespace godot;

void Player::_physics_process(double delta) {
    Vector2 dir = Vector2(0,0);

    Input* input = Input::get_singleton();

    // Left / Right movement
    if (input->is_action_pressed("ui_right")) {
        dir.x += 1;
    }
    if (input->is_action_pressed("ui_left")) {
        dir.x -= 1;
    }

    Vector2 vel = get_velocity();

    vel.x = dir.x * speed;

    // Jump if on floor
    if (input->is_action_just_pressed("ui_up") && is_on_floor()) {
        vel.y = jump_velocity;
    }
    set_velocity(vel);


    // Move and slide
    move_and_slide();
}

void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_physics_process", "delta"), &Player::_physics_process);
}
