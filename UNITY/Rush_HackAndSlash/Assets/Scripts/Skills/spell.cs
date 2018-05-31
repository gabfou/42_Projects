using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class spell : MonoBehaviour {
	
	protected Animator				animator;
	protected GameObject 			g;
	[HideInInspector] public bool	moving = false;
	protected float timeattack = 0;
	public string name;
	public string description;
	public int level = 1;
	// Use this for initialization
	void Start () {
		animator = GetComponentInParent< Animator > ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	protected void attackinit()
	{
		animator.SetBool ("auto", false);
		animator.SetBool ("tourbilol", false);
	}

	public virtual List<string> attack(perso attacker, perso victim, float distanceNVA)
	{
		List<string> r = new List<string>();

		if (victim != null && Vector3.Distance (transform.position, victim.transform.position) <= 4f) {
			timeattack += Time.deltaTime;
			attackinit ();
			animator.SetBool ("auto", true);
			if (timeattack > 0.50) {
				int roll = Random.Range (0, 100);
				if (!(roll > 75 + attacker.AGI - victim.AGI)) {
					int basedamage = Random.Range (attacker.minDamage, attacker.maxDamage);
					victim.ouch (basedamage * (1 - victim.Armor / 200));
				}
				timeattack = 0;
				r.Add("finish");
			}
			r.Add("stopmoving");
			animator.SetBool ("attack", true);
			animator.SetBool ("run", false);
		} else {
			animator.SetBool ("attack", false);
			animator.SetBool ("run", (distanceNVA > 0.5f));
		}
			
		return (r);
	}
}
