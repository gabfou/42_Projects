using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class apparitiongrossisment : MonoBehaviour {

	public Text t;

	// Use this for initialization
	void Start () {
		StartCoroutine(FadeTextToFullAlpha(5, t));
	}
	
	public IEnumerator FadeTextToFullAlpha(float t, Text i)
	{
		i.color = new Color(i.color.r, i.color.g, i.color.b, 0);
		while (i.color.a < 1.0f)
		{
			i.color = new Color(i.color.r, i.color.g, i.color.b, i.color.a + 0.01f);
			yield return new WaitForSeconds(t);
		}
	}

	// Update is called once per frame
	void Update () {
		
	}
}
