using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class fourche : MonoBehaviour {

	playerloadingdevilcontroller p;
	Vector3 dir;
	public float speed;
	// Use this for initialization
	void Start () {
		p = Camera.main.GetComponent<charon>().obj.GetComponent<playerloadingdevilcontroller>();
		Vector3 tmp = new Vector3(p.transform.position.x + Random.Range(-2, 3), p.transform.position.y + Random.Range(-2, 3), p.transform.position.z);
		dir = tmp - transform.position;
		dir.Normalize();
	}
	
	// Update is called once per frame
	void Update () {
		transform.position += speed * Time.deltaTime * dir;
		if (transform.position.x > 20 || transform.position.x < -20 || transform.position.y > 20 || transform.position.y < -20)
			GameObject.Destroy(gameObject);
	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag == "Player")
			GameObject.Destroy(gameObject);
	}
}
