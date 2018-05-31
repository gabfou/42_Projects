using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Invector.CharacterController;

public class RagdollController : MonoBehaviour
{
	public bool				activeRagdoll = false;

	Collider[]				ragdollColliders;
	Rigidbody[]				ragdollRigidbodies;
	CharacterJoint[]		ragdollJoints;

	Collider				playerCollider;
	Rigidbody				playerRigidbody;
	vThirdPersonController	playerController;
	vThirdPersonInput		playerInput;
	Animator				playerAnimator;

	// Use this for initialization
	void Start ()
	{
		playerCollider = GetComponent< Collider >();
		playerRigidbody = GetComponent< Rigidbody >();
		playerController = GetComponent< vThirdPersonController >();
		playerInput = GetComponent< vThirdPersonInput >();
		playerAnimator = GetComponent< Animator >();

		ragdollColliders = GetComponentsInChildren< Collider >();
		ragdollRigidbodies = GetComponentsInChildren< Rigidbody >();
		ragdollJoints = GetComponentsInChildren< CharacterJoint >();

		foreach (var c in ragdollColliders)
			c.enabled = false;
		foreach (var r in ragdollRigidbodies)
			r.isKinematic = true;
		foreach (var j in ragdollJoints)
		{
			j.enableCollision = false;
			j.enablePreprocessing = false;
			j.enableProjection = false;
		}
		

		//enable player controller
		playerAnimator.enabled = true;
		playerCollider.enabled = true;
		playerController.enabled = true;
		playerInput.enabled = true;
		playerRigidbody.isKinematic = false;
	}

	void Update()
	{
		if (activeRagdoll)
		{
			ActivateRagdoll();
			activeRagdoll = false;
		}
	}

	public void ActivateRagdoll()
	{
		foreach (var c in ragdollColliders)
			c.enabled = true;
		foreach (var r in ragdollRigidbodies)
			r.isKinematic = false;
		foreach (var j in ragdollJoints)
		{
			j.enableCollision = true;
			j.enablePreprocessing = true;
			j.enableProjection = true;
		}

		//disable player controller
		playerAnimator.enabled = false;
		playerCollider.enabled = false;
		playerController.enabled = false;
		playerInput.enabled = false;
		playerRigidbody.isKinematic = true;
	}
}
