using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class playerloadingdevilcontroller : MonoBehaviour {

	public float xmin;
	public float xmax;
	public float ymin;
	public float ymax;
	public blblbl b;
	public Text	loadingtext;
	public Slider loadingslider;
	[HideInInspector] public float loading;


	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
				print("hell?" +LevelManagerScript.hell);

		float move =  Input.GetAxisRaw("Horizontal");
		float move2 =  Input.GetAxisRaw("Vertical");

		float newx = move * Time.deltaTime * 5 + transform.position.x;
		float newy = move2 * Time.deltaTime * 5 + transform.position.y;
		transform.position += new Vector3((newx > xmin && newx < xmax) ? move * Time.deltaTime * 5 : 0, (newy > ymin && newy < ymax) ? move2 * Time.deltaTime * 5 : 0, 0);
		if (move == 0 && move2 == 0)
			b.isactive = false;
		else
			b.isactive = true;
		loading += Time.deltaTime * 100 / 90;
		loadingtext.text = Mathf.Round(loading).ToString() + "%";
		loadingslider.value = loading / 100;
		if (loading >= 100)
		{
			StartCoroutine(NextScene());
		}
	}

	void OnTriggerEnter2D(Collider2D other)
	{
		Debug.Log("fdsf");
		if (other.tag == "ouch")
			loading -= 2;
	}
	IEnumerator NextScene() {
		AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("marito");
			while (!asyncLoad.isDone)
			{
				yield return null;
        	}
	}

	// void OnDrawGizmos()
	// {
	// 	Gizmos.color = Color.red;
	// 	Gizmos.DrawWireCube;
	// }
}
