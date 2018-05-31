using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boss : MonoBehaviour {
	public GameObject meteorite;
	float timesincemeteore;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		timesincemeteore +=  Time.deltaTime;
		if (timesincemeteore > 1) {
			timesincemeteore = 0;
			GameObject.Instantiate (meteorite, transform.position + new Vector3(Random.Range(-20, 20), 40, Random.Range(-20, 20)), Quaternion.identity);
		} 
	}
}
