#include "player.hpp"
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/print_string.hpp>

using namespace godot;

void Player::_physics_process(double delta) {
    Vector2 dir = Vector2(0,0);
    Input* input = Input::get_singleton();

    // Horizontal input
    if (input->is_action_pressed("ui_right"))
        dir.x += 1;
    if (input->is_action_pressed("ui_left"))
        dir.x -= 1;

    // Get current velocity
    Vector2 vel = get_velocity();

    // Horizontal movement
    vel.x = dir.x * speed;

    // Gravity
    vel.y += 1000.0 * delta;

    // Jump
    if (input->is_action_just_pressed("ui_up") && is_on_floor())
        vel.y = jump_velocity;

    set_velocity(vel);

    // Move and slide — no arguments in Godot 4 C++
    move_and_slide();
}


void Player::_bind_methods() {
    // Only bind custom methods
    // e.g., ClassDB::bind_method(D_METHOD("say_hello"), &Player::say_hello);
}
