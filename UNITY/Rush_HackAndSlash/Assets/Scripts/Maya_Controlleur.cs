using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using UnityEngine.EventSystems;

public class Maya_Controlleur : MonoBehaviour {

	NavMeshAgent			navmeshAgent;
//	Rigidbody				rbody;
	Animator				animator;
	RaycastHit				hit;
	public		bool 		dead = false;
	perso		cible;
	bool mouse = false;
	float timeattack = 0;
	public		perso				stat;
	public		GameObject			mCompetances;
	public		GameObject			mInventory;
	public		AudioSource			BGmusic;
	private		bool 				mCopen;
	private		bool 				mIopen;
	public		Image 				HealthBar;
	public		Image 				XPBar;
	public		Image 				EnemyBar;
	public		Text 				HPtxt;
	public		Text 				XPtxt;
	public		Text				LVLtxt;
	public		Text				EnemyName;
	public		Text 				GameOver;
	public		Text				mname;
	public		Text 				mSTR;
	public		Text 				mAGI;
	public		Text 				mCON;
	public		Text 				mINT;
	public		Text 				mdamage;
	public		Text 				marmor;
	public		Text 				mexp;
	public		Text 				mcredit;
	public		Text 				mcptpts;
	public		Text 				mmana;
	private		Text				t;
	private		bool				b;
	private		bool				end = false;
	public		int 				cptpts;
	[HideInInspector] public int	skillpoint = 0;
	public		spell 				skill1;
//	public		spell 				skill2;
	public		GameObject			skilltree;
	public bool canmove = true;
	public		Weapon				equipedR;
	public		Weapon				equipedL;
	public		List<spell> 		listsp;
	public		List<Weapon> 		Bagpack;
	public		List<GameObject> 	inventory;
	public		Weapon_pool			weaponpool;
	public		Dropdown 			dropskill;
	bool		place;
	public		spell[]				spellbar = new spell[4];
	[HideInInspector] public float	regen = 0;

	[HideInInspector]
	public Vector3 			position;
	spell skilltmp;

	void	Awake() {
		GameState.mayaController = this;
	}

	void	Start() {
		BGmusic.Play ();
		navmeshAgent = GetComponent< NavMeshAgent > ();
//		rbody = GetComponent< Rigidbody > ();
		animator = GetComponent< Animator > ();
		stat = GetComponent< perso> ();
		t = GameOver.GetComponent<Text> ();
		mname.text = name;
		skilltree.SetActive (false);
		JustAddStuff (equipedR);
		JustAddStuff (equipedL);
		dropskillupdate ();
		spellbar [0] = null;
		spellbar [1] = null;
		spellbar [2] = null;
		spellbar [3] = null;
	}

	void	Update () {
		GameState.mayaPosition = transform.position;
			CheckDeath ();
		stat.HP += regen * Time.deltaTime;
		if (stat.INT * 5 > stat.mana)
			stat.mana += 2 * Time.deltaTime;
		if (!dead) {
			if (Input.GetKeyDown ("c")) {
				if (!mCopen) {
					mCopen = true;
					canmove = false;
					mCompetances.SetActive (true);

				} else {
					mCopen = false;
					canmove = true;
					mCompetances.SetActive (false);
				}
			}
			else if (Input.GetKeyDown ("i")) {
				if (!mIopen) {
					mIopen = true;
					mInventory.SetActive (true);

				} else {
					mIopen = false;
					mInventory.SetActive (false);
				}
			}

			if (Input.GetKeyDown ("n")) {
				if (skilltree.activeSelf == false) {
					canmove = false;
					skilltree.SetActive (true);

				} else {
					canmove = true;
					skilltree.SetActive (false);
				}
			}
			if (canmove)
				Move ();
			UpdateGUI ();
		} else if (dead == true && end == false) {
			end = true;
			StartCoroutine (endgame());
		}
	}

	public void	ChangeEquipement(bool hand, Weapon arme) {
		Debug.Log ("YO o/");
		if (hand) {
			AddStuff(equipedR, arme);
			equipedR = arme;
		} else {
			AddStuff(equipedL, arme);
			equipedL = arme;
		}
	}

	void	AddStuff(Weapon equiped, Weapon arme) {
		if (equiped != null) {
			stat.STR -= equiped.STR;
			stat.AGI -= equiped.AGI;
			stat.CON -= equiped.CON;
			stat.Armor -= equiped.AMR;
			stat.INT -= equiped.INT;
		}
		if (arme != null) {
			stat.STR += arme.STR;
			stat.AGI += arme.AGI;
			stat.CON += arme.CON;
			stat.Armor += arme.AMR;
			stat.INT += arme.INT;
		}
	}

