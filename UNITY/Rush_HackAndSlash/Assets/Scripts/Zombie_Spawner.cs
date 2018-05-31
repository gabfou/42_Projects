using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Zombie_Spawner : MonoBehaviour {

	public	GameObject	ZombiePrefabA;
	public	GameObject	ZombiePrefabB;
	private	GameObject	Inst;
	private	bool 		incoming;
	private bool		isplayernear = false;
	// Use this for initialization
	void Start () {
		
	}

	void	OnTriggerStay(Collider Col)
	{
		if (Col.tag == "Player")
			isplayernear = true;
	}

	void	OnTriggerExit(Collider Col)
	{
		if (Col.tag == "Player")
			isplayernear = false;
	}


	// Update is called once per frame
	void Update () {
		if (isplayernear && !incoming && Inst == null) {
			float k = Random.Range (1, 10);
			StartCoroutine (spawning (k));
		}
	}

	IEnumerator		spawning(float k) {
		incoming = true;
//		Debug.Log ("waitfor = " + k);
		yield return new WaitForSeconds (k);
		if (Random.Range(1, 3) == 1)
			Inst = Instantiate (ZombiePrefabA, transform.position, transform.rotation);
		else
			Inst = Instantiate (ZombiePrefabB, transform.position, transform.rotation);
		incoming = false;
	}
}
