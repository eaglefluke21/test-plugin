#include "test.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/print_string.hpp>


void Test::say_hello()
{
    godot::print_line("hello");
};

void Test::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("say_hello"),&Test::say_hello);
    godot::ClassDB::bind_method(godot::D_METHOD("set_my_data","new_data"), &Test::set_my_data);
    godot::ClassDB::bind_method(godot::D_METHOD("get_my_data"), &Test::get_my_data);
    
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::STRING,"my_data"), "set_my_data", "get_my_data");
};

godot::String Test::get_my_data() const
{
    return my_data;
};

void Test::set_my_data(const godot::String &new_data)
{
    my_data = new_data;
};
