using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class playerloading2 : MonoBehaviour {

	public Text	loadingtext;
	public Slider loadingslider;
	[HideInInspector] public float loading;
	public float speed;
	public float jumpspeed;
	public float hight;
	public float low;
	int asjumped = 0;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame

	void Update () {
				print("hell?" +LevelManagerScript.hell);

		if (asjumped == 3)
			transform.position += new Vector3(speed * Time.deltaTime, 0, 0);
		else if (asjumped == 1)
		{
			transform.position += new Vector3(speed * Time.deltaTime / 2, jumpspeed* Time.deltaTime, 0);
			if (transform.position.y > hight)
				asjumped = 2;
		}
		else if (asjumped == 2)
		{
			transform.position += new Vector3(speed * Time.deltaTime / 2, -jumpspeed * Time.deltaTime, 0);
			if (transform.position.y < low)
				asjumped = 3;
		}

		else
		{
			if (Input.GetKey("space"))
				asjumped = 1;
		}
		if (loading + speed * 2 * Time.deltaTime < (transform.position.x + 7) * 100 / 14)
			loading += speed * 2 *  Time.deltaTime;
		loadingtext.text = Mathf.Round(loading).ToString() + "%";
		loadingslider.value = loading / 100;
		if (loading >= 100) {
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
		AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("Tetris");
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
