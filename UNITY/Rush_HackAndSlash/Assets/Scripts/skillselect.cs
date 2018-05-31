using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class skillselect : MonoBehaviour {

	int lastnumero;
	public Maya_Controlleur maya;
	Text lasttext;
	Dropdown d;
	// Use this for initialization

	IEnumerator tolate()
	{
		yield return new WaitForSeconds (2);
		gameObject.SetActive (false);
	}

	void Awake()
	{
		StartCoroutine (tolate ());
		GetComponent<Dropdown>().onValueChanged.AddListener(value => Destroy(transform.Find("Dropdown List").gameObject));
	}

	void Start () {
		d = GetComponent<Dropdown> ();
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	public void select(int numero, Text text)
	{
		lastnumero = numero;
		lasttext = text;
	}

	public void setnewskill(int numeroskill)
	{
		maya.setskill(lastnumero, numeroskill);
		lasttext.text = d.options [numeroskill].text;
		gameObject.SetActive (false);
	}
}
