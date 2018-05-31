using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class goombacontroller : MonoBehaviour {

	new Rigidbody2D	rigidbody2D;
	public bool canmove = false;
	public int dir = -1;
	public float speed = 15;
	public float collengt = 3f;
	public float ejectpower = 100f;
	EdgeCollider2D	EdgeCollider2d;
	BoxCollider2D		boxCollider2d;
	Animator		anim;

	// Use this for initialization
	void Start () {
		EdgeCollider2d = GetComponent< EdgeCollider2D >();
		boxCollider2d = GetComponent< BoxCollider2D >();
		rigidbody2D = GetComponent< Rigidbody2D >();
		anim = GetComponent< Animator >();
	//	transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);
	}
	
	// Update is called once per frame
	void FixedUpdate () {
		if (canmove == true)
		{
			RaycastHit2D[] results = new RaycastHit2D[1];
			int collisionNumber = Physics2D.RaycastNonAlloc(transform.position, new Vector3(dir, 0, 0), results, collengt, 1 << LayerMask.NameToLayer("Ground"));
			// Debug.DrawLine(transform.position, transform.position + new Vector3(dir * collengt, 0, 0), Color.red, 1f);
			if (collisionNumber > 0)
				dir = -dir;
			transform.localScale = new Vector3(dir, transform.localScale.y, transform.localScale.z);
			rigidbody2D.velocity = new Vector2(dir * speed, 0);
		}
	}

	Rigidbody2D rb2d;
	void OnTriggerEnter2D(Collider2D other)
	{	
		
		print ("goomba triger");
		if (other.tag == "Player")
		{
			canmove = false;
			rb2d = other.GetComponent< Rigidbody2D >();
			rb2d.velocity = new Vector2(0, 0);
			rb2d.AddForce(new Vector2(0, ejectpower), ForceMode2D.Impulse);
			boxCollider2d.enabled = false;
			EdgeCollider2d.enabled = false;
			anim.SetTrigger("death");
		}
	}

	void OnBecameVisible()
	{
		print("I SEE YOU");
		canmove = true;
	}
}
