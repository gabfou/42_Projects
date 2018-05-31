using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class attackFireball : spell {

	public 	GameObject 	coll;
	public 	int 		manaCost;
	private RaycastHit 	_hit;
	private Vector3 	_position;
	private Vector3		_direction;
	float truc = 0;


	public override List<string> attack(perso attacker, perso victim, float distanceNVA)
	{
		List<string> r = new List<string>();

		r.Add ("stopmoving");

		if (attacker.mana >= manaCost) {

			attacker.mana -= manaCost;

			attackinit ();

			Ray ray = Camera.main.ScreenPointToRay (Input.mousePosition);
			if (Physics.Raycast (ray, out _hit, 1000)) {
				_position = _hit.point;
			}

			_direction = (_hit.point - attacker.transform.position).normalized;

			truc += Time.deltaTime;

			GameObject instance = Instantiate (coll, attacker.transform.position, Quaternion.Euler (_direction));
			instance.GetComponent<colliderFireball> ().hitPoint = _hit.point;
			instance.GetComponent<colliderFireball> ().level = base.level;

			if (truc > 0.25) {
				truc = 0;
				instance.GetComponent<colliderFireball> ().damage = true;
			}
		}
		r.Add ("finish");

		return (r);
	}
}
