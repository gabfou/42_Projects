using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Speedy : MonoBehaviour {

	public	ToxiController	Player;
	PlayerAPI	api;
	private	float				speedW;
	private	float				speedR;

	// Use this for initialization
	void Start () {
		api = GetComponent< PlayerAPI >();
		speedW = api.defaultPlayerWalkSpeed;
		speedR = api.defaultPlayerRunSpeed;
	}

	void Update() {
		float f = 100 - Player.fatigue;
		api.SetWalkSpeed(speedW * (f + .2f) / 25);
		api.SetRunSpeed((f + 0.2f) * speedR / 25);
	}
}