	void	JustAddStuff(Weapon arme) {
		if (arme != null) {
			stat.STR += arme.STR;
			stat.AGI += arme.AGI;
			stat.CON += arme.CON;
			stat.Armor += arme.AMR;
			stat.INT += arme.INT;
		}
	}

	void	Move() {
		
		Ray ray = Camera.main.ScreenPointToRay (Input.mousePosition);
		RaycastHit hit2;
		if (Physics.Raycast (ray, out hit2, Mathf.Infinity))
		{
			if (hit2.collider.tag == "mechant")
				hit2.collider.gameObject.GetComponent<perso> ().brillance ();
			if (Input.GetMouseButtonDown (0) || Input.GetMouseButtonDown (1) || Input.GetKeyDown("q") || Input.GetKeyDown("w"))
			 {
				if (hit2.collider.tag == "mechant") {
					cible = hit2.collider.gameObject.GetComponent<perso>();
				} 
				else if (hit2.collider.tag == "equipement") {
					place = false;
					foreach (GameObject slot in inventory) {
						if (slot.GetComponent<InventoryCase> ().arme == null)
							place = true;
					}
					if (place) {
						Weapon tmp = Instantiate (hit2.collider.gameObject.GetComponent<Weapon> (), new Vector3 (1000f, 1000f, 1000f), Quaternion.identity, transform);
						Destroy (hit2.collider.gameObject);
//						Bagpack.Add (tmp);

						foreach (GameObject slot in inventory) {
							Debug.Log (slot.GetComponent<InventoryCase> ().arme);
							if (slot.GetComponent<InventoryCase> ().arme == null) {
								Debug.Log (slot.GetComponent<InventoryCase> ().arme);
								slot.GetComponent<InventoryCase> ().arme = (Weapon)tmp;
								break;
							}
						}
						foreach (Weapon equi in Bagpack)
							Debug.Log (equi);
					}
				}
				mouse = true;
				hit = hit2;
				if (Input.GetMouseButtonDown (0) && spellbar [0] != null)
					skilltmp = spellbar [0];
				if (Input.GetMouseButtonDown (1) && spellbar [1] != null)
					skilltmp = spellbar [1];
				if ( Input.GetKeyDown("q") && spellbar [2] != null)
					skilltmp = spellbar [2];
				if (Input.GetKeyDown("w") && spellbar [3] != null)
					skilltmp = spellbar [3];
			}
		}
		if (Input.GetMouseButtonUp (0) || Input.GetMouseButtonUp (1) || Input.GetKeyUp("q") || Input.GetKeyUp("w")) {
			mouse = false;
		}

		Vector3 wantedPosition;
		if (cible == null)
			wantedPosition = new Vector3 (hit.point.x, hit.point.y, hit.point.z);
		else
			wantedPosition = cible.transform.position;

		position = transform.position;

//		List<string> action = skill1.attack (stat, cible, navmeshAgent.remainingDistance);
//		if (action.Contains("stopmoving"))
//			wantedPosition = (position);
//		//		Debug.Log (wantedPosition);//
//		if (action.Contains("finish") && mouse == false)
//			cible = null;
//		if (Input.GetMouseButtonDown (1)) {
//			List<string> action2 = skill2.attack (stat, cible, navmeshAgent.remainingDistance);
//			if (action2.Contains("stopmoving"))
//				wantedPosition = (position);
//			//		Debug.Log (wantedPosition);//
////			if (action2.Contains("finish") && mouse == false)
////				cible = null;
		if (skilltmp == null)
			skilltmp = skill1;
//		tmp = spellbar [0];
		List<string> action = skilltmp.attack (stat, cible, navmeshAgent.remainingDistance);
		if (action.Contains("stopmoving"))
			wantedPosition = (position);
		if (action.Contains ("finish") && mouse == false) {
			cible = null;
			skilltmp = null;
		}

		navmeshAgent.SetDestination (wantedPosition);
	}

	void OnDrawGizmos()
	{
		Gizmos.DrawSphere(hit.point, 1f);
		Gizmos.color = Color.blue;
	}

	private	void	CheckDeath() {
		if (stat.HP <= 0 && dead == false) {
			animator.SetTrigger ("dead");
			dead = true;
		}
	}

