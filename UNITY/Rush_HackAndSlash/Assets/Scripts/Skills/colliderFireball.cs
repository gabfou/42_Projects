using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class colliderFireball: MonoBehaviour {

	perso victim;
	GameObject parent;
	perso player;
	public int level = 1;
	public bool damage = false;

	public Vector3 hitPoint;
	Rigidbody rigid;

	ParticleSystem pa;

	void Start () {
		parent = GameObject.FindGameObjectWithTag ("Player");
		player = parent.GetComponent<perso> ();
		pa = GetComponent< ParticleSystem > ();
		pa.Emit (2);
		GameObject.Destroy (gameObject, 2);
		rigid = GetComponent<Rigidbody> ();
	}

	void Update() {

		if (hitPoint != Vector3.zero) {
			Vector3 dir = (hitPoint - transform.position).normalized;
			Vector3 dirspe = dir / (Mathf.Abs (dir.x) + Mathf.Abs (dir.y) + Mathf.Abs (dir.z));
			transform.eulerAngles = new Vector3 (0, 0, ((dirspe.y + 1) * 90 * ((dirspe.x > 0) ? 1 : -1)) + 90);
			rigid.velocity = dir * 100;
		}
	}

	void	OnTriggerEnter(Collider Col)
	{
		if (damage == false)
			return;
		Debug.Log (Col);
		if (Col.tag != "mechant")
			return;
		else
			victim = Col.gameObject.GetComponent<perso> ();
		Debug.Log ("victim : " + victim);
		int roll = Random.Range (0, 100);
		if (!(roll > 75 + player.AGI - victim.AGI)) {
			int basedamage = Random.Range (player.minDamage, player.maxDamage);
			victim.ouch ((basedamage / 2 * level * (1 - victim.Armor / 200)));
		}

	}

}
