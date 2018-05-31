using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jumpy : MonoBehaviour {

	public	ToxiController	Player;
	public	float				jumpForce;
	PlayerAPI					api;


	// // Use this for initialization
	void Start () {
		api = GetComponent< PlayerAPI >();
		InvokeRepeating("CheckJump", 5f, 3f);
	}
	
	void CheckJump() {
		if (Random.Range(0, 100) < Player.toxicity) {
			api.Jump(jumpForce);
		}
	}
}
