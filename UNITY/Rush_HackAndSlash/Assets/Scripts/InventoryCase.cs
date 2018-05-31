using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class InventoryCase : MonoBehaviour {

	public	Weapon	arme = null;
	private		string		currentToolTipText = "";
	private		GUIStyle	guiStyleFore;
	private		GUIStyle	guiStyleBack;
	// Use this for initialization
	void Start () {
		guiStyleFore = new GUIStyle();
		guiStyleFore.normal.textColor = Color.white;
		guiStyleFore.alignment = TextAnchor.UpperCenter ;
		guiStyleFore.wordWrap = true;
		guiStyleBack = new GUIStyle();
		guiStyleBack.normal.textColor = Color.black;
		guiStyleBack.alignment = TextAnchor.UpperCenter ;
		guiStyleBack.wordWrap = true;
	}
	
	// Update is called once per frame
	void Update () {
		if (arme != null) {
			GetComponent<Image> ().sprite = arme.sprite;
		}
	}
	public void	entrededans ()
	{
		if (arme)
			currentToolTipText = arme.Type + " " + arme.Rarity + " " + arme.level + "\n" + "STR : " + arme.STR + " AGI : " + arme.AGI + " CON : " + arme.CON + " INT : " + arme.INT + " AMR : " + arme.AMR + " SPD : " + arme.SPD;
	}

	public void sortdededans ()
	{
		currentToolTipText = "";
	}

	void OnGUI()
	{
		if (currentToolTipText != "")
		{
			var x = Event.current.mousePosition.x;
			var y = Event.current.mousePosition.y;
			GUI.Label (new Rect (x-149,y+21,300,60), currentToolTipText, guiStyleBack);
			GUI.Label (new Rect (x-150,y+20,300,60), currentToolTipText, guiStyleFore);
		}
	}
}
