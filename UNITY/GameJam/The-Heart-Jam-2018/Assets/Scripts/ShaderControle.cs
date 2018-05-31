﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Rendering.PostProcessing;

public class ShaderControle : MonoBehaviour {

	// Use this for initialization
	float				depth;
	public Transform	container;
	public Transform	player;
	public float		oxygen;
	public float		speedoxygen = 1;
	public float		speedoxygenback = 1;
	PostProcessVolume	volume;
	PreDeathEffect		predeatheffect;
	Vignette			vignette;
	public float		distortionIntensity;
	WaterSurface		watersurface;
	PostProcessingManager	ppm;

	void OnEnable () {
		volume = GetComponent<PostProcessVolume>();
		watersurface = FindObjectOfType<WaterSurface>();
		ppm = FindObjectOfType<PostProcessingManager>();

		bool foundEffectSettings = volume.profile.TryGetSettings<PreDeathEffect>(out predeatheffect);
		if(!foundEffectSettings)
		{
			enabled = false;
			Debug.Log("Cant load PreDeathEffect settings");
			return;
		}
	}
	
	// Update is called once per frame
	void Update () {
		oxygenchange();
		depthchange();
		oxygen +=  Time.deltaTime * ((watersurface.playerisin) ? speedoxygen : -speedoxygenback);
		oxygen = (oxygen < 0) ? 0 : oxygen;
		depth = -(container.position.y);
		Vector3 tmp = Camera.main.WorldToScreenPoint(player.position);
		tmp.x /= Camera.main.pixelWidth;
		tmp.y /= Camera.main.pixelHeight;
		predeatheffect.CenterPoint.value = tmp;
		if (depth > ppm.maxDepth)
			SceneManager.LoadScene("end");
		// Debug.Log(depth);
		// cheapDistorsion();
	}

    void oxygenchange ()
	{
		if(volume.profile == null)
		{
			enabled = false;
			Debug.Log("Cant load PostProcess volume");
			return;
		}
		predeatheffect.Strenght.Override((oxygen > 20) ? (oxygen - 20) / 200 : 0);
		// predeatheffect.greytougoum.Override((oxygen > 50) ? (oxygen > 75) ? 0.4f : 0.2f : 0);
		predeatheffect.greystrenght.Override((oxygen > 30) ? (oxygen - 30) / 40 : 0);
		if (oxygen > 150)
		{
			GameManager.instance.Lose();
			Debug.Log("DEADED");
		}

    }

	void depthchange()
	{
		bool foundEffectSettings = volume.profile.TryGetSettings<PreDeathEffect>(out predeatheffect);
		if(!foundEffectSettings)
		{
			enabled = false;
			Debug.Log("Cant load PreDeathEffect settings");
			return;
		}
		predeatheffect.noircissement.Override(depth / (ppm.maxDepth * 1.2f));
	}

	void cheapDistorsion()
	{
		LensDistortion ld;
		bool foundEffectSettings = volume.profile.TryGetSettings<LensDistortion>(out ld);
		if (!foundEffectSettings)
		{
			enabled = false;
			Debug.Log("Cant load LensDistortion settings");
			return;
		}
		ld.centerX.Override(Mathf.Sin(Time.timeSinceLevelLoad * 100 * Input.GetAxis("Horizontal")));
		ld.centerY.Override(Mathf.Sin(Time.timeSinceLevelLoad * 100 * Input.GetAxis("Horizontal")));
	}
}
