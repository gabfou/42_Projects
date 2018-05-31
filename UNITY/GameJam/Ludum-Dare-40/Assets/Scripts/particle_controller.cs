using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class particle_controller : MonoBehaviour {
	public List<GameObject> listparticle;
	// public GameObject sparkshoesleft;
	// public GameObject sparkshoesright;
	// public GameObject sparkchest;
	// public GameObject cafeaura;
	// public GameObject sickclood;
		

	// Use this for initialization
	// public class particle_controller_niark
	// {
	// 	string name;
	// 	ParticleSystem pc;
	// 	bool isactive;

	// 	public particle_controller_niark(string name, ParticleSystem pc)
	// 	{
	// 		name = name;
	// 		pc = pc;
	// 		isactive = pc.enabled;
	// 	}
	// }

	// public List<particle_controller_niark> dictionaryparticule;

	// void Awake () {

	// 	dictionaryparticule = new List<particle_controller_niark>();
	// 	ParticleSystem[] tmp = GetComponentsInChildren<ParticleSystem>(true);
	// 	Debug.Log("test2");
	// 	foreach (ParticleSystem tmp2 in tmp)
	// 	{
	// 		Debug.Log("test");
	// 		dictionaryparticule.Add(new particle_controller_niark(tmp2.name, tmp2));
	// 	}
	// }

// 	void OnGUI() {
// Debug.Log("test4");
// 		foreach(KeyValuePair<string, GameObject> entry in dictionaryparticule) {
// 			Debug.Log("test3");
// 			if (GUI.Button(new Rect(10, 10, 150, 100), entry.Key))
//     	        print("You clicked the button!");
// 		}
// 	}
	
	// Update is called once per frame
	void Update () {
		
	}

}
