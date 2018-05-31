using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class turret : MonoBehaviour {
	public GameObject bullet;
	float timesinceprevious;
	public float spawntime;
	float		realspawntime;
	public float range;
	public GameObject player;
	public float addrandomspawnrange = 0;
	public float timebeforeactive = 0;
	public float	Accelebysecond;
	public float	timestopshooting = Mathf.Infinity;
	public float vitessemin;

	LayerMask l;
	// Use this for initialization
	void Start () {
		realspawntime = spawntime + Random.Range(0, addrandomspawnrange + 1);
	}
	
	// Update is called once per frame
	void Update ()
	{
		if (spawntime - Time.deltaTime * Accelebysecond > vitessemin)
			spawntime -= Time.deltaTime * Accelebysecond;
		if (timebeforeactive > Time.timeSinceLevelLoad)
			return ;
			// Debug.Log(Time.time);

		timesinceprevious += Time.deltaTime;
		
		GetComponent<SpriteRenderer>().enabled = true;

		if (timesinceprevious > realspawntime && Time.timeSinceLevelLoad < timestopshooting)
		{
			RaycastHit2D hit = Physics2D.Raycast(transform.position, Vector3.Normalize(player.transform.position - transform.position), range);
			if (hit.collider != null && hit.collider.tag == "Player") {
				GameObject.Instantiate (bullet, transform.position, Quaternion.identity);
			}
			timesinceprevious = 0;
			realspawntime = spawntime + Random.Range(0, addrandomspawnrange + 1);
		}
	}
}
