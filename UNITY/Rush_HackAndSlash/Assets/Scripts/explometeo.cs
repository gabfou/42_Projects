using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class explometeo : MonoBehaviour {

	// Use this for initialization
	public ParticleSystem p;
	public ParticleSystem p2;
	float	t = 0;

	void Start () {
		p.Emit (10);
		p2.Emit (20);
	}

	void	OnTriggerEnter(Collider Col)
	{
		if (t < 0.25 &&  (Col.tag == "Player" || Col.tag == "mechant"))
			Col.gameObject.GetComponent<perso> ().ouch (100);
	}
	
	// Update is called once per frame
	void Update () {
		t += Time.deltaTime;
		if (t > 3f) {
			GameObject.Destroy (gameObject);
		}
	}
}
