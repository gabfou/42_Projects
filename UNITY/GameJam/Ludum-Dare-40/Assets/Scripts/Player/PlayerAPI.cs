using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Invector.CharacterController;

public class PlayerAPI : MonoBehaviour
{
	vThirdPersonController	controller;
	vThirdPersonInput		input;

	public readonly float		defaultPlayerJumpPower = 4;
	public readonly float		defaultPlayerWalkSpeed = 2.5f;
	public readonly float		defaultPlayerRunSpeed = 3;
	public readonly float		defaultPlayerSprintSpeed = 4;

	new public Rigidbody	rigidbody { get; private set; }
	public bool				isGrounded { get { return controller.isGrounded; } }
	public float			excitation { get { return controller.excitation; } }

	public float			runSpeed { get { return controller.freeSprintSpeed; } }
	public float			walkSpeed { get { return controller.freeRunningSpeed; } }

	Animator				animator;

	void Awake ()
	{
		controller = FindObjectOfType< vThirdPersonController >();
		input = FindObjectOfType< vThirdPersonInput >();
		rigidbody = controller.GetComponent< Rigidbody >();
		animator = controller.GetComponent< Animator >();
	}

	public void Jump(float jumpPower)
	{
		controller.jumpHeight = jumpPower;
		controller.Jump();
	}

	public void AddMovement(Vector2 add)
	{
		controller.input.x += add.x;
		controller.input.y += add.y;
	}

	public void SetRunSpeed(float speed)
	{
		animator.speed = speed / defaultPlayerSprintSpeed;
		controller.freeSprintSpeed = speed;
	}
	public void SetWalkSpeed(float speed)
	{
		animator.speed = speed / defaultPlayerRunSpeed;
		controller.freeRunningSpeed = speed;
		controller.freeWalkSpeed = speed;
	}
	public void AddExcitation(float excitation) { controller.excitation += excitation; }
}
