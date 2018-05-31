using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class meteorite : MonoBehaviour {

	// Use this for initialization
	public GameObject explosion;
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void	OnCollisionEnter(Collision Col)
	{
		GameObject.Instantiate (explosion, transform.position, Quaternion.identity);
		GameObject.Destroy (gameObject);
	}
}
