using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;

public class RemainingDistance : MonoBehaviour {

	public	List<Vector3>	CP;
	public	Transform		Player;
	public	Text			txtDist;

	private	int				lenght;
	private int				i;
	private	List<float>		distList;
	private float			dist;
	private float			remain;
	// Use this for initialization
	void Start () {
		lenght = CP.Count;
		distList  = new List<float>(new float[CP.Count]);
		 
		setDist();
	}
	
	// Update is called once per frame
	void Update () {
		i = 0;
		while (i < lenght) {
			dist = Vector3.Distance(CP[i], Player.position);
			// Debug.Log("dist = " + dist);
			if (dist < distList[i]) {
				setRemain(dist, i);
				break ;
			}
			i++;
		}
		// remain = CP.Where(p => Vector3.Distance(p, CP[0]) < Vector3.Distance(p, Player.position)).Min(p => Vector3.Distance(p, Player.position));
		txtDist.GetComponent<Text>().text = remain.ToString();

	}

	void setDist() {
		i = 0;
		while (i < lenght - 1) {
			distList[i] = Vector3.Distance(CP[i], CP[i + 1]);
			Debug.Log(i + ": " + distList[i]);
			i++;
		}
		distList[i] = Vector3.Distance(CP[i], Player.position);
		Debug.Log(i + ": " + distList[i]);
	}

	void setRemain(float dist, int i) {
		float tmp = 0;
		while (i >= 0) {
			tmp += distList[i];
			i--;
		}
		// Debug.Log(i.ToString() + ": " + remain);		
		remain = tmp + dist;
	}
}
