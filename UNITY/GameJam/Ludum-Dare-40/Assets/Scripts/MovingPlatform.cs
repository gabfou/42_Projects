using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovingPlatform : MonoBehaviour
{
	public List< Vector3 >	list = new List< Vector3 >();
	public float			speed = 1f;
	private int				index;

	public bool		canMove = true;
	private	Rigidbody player = null;
	private Vector3 Last;
	public bool	needcol = false;
	// Use this for initialization
	void Start () {
		index = 0;
	}
	
	// Update is called once per frame
	void FixedUpdate () {
		if (!canMove || needcol)
			return ;
		
		if ((list [index] - transform.position).magnitude > 0.01)
		{
			transform.position = Vector3.MoveTowards (transform.position, list [index], speed * Time.deltaTime);
			if (player)
			{
				// Vector3 tmp = player.velocity;
				player.position = Vector3.MoveTowards(player.position, player.position + (transform.position - Last), Mathf.Infinity);
				// tmp = player.velocity;
			}
		}
		else if (index < list.Count - 1)
			index++;
		else
			index = 0;
		Last = transform.position;
	}
	
	void OnCollisionEnter(Collision other)
	{
		if (other.gameObject.tag == "Player")
		{
			needcol = false;
			player = other.gameObject.GetComponent<Rigidbody>();
		}
	}

	void OnCollisionExit(Collision other)
	{
		if (other.gameObject.tag == "Player")
			player = null;
	}
}
