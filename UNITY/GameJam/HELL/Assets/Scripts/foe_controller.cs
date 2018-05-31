using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class foe_controller : MonoBehaviour {


	public	GameObject		Ammo;
	public	GameObject		GameManager;
	public	float			SpeedH;
	public	float			SpeedV;

	private	float			i;
	private float			j;
	private	float			vit;
	private	GameObject		curShoot;
	private	Game_Manager	GM;
	// private float			bl = 0;


	// Use this for initialization
	void Start () {
		GM = GameManager.GetComponent<Game_Manager>();
		i = 0;
		vit = 10;
	}
	
	// Update is called once per frame
	void Update () {
		if (GM.GameState) {
			if ((Random.Range(0f, vit) <= 0.01f))
				Shoot();
			if (i == 0) {
				transform.position = new Vector3(transform.position.x, transform.position.y - SpeedV * Time.deltaTime * 60f, 0);
				j = SpeedH;
			} else if (i == 25) {
				transform.position = new Vector3(transform.position.x, transform.position.y - SpeedV * Time.deltaTime * 60f, 0);
				j = -SpeedH;
			} else {
				transform.position = new Vector3(transform.position.x + j * Time.deltaTime * 60f, transform.position.y, 0);
				vit *= 0.999f;
			}
			// transform.eulerAngles = new Vector3(0, 0, bl);
			// bl += 0.01f;
			i += j;
		}
	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag == "Player") {
			GM.ScoreUp(20);
			// GM.ScoreUp(20);
			GameObject.Destroy(gameObject);
		}
	}

	void Shoot() {
		curShoot = Instantiate(Ammo, transform.position, Quaternion.identity);
	}

}
