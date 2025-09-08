extends Node2D
func _ready():
	print("Test instance created")
	var my_class = Test.new()  # RefCounted → no need to add_child()
	my_class.say_hello()
	
	print(my_class.my_data);
	my_class.my_data = "changes";
	print(my_class.my_data);
	
