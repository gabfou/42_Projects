using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class colliderZone : MonoBehaviour {

	perso victim;
	GameObject parent;
	perso player;

	ParticleSystem pa;

	void Start () {
		parent = GameObject.FindGameObjectWithTag ("Player");
		player = parent.GetComponent<perso> ();
		pa = GetComponent< ParticleSystem > ();
		pa.Emit (5);
		GameObject.Destroy (gameObject, gameObject.GetComponent<ParticleSystem>().main.duration);
	}


	void	OnTriggerStay(Collider Col)
	{
		if (Col.tag != "mechant")
			return;
		else
			victim = Col.gameObject.GetComponent<perso> ();
		Debug.Log ("victim : " + victim);
		int roll = Random.Range (0, 100);
		if (!(roll > 75 + player.AGI - victim.AGI)) {
			int basedamage = Random.Range (player.minDamage / 3, player.maxDamage / 3);
			victim.ouch (basedamage * (1 - victim.Armor / 200));
		}

	}

}
