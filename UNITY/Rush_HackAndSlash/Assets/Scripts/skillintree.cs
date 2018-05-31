using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class skillintree : MonoBehaviour {
	
	public Maya_Controlleur maya;
	public skillintree[] requirement;
	public spell spell;
	public Text	level;
	[HideInInspector] public int maxvalue;
	public int basevalue = 0;
	public int levelrequirement = 0;
	[HideInInspector] public bool taken = false;
	bool cantake = false;

	private		string				currentToolTipText = "";
	private		GUIStyle			guiStyleFore;
	private		GUIStyle			guiStyleBack;

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

		maxvalue = basevalue + 5;

	}
	
	// Update is called once per frame
	void Update () {
		if (!cantake && checkcantake ()) {
			cantake = true;

			GetComponent<Image>().color = Color.white;
		}
	}

	public bool checkcantake()
	{
		int i = -1;

		if (maya.stat.level < levelrequirement)
			return false;
		while (++i < requirement.Length) {
			if (requirement [i].taken == false)
				return (false);
		}
		return true;
	}

	public void trytake()
	{
		if (cantake && maya.skillpoint > 0) {
			GetComponent<Image> ().color = Color.green;
			if (int.Parse (level.text) > 4)
				return;
			if (int.Parse (level.text) == 4)
				taken = true;
			level.text = (int.Parse (level.text) + 1).ToString();
			if (int.Parse (level.text)  > 1)
				maya.spellevolve (spell.name, int.Parse (level.text) + basevalue);
			else
				maya.addspell (spell);
		}
	}

	public void	pointerEnter ()
	{
		currentToolTipText = spell.description;//
	}

	public void	pointerExit ()
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
