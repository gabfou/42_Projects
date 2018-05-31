using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Game_Manager : MonoBehaviour {

	public	GameObject	Intro;
	public	Text		score;
	public	Text		txt;
	public	Image		gameover;
	public	Image		win;
	public	bool		lost;
	public	List<Talk>	list;
	public	List<Talk>	list2;

	[HideInInspector]
	public	bool		GameState;

	private	bool		outro;
	private	int			Score;
	private	int			i;
	private	int			j;

	[System.Serializable]
	public struct Talk {
		public	string	str;
		public	int		i;
	}
	// Use this for initialization
	void Start () {
		Debug.Log(SceneManager.GetActiveScene().name);
		i = 0;
		j = 0;
		lost = false;
		GameState = false;
		outro = false;
		txt.GetComponent<Text>().color = getColor(list[i].i);
		txt.GetComponent<Text>().text = list[i].str;
	}

	// Update is called once per frame
	void Update () {
		// print("hell?" +LevelManagerScript.hell);

		if (!lost && !GameState) {
		if (LevelManagerScript.passe2 && SceneManager.GetActiveScene().name != "Tetris")
			{
				GameState = true;
				Intro.SetActive(false);
				return ;
			}
			if (Input.GetKeyDown("space")) {
				if (i == list.Count -1) {
					GameState = true;
					Intro.SetActive(false);
					return ;
				}
				i++;
				txt.GetComponent<Text>().color = getColor(list[i].i);
				txt.GetComponent<Text>().text = list[i].str;
			}
		}
		if (lost && gameover.rectTransform.localScale.x < 5)
		{
			gameover.rectTransform.localScale += new Vector3(0.01f,0.01f,0) * Time.deltaTime * 60f;
			gameover.color += new Color(0,0,0, 0.005f) * Time.deltaTime * 60f;
		} else if (gameover.rectTransform.localScale.x >= 5 && !outro){
			if (SceneManager.GetActiveScene().name == "Tetris") 
			{
				outro = true;
				gameover.enabled = false;
				Intro.SetActive(true);
				i = 0;
				txt.GetComponent<Text>().color = getColor(list2[i].i);
				txt.GetComponent<Text>().text = list2[i].str;
				return ;
			}
			StartCoroutine(NextScene());
		}
		if (outro)
		{
			if (Input.GetKeyDown("space")) {
				if (i == list2.Count -1) {
					GameState = true;
					Intro.SetActive(false);
					StartCoroutine(NextScene());
				}
				i++;
				txt.GetComponent<Text>().color = getColor(list2[i].i);
				txt.GetComponent<Text>().text = list2[i].str;
			}
		}
		if (LevelManagerScript.hell == false && Score == 1540)
			StartCoroutine(NextScene());
	}

	public void ScoreUp (int points) {
		Score += points;
		score.GetComponent<Text>().text = "Score : " + Score.ToString();
	}

	public void GameOver () {
		lost = true;
		GameState = false;
		Debug.Log("GAME OVER");
	}

	Color	getColor(int col) {
		if (col == 1) {
			return new Color(1,1,1); 
		} else if (col == 2) {
			return new Color(1,0,0);
		}
		return new Color(0,0,1);
	}

	public IEnumerator NextScene() {
		// SceneManager.GetActiveScene().name;
		string scene = "";
		// yield return new WaitForSeconds(1);
		if (SceneManager.GetActiveScene().name == "space invaders" && LevelManagerScript.passe2 == false) {
			scene = "loading1";
		} else if (SceneManager.GetActiveScene().name == "marito" && LevelManagerScript.passe2 == false) {
			scene = "loading2";
		} else if (SceneManager.GetActiveScene().name == "Tetris") {
			LevelManagerScript.passe2 = true;
			scene = "space invaders";
		} else if (SceneManager.GetActiveScene().name == "space invaders") {
			scene = "marito";
		} else if (SceneManager.GetActiveScene().name == "marito") {
			scene = "youwin";
		}
		
		AsyncOperation asyncLoad = SceneManager.LoadSceneAsync(scene);
		while (!asyncLoad.isDone)
        {
            yield return null;
        }
	}
}
