using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class attackZone : spell {

	public 	GameObject 	coll;
	public 	int 		manaCost;
	private RaycastHit 	_hit;
	private Vector3 	_position;

	public override List<string> attack(perso attacker, perso victim, float distanceNVA)
	{
		List<string> r = new List<string>();

		r.Add ("stopmoving");

		if (attacker.mana >= manaCost) {

			attacker.mana -= manaCost;

			attackinit ();

			Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			if (Physics.Raycast (ray, out _hit, 1000)) {
				_position = _hit.point;
			}
			GameObject.Instantiate (coll, _position, Quaternion.identity);

		}
		r.Add ("finish");

		return (r);
	}
}
