using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class blblbl : MonoBehaviour {

	float dg = 20;
	float timesincelast = 0;
	public bool isactive = true;

	// Use this for initialization
	void Start () {
		transform.Rotate(Vector3.forward, -10);
	}
	
	// Update is called once per frame
	void Update () {
		if (!isactive)
			return;
		timesincelast += Time.deltaTime;

		if (timesincelast > 0.1f)
		{
			transform.Rotate(Vector3.forward, dg);
			dg *= -1;
			timesincelast = 0;
		}
	}
}
