using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ammo : MonoBehaviour {

	public	float	speed;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		transform.position = new Vector3(transform.position.x, transform.position.y + speed * Time.deltaTime * 60f, 0);
		if (transform.position.y > 70f || transform.position.y < -70f) {
			GameObject.Destroy(gameObject);
		}
	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag != gameObject.tag && other.tag != "Untagged")
			GameObject.Destroy(gameObject);
	}
}
