using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class regenintree : MonoBehaviour {

	public Maya_Controlleur maya;
	public skillintree[] requirement;
	public Text	level;
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
			level.text = (int.Parse (level.text) + 1).ToString();
			maya.skillpoint--;
			maya.regen += 1;
		}
	}

	public void	pointerEnter ()
	{
		currentToolTipText = "Regain HP faster (1HP per second per skilllevel)";//
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