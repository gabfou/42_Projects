using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class heal : spell {

	ParticleSystem 	pa;
	public 	int 	manaCost;

	void Start () {
		pa = GetComponent< ParticleSystem > ();
	}

	public override List<string> attack(perso attacker, perso victim, float distanceNVA)
	{
		List<string> r = new List<string>();

		r.Add ("stopmoving");

		if (attacker.mana >= manaCost) {

			attacker.mana -= manaCost;

			attacker.HP += attacker.MaxHP * 0.1f * Time.deltaTime * base.level;

			pa.transform.position = attacker.transform.position;
			if (pa.isStopped) {
				pa.Play ();
			}

		}
		r.Add ("finish");

		return (r);
	}
}
