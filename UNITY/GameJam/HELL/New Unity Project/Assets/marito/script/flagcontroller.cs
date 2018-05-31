using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class flagcontroller : MonoBehaviour {

	Animator		anim;
	// Use this for initialization
	void Start () {
		anim = GetComponent< Animator >();
	}
	
	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag == "Player")
		{
			anim.SetTrigger("end");
		}
	}
}
