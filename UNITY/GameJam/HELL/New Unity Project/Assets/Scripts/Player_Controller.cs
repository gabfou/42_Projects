using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Player_Controller : MonoBehaviour {

	public	GameObject	Ammo;
	public	float		speed;
	public	GameObject		GameManager;


	private	GameObject	curShoot = null;
	private	Game_Manager	GM;


	// Use this for initialization
	void Start () {
		GM = GameManager.GetComponent<Game_Manager>();

	}
	
	// Update is called once per frame
	void Update () {
		if (GM.GameState) {
			float move = Input.GetAxisRaw("Horizontal"); 
			if (move < 0 && transform.position.x > -45f)
				transform.position = new Vector3(transform.position.x - speed * Time.deltaTime * 2f, transform.position.y, 0);
			else if (move > 0 && transform.position.x < 45f)
				transform.position = new Vector3(transform.position.x + speed * Time.deltaTime * 2f, transform.position.y, 0);
			if (Input.GetKeyDown("space") && !curShoot)
			{
				if (LevelManagerScript.hell == true)
					Shoot();
				else
					heavenshoot();
			}
		}
	}

		void	heavenshoot() {
		Instantiate(Ammo, new Vector3(transform.position.x, transform.position.y + 1f, 0), Quaternion.identity);

		Debug.Log("heavenshoot !!!");
	}

	void	Shoot() {
		curShoot = Instantiate(Ammo, new Vector3(transform.position.x, transform.position.y + 1f, 0), Quaternion.identity);
		Debug.Log("shoot !!!");
	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.tag == "Foe" && LevelManagerScript.hell == true)
		{
			GameOver();
		}
	}

	void GameOver()
	{
		GM.GameOver();
		GameObject.Destroy(gameObject);
		// Debug.Log("GAME OVER");
	}
}
