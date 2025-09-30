extends Node2D

func _ready():
	print("Player class registered?", ClassDB.class_exists("Player"))

	replace_with_cpp("Player", "Player")
	replace_with_cpp("Ground", "Ground")  # optional for other C++ nodes

# -------------------------------
# Helper function in same file
func replace_with_cpp(node_path: NodePath, cpp_class_name: String) -> Node:
	var old_node = get_node(node_path)
	if not old_node:
		push_error("Node not found: %s" % node_path)
		return null

	var parent = old_node.get_parent()
	var idx = old_node.get_index()

	var cpp_instance = ClassDB.instantiate(cpp_class_name)
	if not cpp_instance:
		push_error("C++ class not found: %s" % cpp_class_name)
		return null

	cpp_instance.name = old_node.name
	cpp_instance.position = old_node.position
	cpp_instance.scale = old_node.scale
	cpp_instance.rotation = old_node.rotation

	for child in old_node.get_children():
		old_node.remove_child(child)
		cpp_instance.add_child(child)

	parent.remove_child(old_node)
	parent.add_child(cpp_instance)
	parent.move_child(cpp_instance, idx)
	cpp_instance.owner = parent

	return cpp_instance
