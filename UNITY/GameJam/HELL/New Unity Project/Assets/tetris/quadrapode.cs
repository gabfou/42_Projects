using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class quadrapode : MonoBehaviour {

	// Use this for initialization
	[HideInInspector] public int ismoving = 1;
	[HideInInspector] public int ascolitioner = 0;
	// public founder found;
	
	[HideInInspector] public Rigidbody2D rigid;

	void Start () {
		// found.enabled = false;
		rigid = gameObject.GetComponent<Rigidbody2D>();
	}
	
	// Update is called once per frame
	void Update () {
		if (rigid == null)
			return ;
		if (rigid.velocity == new Vector2(0, 0) || rigid.angularVelocity != 0)
			ismoving = 0;
		else
			ismoving = 1;
		// if (rigid.velocity == new Vector2(0, 0))
		// {
		// 	GameObject.Destroy(rigid);
		// 	rigid = null;
		// 	ismoving = 0;
		// }
	}

	public bool raycasthori(float i)
	{
		Vector2 dir = new Vector2(i, 0);
	return (true);
		// found.founded = false;
		// found.enabled = true;
		// if (i < 0)
		// 	found.transform.position = new Vector3(-1, 0, 0) + transform.position;
		// else
		// 	found.transform.position = new Vector3(1, 0, 0) + transform.position;
		// found.enabled = false;
		// return (!found.founded);
		// if (i < 0)
		// 	return (!(Physics2D.Raycast(new Vector2(hightleft.transform.position.x - 0.49f + transform.position.x, hightleft.transform.position.y - 0.49f + transform.position.y), dir, 1)
		// 		|| Physics2D.Raycast(new Vector2(lowleft.transform.position.x - 0.49f + transform.position.x, lowleft.transform.position.y - 0.49f + transform.position.y), dir, 1)));
		// else
		// 	return (!(Physics2D.Raycast(new Vector2(hightright.transform.position.x + 0.49f + transform.position.x, hightright.transform.position.y - 0.49f + transform.position.y), dir, 1)
		// 		|| Physics2D.Raycast(new Vector2(lowright.transform.position.x + 0.49f + transform.position.x, lowright.transform.position.y - 0.49f + transform.position.y), dir, 1)));
	}

	void OnCollisionEnter2D(Collision2D other)
	{
		if (other.gameObject.GetComponent<tetriscase>())
			ascolitioner = 1;
	}

}
