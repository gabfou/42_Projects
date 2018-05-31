using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class text_scroll : MonoBehaviour {

	public	Text			txt;
	public	string[]		list;
	private	string			str;
	private	int				i;
	// private	int				j;
	private	bool			writing;
	// Use this for initialization
	void Start () {
		// list = new List<string>();

        // list[0] = "first line";
        // list[1] = "second";
    	// list[2] = "bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla ";
    	// list[3] = "Voila !";

		i = 0;
		// j = 0;
		writing = false;
	}
	
	// Update is called once per frame
	void Update () {
		// txt.GetComponent<Text>().text = "";
		if (!writing){
			if (i == list.Length) {
				Stop();
			}
			StartCoroutine(Write());
			writing = true;
		}
	}

	IEnumerator Write() {
		if (i < list.Length) {
			txt.GetComponent<Text>().text = list[i];
			Debug.Log(list[i]);
			i++;
		}
		yield return new WaitForSeconds(3);
		writing = false;
	}

	void	Stop() {
		Debug.Log("stop");
	}
}
