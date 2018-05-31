using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;

public class controllertetris : MonoBehaviour {

	// Use this for initialization
	public GameObject	GameManager;
	public quadrapode[] list;
	public GameObject[] listimage;

	quadrapode current = null;
	GameObject next = null;
	int 		nextrange;
	float		nextrot;
	public Vector3 origin;
	public Vector3	nextorigin;
	[HideInInspector] public UnityEvent checkpoofneeded;
	[HideInInspector] public UnityEvent checkdestroyneeded;
	private	Game_Manager	GM;

	int tmp36 = 0;
	int tmp32 = 0;

// 
	void Awake()
	{
		if (checkpoofneeded == null)
			checkpoofneeded = new UnityEvent();
		if (checkdestroyneeded == null)
			checkdestroyneeded = new UnityEvent();
	}
	void Start () {
		GM = GameManager.GetComponent<Game_Manager>();
		newnext();
	}

	void		newnext()
	{
		if (next != null)
			GameObject.Destroy(next.gameObject);
		nextrange = Random.Range(0, list.Length);
		nextrot = Random.Range(0, 4);;
		next = GameObject.Instantiate(listimage[nextrange], nextorigin, Quaternion.identity);
		next.transform.Rotate(Vector3.forward, nextrot * 90);
	}

	IEnumerator spawnnew()
	{
		if (current && current.transform.position.y > origin.y - 2)
			GM.GameOver();
		current = null;
		checkpoofneeded.Invoke();
		yield return new WaitForSeconds(0.01f);
		checkdestroyneeded.Invoke();
		yield return new WaitForSeconds(0.49f);
		if (current == null)
		{
			current = GameObject.Instantiate(list[nextrange], origin, Quaternion.identity);
			current.GetComponent<Rigidbody2D>().velocity = new Vector2(0, -0.001f);
			current.transform.Rotate(Vector3.forward, nextrot * 90);
			newnext();
		}
		tmp36 = 0;
	}

	IEnumerator delay()
	{
		tmp32 = 1;
		yield return new WaitForSeconds(0.05f);
		tmp32 = 0;
	}

	// Update is called once per frame
	void FixedUpdate () {
				print("hell?" +LevelManagerScript.hell);

		if (GM.GameState) {
			if (tmp36 == 0 && (current == null || current.ismoving == 0))
			{
				tmp36 = 1;
				StartCoroutine(spawnnew());
			}
			if (current == null || tmp32 == 1)
				return ;
			
			float m  = Input.GetAxisRaw("Horizontal");
			if (current.raycasthori(1) && m > 0)
			{
				current.rigid.MovePosition(current.transform.position + new Vector3(1, 0, 0));
				StartCoroutine(delay());
			}

			if (current.raycasthori(-1) && m < 0)
			{
				current.rigid.MovePosition(current.transform.position - new Vector3(1, 0, 0));
				StartCoroutine(delay());
			}
			if (Input.GetKeyDown("space"))
			{
				current.transform.Rotate(Vector3.forward, 90);
			}
		}
	}
}
