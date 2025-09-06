#include "test.hpp"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/print_string.hpp>


void Test::say_hello()
{
    godot::print_line("hello");
};

void Test::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("say_hello"),&Test::say_hello);
}