	void	UpdateGUI() {
		if (stat.xp >= stat.nextxp)
			levelup ();
		float curhp = stat.HP / stat.MaxHP;
		float curxp = stat.xp / stat.nextxp;
		HealthBar.fillAmount = curhp;
		XPBar.fillAmount = curxp;
		HPtxt.text = "HP - " + Mathf.FloorToInt(stat.HP).ToString() + " / " + stat.MaxHP.ToString() + " max";
		XPtxt.text = "XP - " + stat.xp.ToString() + " / " + stat.nextxp.ToString() + " to nxt lvl";
		LVLtxt.text = "LVL " + stat.level;
		if (cible != null) {
			EnemyBar.fillAmount = cible.HP / cible.MaxHP;
			EnemyName.text = (cible.name).Split('(')[0] + " - LVL : " + cible.GetComponent<zombie_controller>().level;
		} else {
			EnemyBar.fillAmount = 0;
			EnemyName.text = "";
		}

		mSTR.text = "STR : " + stat.STR;
		mAGI.text = "AGI : " + stat.AGI;
		mCON.text = "CON : " + stat.CON;
		mINT.text = "INT : " + stat.INT;
		mdamage.text = "damage = " + stat.minDamage + " / " + stat.maxDamage;
		marmor.text = "armor = " + stat.Armor;
		mexp.text = "exp = " + stat.xp.ToString() + " / " + stat.nextxp.ToString();
		mcredit.text = "credit = " + stat.money;
		mmana.text = "mana = " + Mathf.RoundToInt(stat.mana);
		mcptpts.text = "(+"+ cptpts.ToString() +")";
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

	public IEnumerator FadeTextToZeroAlpha(float t, Text i)
	{
		i.color = new Color(i.color.r, i.color.g, i.color.b, 1);
		while (i.color.a > 0.0f)
		{
			i.color = new Color(i.color.r, i.color.g, i.color.b, i.color.a - 0.01f);
			yield return new WaitForSeconds(t);
		}
	}

	IEnumerator re()
	{
		yield return new WaitForSeconds(3);
		b = false;
		StartCoroutine (FadeTextToZeroAlpha(0.001f, t));
	}

	public void sptext(string s)
	{
		t.text = s;
		b = true;
		StartCoroutine (FadeTextToFullAlpha (0.001f, t));
		StartCoroutine (re ());
	}

	IEnumerator endgame () {
		yield return new WaitForSeconds (5f);
		sptext("GAME OVER");
		yield return new WaitForSeconds (5f);
		SceneManager.LoadScene (SceneManager.GetActiveScene ().name);
	}

	public	void	UPSTAT(string str) {
		if (cptpts > 0) {
			if (str == "STR") {
				stat.STR += 1;
				cptpts -= 1;
			} else if (str == "AGI") {
				stat.AGI += 1;
				cptpts -= 1;
			} else if (str == "CON") {
				stat.HP = (stat.HP == stat.MaxHP) ? stat.MaxHP : stat.HP + 5 ;
				stat.CON += 1;
				cptpts -= 1;
			} else if (str == "INT") {
				stat.INT += 1;
				stat.mana = stat.INT * 10;
				cptpts -= 1;
			}
		}
	}

	void	levelup() {
		stat.xp = 0;
		stat.nextxp *= 1.5f;
		stat.nextxp = Mathf.Floor (stat.nextxp);
		stat.level += 1;
		cptpts += 5;
		skillpoint++;
		stat.HP = stat.MaxHP;
		StartCoroutine (noticemesempai(LVLtxt));
	}

	IEnumerator	noticemesempai(Text lvl) {
		while (lvl.fontSize < 50) {
			lvl.fontSize += 1;
			yield return new WaitForSeconds(0.01f);
		}
		while (lvl.fontSize > 25) {
			lvl.fontSize -= 1;
			yield return new WaitForSeconds(0.01f);
		}	
	}

	void	OnTriggerEnter(Collider Col) {
		if (Col.CompareTag ("popohp")) {
			stat.HP += stat.MaxHP * 0.3f;
			Destroy (Col.gameObject);
		}
	}

	public void addspell(spell sp)
	{
		skillpoint--;
		listsp.Add (GameObject.Instantiate (sp, transform.position, Quaternion.identity, transform));
		dropskillupdate ();
	}

	public void dropskillupdate()
	{
		List<string> ls = new List<string>();

		dropskill.ClearOptions ();
		foreach (spell tmp in listsp)
			ls.Add (tmp.name);
		dropskill.AddOptions (ls);
	}

	public void setskill(int numeroinput, int numeroskill)
	{
		spellbar [numeroinput] = listsp [numeroskill];
		Debug.Log (spellbar [numeroinput].name);
	}

	public void spellevolve(string name, int level)
	{
		skillpoint--;
		foreach (spell tmp in listsp)
		{
			if (tmp.name == name)
				tmp.level = level;
		}
	}
}