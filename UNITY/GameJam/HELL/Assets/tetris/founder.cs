using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class founder : MonoBehaviour {

	[HideInInspector] public bool founded = false;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		// this.GetComponent<Collider2D>().
	}
	
	void OnTriggerStay2D(Collider2D other)
	{
		founded = true;
	}

	void OnTriggerExit2D(Collider2D other)
	{
		founded = false;
	}

}
