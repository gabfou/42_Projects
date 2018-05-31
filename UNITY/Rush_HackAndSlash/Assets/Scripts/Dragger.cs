using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class Dragger : MonoBehaviour {

	public  GameObject  Prefab;
	public  GameObject  cam;

	private Vector3     offset;
	private Vector3     startPosition;
	private Image   image;
	public	Canvas	myCanvas;

	void    Start() {
//		image = GetComponent<Image> ();
		startPosition = transform.position;
	}

	void    Update() {
	}

	public  void    BeginDrag(GameObject lol) {
		Prefab = lol;
		offset = lol.transform.position - cam.transform.position;
//		GameObject str = CastRay();
//		Debug.Log ("begin : " + str.name);
//		if (str != null && str.tag == "case") {
//			offset = gameObject.transform.position - Camera.main.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, Input.mousePosition.z));
//		}
	}


	public  void    OnDrag() {
		Vector2 pos;
		RectTransformUtility.ScreenPointToLocalPointInRectangle(myCanvas.transform as RectTransform, Input.mousePosition, myCanvas.worldCamera, out pos);
		Prefab.transform.position = myCanvas.transform.TransformPoint (pos) +  Camera.main.transform.forward * -0.1f;
	}

	public  void    EndDrag(GameObject qwe) {
		Weapon tmp = Prefab.GetComponent<InventoryCase> ().arme;
		if (qwe.name == "LeftHand")
			GameState.mayaController.ChangeEquipement (false, Prefab.GetComponent<InventoryCase> ().arme);
		else if (qwe.name == "RightHand")
			GameState.mayaController.ChangeEquipement (true, Prefab.GetComponent<InventoryCase> ().arme);
		else if (Prefab.name == "LeftHand")
			GameState.mayaController.ChangeEquipement (false, qwe.GetComponent<InventoryCase> ().arme);
		else if (Prefab.name == "RightHand")
			GameState.mayaController.ChangeEquipement (true	, qwe.GetComponent<InventoryCase> ().arme);
		Prefab.GetComponent<InventoryCase> ().arme = qwe.GetComponent<InventoryCase> ().arme;
		qwe.GetComponent<InventoryCase> ().arme = tmp;
		Debug.Log ("WESH " + qwe.name + " PREFAB " + Prefab.name);
		if (qwe.name == Prefab.name) {
			Debug.Log ("DROP WEAPON");
			return ;
		}
		Debug.Log ("ENDDRAG: " + qwe.name);
			/*int i = gamemanager.GetComponent<gameManager> ().playerEnergy;
			if (i >= energie) {
				Instantiate (Prefab, new Vector3 (str.transform.position.x, str.transform.position.y, 0.0F), Quaternion.identity);
				gamemanager.GetComponent<gameManager> ().playerEnergy -= energie;
				str.tag = "used";
			}*/
			Sprite tmp2 = Prefab.GetComponentInChildren<Image> ().sprite;
			Prefab.GetComponentInChildren<Image> ().sprite = qwe.GetComponentInChildren<Image> ().sprite; 
			qwe.GetComponentInChildren<Image> ().sprite = tmp2;
//			Prefab.transform.position = qwe.transform.position;
//			qwe.transform.position = offset;
		Prefab.transform.position = offset + cam.transform.position;
	}

	public	void	DropOut() {
			Debug.Log ("Drop Weapon");
	}

	public	void	LeftHandequipe(GameObject qwe) {
//		GameState.mayaController.ChangeEquipement (false, qwe.GetComponent<InventoryCase> ().arme);
		EndDrag (qwe);
	}
	public	void	RightHandequipe(GameObject qwe) {
//		GameState.mayaController.ChangeEquipement (true, qwe.GetComponent<InventoryCase> ().arme);
		EndDrag (qwe);
	}

	public GameObject CastRay() {
		Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
		RaycastHit hit;
		Physics.Raycast (ray, out hit, Mathf.Infinity);
			return (hit.collider.gameObject);
		return (null);
	}

}
