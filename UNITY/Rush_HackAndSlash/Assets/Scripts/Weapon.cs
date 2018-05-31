using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class Weapon : MonoBehaviour {

	public	int				STR = 1;
	public	int				AGI = 1;
	public	int				CON = 1;
	public	int				INT = 1;
	public	int				AMR = 1;
	public	float			SPD = 1;
	public	string			Type;
	public	float			level;
	public	string			Rarity;
	private	float			i;
	private	int				r;
	private		string		currentToolTipText = "";
	private		GUIStyle	guiStyleFore;
	private		GUIStyle	guiStyleBack;
	public	static	int		aydi = 0;
	public		int 		idweapon;
	public		Sprite 		sprite;

	// Use this for initialization
	void Start () {
		idweapon = ++aydi;
		guiStyleFore = new GUIStyle();
		guiStyleFore.normal.textColor = Color.white;
		guiStyleFore.alignment = TextAnchor.UpperCenter ;
		guiStyleFore.wordWrap = true;
		guiStyleBack = new GUIStyle();
		guiStyleBack.normal.textColor = Color.black;
		guiStyleBack.alignment = TextAnchor.UpperCenter ;
		guiStyleBack.wordWrap = true;

		r = Random.Range(1, 12);

		if (r < 6) { //////                          Rarete
			Rarity = "Commune";
			i = Random.Range (0.5f, 1f);
		} else if (r < 9) {
			Rarity = "Rare";
			i = Random.Range (1.1f, 1.5f);
		} else if (r < 11) {
			Rarity = "Epic";
			i = Random.Range (1.6f, 2f);
		} else {	
			Rarity = "Legendaire";
			i = Random.Range (2.1f, 3f);
		}
		level = GameState.mayaController.stat.level;
		float mult = (level / 10) + 1f;///            Level
		if (Type == "Dagger") {
			STR += (int)(2 * mult * i);
			AGI += (int)(10 * mult * i);
			SPD += (int)(1.5f * mult * i);
		} else if (Type == "Sword") {
			STR += (int)(10 * mult * i);
			AGI += (int)(2 * mult * i);
		} else if (Type == "Staff") {
			STR += (int)(1 * mult * i);
			INT += (int)(10 * mult * i);
			SPD += (int)(0.75f * mult * i);
		} else if (Type == "Shield") {
			AMR += (int)(10 * mult * i);
			CON += (int)(5 * mult * i);
		}
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void	OnMouseEnter ()
	{
		currentToolTipText = Type + " " + Rarity + " " + level + "\n" + "STR : " + STR + " AGI : " + AGI + " CON : " + CON + " INT : " + INT + " AMR : " + AMR + " SPD : " + SPD;
	}

	void OnMouseExit ()
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
