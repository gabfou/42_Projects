using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;
using UnityEngine.SceneManagement;
using UnityEngine.Audio;

public class ToxiController : MonoBehaviour {

	// Use this for initialization
	public	float				toxicity = 50f;
	public	float				fatigue = 50f;
	public	Text				sleeptxt;
	public	bool				GameState;
	public render_with_shader	rws;
	Vector3 				lastCheckpoint;
	float					lastCheckpointToxicity = 50f;
	float					lastCheckpointFatigue = 50f;
	public GameObject		cafe;
	public	bool			rienacarrer = false;

	public AudioMixer		mixer;

	public Slider			toxiSlider;
	public Slider			fatigueSlider;

	// private static System.Random rnd = new System.Random();
	private	RectTransform	sleepRT;
	private	Rigidbody		rb;
	private Animator		anim;

	List<GameObject> cafeSinceLastCheckpoint = new List<GameObject>();

	void Start () {
		sleeptxt.enabled = false;
		GameState = true;
		rb = GetComponent<Rigidbody>();
		lastCheckpoint = transform.position;
		sleepRT = sleeptxt.GetComponent<RectTransform>();
		anim = GetComponent<Animator>();
		sleepRT.localPosition = new Vector3( 0, 450, 0);
		if (rienacarrer == false)
		{
			InvokeRepeating("ToxicityUpdate", 2f, 0.2f);
			InvokeRepeating("fatigueUpdate", 2f, 0.2f);
		}
	}

	void Update()
	{
		if (Input.GetKeyDown(KeyCode.R))
			SceneManager.LoadScene(SceneManager.GetActiveScene().name);
		mixer.SetFloat("coffee", toxicity / 1.5f - 60);
	}
	
	void FixedUpdate()
	{
		if (!GameState) {
			sleeptxt.enabled = true;
			sleepRT.localPosition = Vector3.MoveTowards(sleepRT.localPosition, new Vector3(0, -450f, 0), 1f);
		}
		anim.SetFloat("excitement", -(fatigue - 100));
	}

	void sleep() {
		sleepRT.position = new Vector3(0, 450, 0);
		sleeptxt.enabled = true;
		sleepRT.position = Vector3.MoveTowards(sleepRT.position, new Vector3(0, -450f, 0), 10);
		while (sleepRT.position.y > 0) {
			sleepRT.position = new Vector3( 0, sleepRT.position.y - 0.5f, 0) * Time.deltaTime * 60f;
		}
	}

	void ToxicityUpdate() {
		if (GameState) {
			toxicity -= 0.20f;
			if (toxicity < 0) {
				toxicity = 0;
			}
			float tmp = toxicity / 50 - 1;
			tmp = (tmp < 0) ? 0 : tmp;
			rws.intensity = tmp;
			tmp = toxicity / 20 - 4;
			tmp = (tmp < 0) ? 0 : tmp;
			tmp = (tmp < 0.1f) ? tmp : Mathf.Pow(2, tmp);
			rws.Intensitytache = tmp;
			
			toxiSlider.value = toxicity;
		}
    }

	IEnumerator ResetLevel()
	{
		yield return new WaitForSeconds(8);
		SceneManager.LoadScene(SceneManager.GetActiveScene().name);
	}
	
	void fatigueUpdate() {
		if (GameState) {
			fatigue += 0.15f;
			if (fatigue >= 100 && GameState) {
				GameState = false;
				GetComponent< RagdollController >().activeRagdoll = true;
				StartCoroutine(ResetLevel());
			}
			fatigueSlider.value = fatigue;
		}
    }

	void addFatigue(float i) {
		fatigue += i;
		if (fatigue > 100f) {
			fatigue = 100f;
		}
	}

	void addToxicity(float i) {
		toxicity += i;
		if (toxicity > 100f) {
			toxicity = 100f;
		}
	}

	void RespawnCafe()
	{
		foreach(GameObject obj in cafeSinceLastCheckpoint)
			obj.SetActive(true);
		cafeSinceLastCheckpoint.Clear();
	}

	void OnTriggerEnter(Collider other)
	{
		Debug.Log(other.tag);
		if (other.tag == "cafe") {
			addToxicity(10f);
			addFatigue(-10f);
			cafeSinceLastCheckpoint.Add(other.gameObject);
			other.gameObject.SetActive(false);
		}
		if (other.tag == "Checkpoint" && lastCheckpoint.Equals(other.transform.position) == false)
		{
			cafeSinceLastCheckpoint.Clear();
			lastCheckpointFatigue = fatigue;
			lastCheckpointToxicity = toxicity;
			lastCheckpoint = other.transform.position;
		}
		if (other.tag == "Death")
		{
			RespawnCafe();
			rb.velocity = Vector3.zero;
			fatigue = lastCheckpointFatigue;
			toxicity = lastCheckpointToxicity;
			transform.position = lastCheckpoint;
			if (rienacarrer == true)
			{
				fatigue = 0;
				toxicity = 100;
			}
		}
	}

	void OnCollisionEnter(Collision other)
	{
		if (other.gameObject.tag == "Checkpoint" && lastCheckpoint.Equals(other.transform.position) == false)
		{
			cafeSinceLastCheckpoint.Clear();
			lastCheckpointFatigue = fatigue;
			lastCheckpointToxicity = toxicity;
			lastCheckpoint = other.transform.position;
		}
		if (other.gameObject.tag == "Death")
		{
			RespawnCafe();
			rb.velocity = Vector3.zero;			
			transform.position = lastCheckpoint;
			fatigue = lastCheckpointFatigue;
			toxicity = lastCheckpointToxicity;
			if (rienacarrer == true)
			{
				fatigue = 0;
				toxicity = 100;
			}
		}
	}

	/*static void randomize (List<string> list) {
		int n = list.Count;
        while (n > 1) {
            int k = (rnd.Next(0, n) % n);
            n--;
            string value = list[k];
            list[k] = list[n];
            list[n] = value;
        }
		int i = 0;
		while (i < list.Count) {
			Debug.Log(i + ": " + list[i]);
			i++;
		}
	}*/
}
