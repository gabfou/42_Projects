using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(ScalingPlatform))]
public class ScalingPlatformEditor : Editor
{
	ScalingPlatform	sp;

	void OnEnable()
	{
		sp = target as ScalingPlatform;
	}

	public void OnSceneGUI()
	{

	}
}
