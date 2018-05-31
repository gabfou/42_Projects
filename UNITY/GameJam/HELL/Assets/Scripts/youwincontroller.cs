using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class youwincontroller : MonoBehaviour {

	// Use this for initialization
	public GameObject	youwin;
	public GameObject	text;
	public GameObject	credit;
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.Space))
			{
				youwin.SetActive(false);
				text.SetActive(false);
			}
	}
}
