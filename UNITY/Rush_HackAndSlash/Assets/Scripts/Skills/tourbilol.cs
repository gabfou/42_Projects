using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class tourbilol : spell {

	// Use this for initialization
	public GameObject parent;
	bool woosh = false;
	perso attackersave;
	ParticleSystem pa;
	public ParticleSystem pa2;
	void Start () {
		base.animator = GetComponentInParent< Animator > ();
		base.moving = true;
		pa = GetComponentInParent< ParticleSystem > ();
		parent = GetComponentInParent<Maya_Controlleur> ().gameObject;
	}
	
	// Update is called once per frame
	void Update () {
		
	}

//	IEnumerator tourbilolauxi()
//	{
//		int i = -1;
//
//		while (++i < 25) {
//			parent.transform.eulerAngles = (parent.transform.eulerAngles - new Vector3(0, 360 / 25, 0));
//			yield return new WaitForSeconds (0.01f);
//		}
//		transform.eulerAngles = new Vector3(0, 0, 0);
//	}

	void	OnTriggerStay(Collider Col)
	{
		perso victim;
//		Debug.Log (Col);
		if (Col.tag != "mechant" || woosh == false)
			return;
		else
			victim = Col.gameObject.GetComponent<perso> ();
		int roll = Random.Range (0, 100);
		if (!(roll > 75 + attackersave.AGI - victim.AGI)) {
			int basedamage = Random.Range (attackersave.minDamage, attackersave.maxDamage );
			victim.ouch ((int)(basedamage * 0.3f * base.level * (1 - victim.Armor / 200)));
		}
	}

	public override List<string> attack(perso attacker, perso victim, float distanceNVA)
	{
		List<string> r = new List<string>();
//		if (timeattack == 0)
//			StartCoroutine (tourbilolauxi ());
		if (woosh == true) {
			woosh = false;
			r.Add ("finish");
			return r;
		}
		timeattack += Time.deltaTime;
		attackinit ();
		if (timeattack > 0.25) {
			woosh = true;
			timeattack = 0;
			attackersave = attacker;
		}
		if (victim == null && distanceNVA < 0.5f) {
			animator.SetBool ("attack", false);
			animator.SetBool ("run", false);
			woosh = false;
		} else {
			animator.SetBool ("tourbilol", true);
			parent.transform.eulerAngles = (parent.transform.eulerAngles - new Vector3(0, 360 * 400 * Time.deltaTime, 0));
			pa.Emit (10);
			if (base.level > 5) {
				pa.Emit (100);
			}
			animator.SetBool ("attack", true);
			animator.SetBool ("run", false);
		}			
		return (r);
	}
}
