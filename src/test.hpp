#pragma once

#include "godot_cpp/variant/string.hpp"
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/classes/node.hpp>

class Test : public godot::Node{
GDCLASS(Test, godot::Node)
protected:
static void _bind_methods();
private:
    godot::String my_data = "Building game";

    godot::String get_my_data() const;
    void set_my_data(const godot::String &new_data);

    void say_hello();


};