extends CharacterBody2D

var speed = 200
var jump_velocity = -400  # negative Y = up

func _physics_process(_delta):
	var dir = Vector2.ZERO

	# Left/Right movement
	if Input.is_action_pressed("ui_right"):
		print("ui_right")
		dir.x += 1
	if Input.is_action_pressed("ui_left"):
		print("ui_left")
		dir.x -= 1

	velocity.x = dir.x * speed

	# Jump if on the floor
	if Input.is_action_just_pressed("ui_up") and is_on_floor():
		velocity.y = jump_velocity

	# Apply movement and gravity
	move_and_slide()
