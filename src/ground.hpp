#pragma once
#include <godot_cpp/classes/static_body2d.hpp>

using namespace godot;

class Ground : public StaticBody2D {
    GDCLASS(Ground, StaticBody2D)
protected:
    static void _bind_methods();
public:
    // Any custom logic can go here, e.g., triggers or events
};
