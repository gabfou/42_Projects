using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class tetriscase : MonoBehaviour {

	// Use this for initialization
	public tetriscase right = null;
	public tetriscase left = null;
	[HideInInspector] public bool astobedestroy = false;

	void Start () {
		Camera.main.GetComponent<controllertetris>().checkpoofneeded.AddListener(checkpoof);
		Camera.main.GetComponent<controllertetris>().checkdestroyneeded.AddListener(checkdestroy);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	
	public void initpoof()
	{
		right = null;
		left = null;
	}

	public void checkdestroy()
	{
		Debug.Log("dsf");
		if (astobedestroy == true)
			GameObject.Destroy(gameObject);
	}

	public void checkpoof()
	{
		Debug.Log("dsf3");
		RaycastHit2D[] list2;
		list2 = Physics2D.RaycastAll(new Vector2(-10, transform.position.y), new Vector2(1, 0), 100, 1 << LayerMask.NameToLayer("tetriscube"));
			// Debug.DrawRay(new Vector2(-10, transform.position.y), new Vector2(1, 0) * 100, Color.red, 1);
		Debug.Log(list2.Length);
		if  (list2.Length > 11)
		{
			foreach (var l  in list2)
				Debug.Log(l.collider);
			Debug.Log("list2.Length");
			this.astobedestroy = true;
		}
	}

}
