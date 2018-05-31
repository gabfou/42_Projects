using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEditor.IMGUI.Controls;

[CustomEditor(typeof(RotatingPlatform))]
public class RotatingPlatformEditor : Editor
{
	RotatingPlatform	rp;
	ArcHandle			arc;

	void OnEnable()
	{
		arc = new ArcHandle();
		arc.radius = 10;
		rp = target as RotatingPlatform;
	}
	
	public void OnSceneGUI()
	{
		switch (rp.mode)
		{
			case RotationMode.Free:
				break;
			case RotationMode.Loop:
			case RotationMode.PingPong:

				using (new Handles.DrawingScope(Matrix4x4.TRS(rp.transform.position, Quaternion.Euler(-90, 0, 0), Vector3.one)))
				{
					arc.angle = rp.minRotation;
					arc.DrawHandle();
					rp.minRotation = arc.angle;
	
					arc.angle = rp.maxRotation;
					arc.DrawHandle();
					rp.maxRotation = arc.angle;
				}

				break;
		}
	}
}
