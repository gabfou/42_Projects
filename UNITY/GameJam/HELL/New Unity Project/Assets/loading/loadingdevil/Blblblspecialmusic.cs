using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Blblblspecialmusic : MonoBehaviour {

	// Use this for initialization
	float dg = 20;
	public bool gaucher = false;
	float timesincelast = 0;
	public bool isactive = true;
	public List<float> timespin;
	public AudioSource source;

	// Use this for initialization
	void Start () {
		if (gaucher == false)
			transform.Rotate(Vector3.forward, -10);
		else
		{
			transform.Rotate(Vector3.forward, 10);
			dg *= -1;
		}
	}
	
	// Update is called once per frame
	void Update () {
		if (!isactive)
			return;

		if (timespin.Count > 0 && source.time > timespin[0])
		{
			transform.Rotate(Vector3.forward, dg);
			dg *= -1;
			timespin.RemoveAt(0);
			
		}
	}
}
