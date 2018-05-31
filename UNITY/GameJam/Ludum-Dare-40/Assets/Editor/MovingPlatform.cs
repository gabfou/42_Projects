using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.Linq;

[CustomEditor(typeof(MovingPlatform))]
public class MovingPlatformEditor : Editor {

	MovingPlatform	r;

	void OnEnable()
	{
		r = target as MovingPlatform;
	}

	public override void OnInspectorGUI()
	{
		base.DrawDefaultInspector();
	}

	public void OnSceneGUI()
	{
		if (r.list.Count == 0)
			r.list.Add(Vector2.zero);

		Handles.color = Color.green;
		for (int i = 0; i < r.list.Count; i++)
		{
			r.list[i] = Handles.PositionHandle(r.list[i], Quaternion.identity);
			Handles.Label(r.list[i], i.ToString(), EditorStyles.whiteLabel);
			// r.list[i] = Handles.FreeMoveHandle(r.list[i], Quaternion.identity, .1f, Vector3.zero, Handles.DotHandleCap);
		}

		if (Event.current.type == EventType.KeyUp && Event.current.keyCode == KeyCode.N)
		{
			r.list.Add(r.list.Last());
			Event.current.Use();
		}
		
		if (!EditorApplication.isPlaying)
			r.gameObject.transform.position = r.list[0];
		
		Vector3[] arr = new Vector3[r.list.Count];		
		for (int i = 0; i < r.list.Count; i++)
			arr[i] = r.list[i];
		Handles.color = Color.white;
		Handles.DrawAAPolyLine(arr);
	}
}
