using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class Rotaty : MonoBehaviour {

	public	GameObject			Player;
	PlayerAPI					api;

	private	ToxiController		P;
	private	Rigidbody			rb;

	// Use this for initialization
	void Start () {
		P = Player.GetComponent<ToxiController>();
		api = GetComponent< PlayerAPI >();
		rb = api.rigidbody;
		InvokeRepeating("CheckRotate", 2f, 1f);
	}
	
	void CheckRotate() {
		if (Random.Range(0, 100) < P.toxicity) {
			rb.DORotate(new Vector3(0, Player.transform.rotation.y + Random.Range(-100, 100), 0), 100);
		}
	}
}
