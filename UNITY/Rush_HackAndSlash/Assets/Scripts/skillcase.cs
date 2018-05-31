using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.Events;

public class skillcase : MonoBehaviour, IPointerClickHandler{

	// Use this for initialization
	public skillselect d;
	public int numero;

	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}

	public void OnPointerClick(PointerEventData eventData)
	{
		if (eventData.button == PointerEventData.InputButton.Right){
			d.gameObject.SetActive (true);
			d.select (numero, GetComponentInChildren<Text>());
		}
	}
}
